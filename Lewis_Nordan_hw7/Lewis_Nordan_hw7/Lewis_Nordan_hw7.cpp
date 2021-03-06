// Lewis_Nordan_hw7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "city.h"
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;
string caseNeutral(string name) {
	string lower = "";
	for (auto letter : name) {
		lower += tolower(letter);
	}
	return lower;
}
vector<city> getcities(string fileName) {
	vector<city> temp;
	string buffer;
	ifstream infile;
	infile.open(fileName);
	int x = 0;
	getline(infile, buffer);
	while (getline(infile,buffer)) {
		temp.push_back(city());
		temp[x].setCity(buffer);
		x++;
	}


	return temp;
}
bool isNum(string s) {
	bool check = false;
	for (int x = 0; x < s.length(); x++) {
		if (isalpha(s[x])) {
			check = false;
			break;
		}
		else {
			check = true;
		}
	}
	return check;
}
int selectCity(vector<city> names) {
	int chosen = 0;
	string cityName = "";
	for (int x = 0; x < names.size();x++) {
		cout << x << ":" << names[x]<<endl;
		
	}
	do {
		cout << "enter the name of a city from the list. or the coresponding number." << endl;
		cin >> cityName;

		if (isNum(cityName)==true) {
			chosen = stoi(cityName);
			if (chosen >= 0 && chosen <= (names.size() - 1)) {
				break;
			}
			else {
				chosen = -1;
			}
		}
		else {

			cityName = caseNeutral(cityName);
			for (int x = 0; x < names.size(); x++) {
				if (caseNeutral(names[x].getName()) == cityName) {
					chosen = x;
					break;
				}
				else {
					chosen = -1;
				}
			}
		} 
	}while (chosen == -1);
	//logic for if the entered value is invalid

	return chosen;
}
vector<city> calulations(vector<city> cities ,int index) {
	for (int x = 0; x < cities.size();x++) {
		cities[x].distancecalc(cities[index]);
	}
	sort(cities.begin(), cities.end());
	return cities;
}
void print(vector<city> results, int num) {
	if (num == 0 || abs(num) > results.size()) {
		cout << num << "is an invalid value. try again." << endl;
		return;
	}
	else {
		for (int x = 1; x < abs(num)+1; x++) {
			if (num > 0) {
				cout << results[x] << endl;
			}
			else {
				cout << results[(results.size() - 1) - x] << endl;;
			}
		}
	}

}


int main()
{
	vector<city> places;
	int sLocation = 0;
	places = getcities("worldcities.csv");
	sLocation = selectCity(places);
	places = calulations(places, sLocation);
	print(places, 5);
	print(places, -5);



	system("pause");
	return 0;
}

