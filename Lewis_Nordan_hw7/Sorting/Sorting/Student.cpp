#include "Student.h"

namespace nwacc {

	Student::Student() : Student(" ", kFirstId) { }
	//	this->set_name(" ");
	//	this->set_id(kFirstId);
	//}

	Student::Student(std::string name, int id) {
		this->set_name(name);
		this->set_id(id);
	}

	void Student::set_name(const std::string &name) {
		this->name = name;
	}

	std::string Student::get_name() const {
		return this->name;
	}

	void Student::set_id(int id) {
		this->id = id;
	}

	int Student::get_id() const {
		return this->id;
	}

	int Student::compare_to(const Student &other) {
		// id numbers. 
		if (this->get_id() < other.get_id()) {
			return -1;
		} else if (this->get_id() > other.get_id()) {
			return 1;
		} else {
			return 0;
		}
	}

	bool Student::operator< (const Student &rhs) {
		// lhs - left hand side
		// rhs - right hand side
		return this->compare_to(rhs) < 0;
	}

	bool Student::operator> (const Student &rhs) {
		return this->compare_to(rhs) > 0;
	}
	
	bool Student::operator<= (const Student &rhs) {
		return this->compare_to(rhs) <= 0;
	}

	bool Student::operator>= (const Student &rhs) {
		return this->compare_to(rhs) >= 0;
	}

	bool Student::operator== (const Student &rhs) {
		return this->compare_to(rhs) == 0;
	}

	bool Student::operator!= (const Student &rhs) {
		return this->compare_to(rhs) != 0;
	}

	std::ostream& operator<<(std::ostream &out, const Student &student) {
		out << student.get_name() << " " << student.get_id();
		return out;
	}
}