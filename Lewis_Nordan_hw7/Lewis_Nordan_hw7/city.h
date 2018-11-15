#ifndef city_
#define city_

#pragma once
#include <string>
#include <sstream>
#include <vector>
#include <math.h>
namespace Cities {
	using namespace std; 



	class city
	{
	private:
		vector<double> cordinates;
		string name;
		string country;

	public:
		city();
		~city();
		//setter
		void setCity(string location);
		//getters
		string getName();
		string getCountry();
		vector<double> getCordinates();
		//distance
		double distance(city& other);
		
	};
}
#endif
