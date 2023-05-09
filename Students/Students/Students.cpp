// Sam McDowell
// Students Lab

#include <iostream>
#include "flame.h"

using namespace std;

void studentType::displayFirstName() {
	cout << firstName;
}

/** 
The main method.

Demonstrates the usage of the studentType class.
*/
int main() {
	studentType libertyStudent;

	libertyStudent.setFirstName("Sparky");
	libertyStudent.lastName = "Falwell";

	libertyStudent.displayFirstName();
	cout << " " << libertyStudent.lastName << endl;

	system("pause");
}
