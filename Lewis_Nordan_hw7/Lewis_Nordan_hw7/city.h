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
	double distance=0;
	int compare_to(const city&);
public:
	city();
	~city();
	//setter
	void setCity(string location);
	//getters
	string getName() const;
	string getCountry() const;
	vector<double> getCordinates() const;
	double getdistance() const;
	//distance
	void distancecalc(city& other);

	//compare operators
	bool operator< (const city&);
	bool operator> (const city&);
	bool operator<= (const city&);
	bool operator>= (const city&);
	bool operator== (const city&);
	bool operator!= (const city&);


	//output operator overload
	friend ostream& operator<< (ostream& out, city &City);
		
};

