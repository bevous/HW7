#include "stdafx.h"
#include "city.h"
using namespace std;

int city::compare_to(city &other)
{
	if (this->getdistance() < other.getdistance()) {
		return -1;
	}
	else if (this->getdistance() > other.getdistance()) {
		return 1;
	}
	else {
		return 0;
	}
}

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
	cordinates.push_back(stod(temp));
	getline(s, temp, ',');
	cordinates.push_back(stod(temp));
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

double city::getdistance()
{
	return distance;
}

void  city::distancecalc(city& other)
{
	const double R = 3959.0;
	double dLat = this->cordinates[0] - other.getCordinates()[0];
	double Dlong = this->cordinates[1] - other.getCordinates()[1];
	double a = ( pow(sin(dLat / 2),2.0) + cos(this->cordinates[0]) * cos(other.getCordinates()[0]) * pow(sin(Dlong / 2),2));
	double c = 2 * a * tan(2 * (sqrt(a), sqrt(1 - a)));
	double d = R * c;

	distance = d;
}

bool city::operator<(city &rh)
{
	return compare_to(rh)<0;
}

bool city::operator>(city &rh)
{
	return compare_to(rh)>0;
}

bool city::operator<=(city &rh)
{
	return compare_to(rh)<=0;
}

bool city::operator>=(city &rh)
{
	return compare_to(rh)>=0;
}

bool city::operator==(city &rh)
{
	return compare_to(rh)==0;
}

bool city::operator!=(city &rh)
{
	return compare_to(rh)!=0;
}

ostream& operator<<(ostream& out, city &City)
{
	out << City.getName() << " " << City.getCountry();
	return out;
}
