// Lewis_Nordan_hw7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "city.h"
#include <fstream>
#include <iostream>
using namespace std;
vector<city> getcities(string fileName) {
	vector<city> temp;
	string buffer;
	ifstream infile;
	infile.open(fileName);
	int x = 0;
	while (getline(infile,buffer)) {
		temp[x].setCity(buffer);
		x++;
	}


	return temp;
}
void adfas() {
	vector<city> places;
	places = getcities("worldcities.csv");

}

int main()
{
	adfas();

	return 0;
}

