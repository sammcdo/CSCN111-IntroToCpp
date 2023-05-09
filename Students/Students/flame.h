#pragma once

#include <iostream>

using namespace std;

/* An class representing a college student */
class studentType {
private:
	string firstName = "";
public:
	string lastName = "";

	/* Output the first name of the student to the console */
	void displayFirstName();

	/* Returns the first name of the student */
	string getFirstName() {
		return firstName;
	}

	/* Update the first name of student */
	void setFirstName(string first) {
		firstName = first;
	}
};
