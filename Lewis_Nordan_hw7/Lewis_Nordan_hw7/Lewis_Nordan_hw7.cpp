// Lewis_Nordan_hw7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "city.h"
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;
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
int selectCity(vector<city> names) {
	int chosen = 0;
	//needs to be built
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
	if (num == 0 || num > results.size()) {
		cout << num << "is an invalid value. try again." << endl;
		return;
	}
	else {
		for (int x = 0; x < num; x++) {
			if (num > 0) {
				cout << results[x] << endl;
			}
			else {
				cout << results[(results.size()) - x];
			}
		}
	}

}


int main()
{
	vector<city> places;
	places = getcities("worldcities.csv");
	selectCity(places);
	print(places, 5);
	


	system("pause");
	return 0;
}

