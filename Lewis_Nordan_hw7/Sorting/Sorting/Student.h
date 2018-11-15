#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>

namespace nwacc {
	class Student {
	private:
		std::string name;
		int id;
		int compare_to(const Student&);
	public:
		static const int kFirstId = 1;
		Student();
		Student(std::string, int);
		std::string get_name() const;
		void set_name(const std::string&);
		int get_id() const;
		void set_id(int);

		bool operator< (const Student&);
		bool operator> (const Student&);
		bool operator<= (const Student&);
		bool operator>= (const Student&);
		bool operator== (const Student&);
		bool operator!= (const Student&);

		friend std::ostream& operator<< (std::ostream&, const Student&);
	};
}

#endif // !STUDENT_H_
