#ifndef city_
#define city_

#pragma once
#include <string>
#include <vector>
namespace Cities {
	using namespace std; 



	class city
	{
	private:
		vector<int> cordinates;
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
		double distance(city other);
		//compare operaters

	};
}
#endif
