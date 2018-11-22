#pragma once
#include <string>
#include <sstream>
#include <vector>
#include <math.h>
using namespace std; 



class city
{
private:
	vector<double> cordinates;
	string name;
	string country;
	double distance;
	int compare_to(city &other );
public:
	city();
	~city();
	//setter
	void setCity(string location);
	//getters
	string getName();
	string getCountry();
	vector<double> getCordinates();
	double getdistance();
	//distance
	void distancecalc(city& other);

	//compare operators
	bool operator< (city &rh);
	bool operator> (city &rh);
	bool operator<= (city &rh);
	bool operator>= (city &rh);
	bool operator== (city &rh);
	bool operator!= (city &rh);


	//output operator overload
	friend ostream& operator<< (ostream& out, city &City);
		
};

