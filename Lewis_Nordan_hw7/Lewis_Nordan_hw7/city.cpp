#include "stdafx.h"
#include "city.h"
using namespace std;

city::city()
{
	vector<double> cordinates;
	string name;
	string country;
}


city::~city()
{
}

void  city::setCity(string location)
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

string  city::getName()
{
	return name;
}

string  city::getCountry()
{
	return country;
}

vector<double>  city::getCordinates()
{
	return cordinates;
}

double  city::distance(city& other)
{
	const double R = 3959.0;
	double dLat = this->cordinates[0] - other.getCordinates()[0];
	double Dlong = this->cordinates[1] - other.getCordinates()[1];
	double a = ( pow(sin(dLat / 2),2.0) + cos(this->cordinates[0]) * cos(other.getCordinates()[0]) * pow(sin(Dlong / 2),2));
	double c = 2 * a * tan(2 * (sqrt(a), sqrt(1 - a)));
	double d = R * c;

	return d;
}
