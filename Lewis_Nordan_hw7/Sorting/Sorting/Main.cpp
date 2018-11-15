#include <iostream>

#include "Student.h"

const int kMaxStudents = 5;

int BinarySearch(nwacc::Student list[], int size, nwacc::Student key) {
	auto begin = 0;
	auto end = size - 1;
	auto mid = (begin + end) / 2;

	while (begin <= end) {
		if (list[mid] < key) {
			begin = mid + 1;
		} else if (list[mid] > key) {
			end = mid - 1;
		} else {
			return mid;
		}
		mid = (begin + end) / 2;
	}
	return -1; // not found. 
}

int LinearSearch(nwacc::Student list[], int size, nwacc::Student key) {
	for (auto index = 0; index < size; index++) {
		if (list[index] == key) {
			return index;
		} // else, not the student for which we are looking, doNothing();
	}
	return -1; // not found. 
}

void SelectionSort(nwacc::Student list[], int size) {
	for (int index = 0; index < (size - 1); index++) {
		int minIndex = index;
		nwacc::Student minValue = list[index];

		for (int innerIndex = (index + 1); innerIndex < size; innerIndex++) {
			if (list[innerIndex] < minValue) {
				minIndex = innerIndex;
				minValue = list[innerIndex];
			} // else, not a smaller value doNothing();
		}
		list[minIndex] = list[index];
		list[index] = minValue;
	}
}

int main() {
	nwacc::Student students[kMaxStudents];
	//double list[6]{ 0.0 };

	students[0] = nwacc::Student("Shane", 1);
	nwacc::Student student("Daniel", 2);
	students[1] = student;
	students[2] = nwacc::Student("Lela", 6);
	students[3] = nwacc::Student("Tamara", 5);
	students[4] = nwacc::Student("Janet", 12);
	
	SelectionSort(students, 5);
	std::cout << BinarySearch(students, 5, student) << std::endl;
	std::cout << BinarySearch(students, 5, nwacc::Student("Bob", 4))
		<< std::endl;

	//SelectionSort(students, 5);
	//for (auto kid : students) {
	//	std::cout << kid << std::endl;
	//}

	return 0;
}