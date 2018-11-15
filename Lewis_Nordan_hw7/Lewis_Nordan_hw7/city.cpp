#include "stdafx.h"
#include "city.h"
using namespace Cities;

city::city()
{
	vector<double> cordinates;
	string name;
	string country;
}


city::~city()
{
}

void Cities::city::setCity(string location)
{
	istringstream s(location);
	string temp;
	getline(s, name, ',');
	getline(s, country, ',');
	getline(s, temp, ',');
	cordinates[0] = stod(temp);
	getline(s, temp, ',');
	cordinates[1] = stod(temp);
}

string Cities::city::getName()
{
	return name;
}

string Cities::city::getCountry()
{
	return country;
}

vector<double> Cities::city::getCordinates()
{
	return cordinates;
}

double Cities::city::distance(city& other)
{
	double dLat = this->cordinates[0] - other.getCordinates()[0];
	double Dlong = this->cordinates[1] - other.getCordinates()[1];
	double a = (sin(dLat / 2)) ^ 2 + cos(this->cordinates[0]) * cos(other.getCordinates()[0]) * (sin(Dlong / 2)) ^ 2;
	double c;
	double d;




	return 0.0;
}
