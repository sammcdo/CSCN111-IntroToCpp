// Sam McDowell
// Lab 4: Hotels

// Imports
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

// Constants
const string FILE_NAME = "input.txt";
const float BLOCK_DISCOUNT = 0.1f;
const float STAY_DISCOUNT = 0.05f;

// Variables
int numberOfRooms;
int daysToStay;

float roomRate;
float salesTaxRate;

float discount;


/**
* Get the inputs from the user
**/
void getKeyboardInputs() {
    cout << "Enter the number of rooms: ";
    cin >> numberOfRooms;

    cout << "Enter the number of days to stay: ";
    cin >> daysToStay;
}

/**
* Get inputs from our input file
**/
void getFileInputs() {
    ifstream inputs(FILE_NAME);
    string line;

    getline(inputs, line);
    roomRate = stof(line);

    getline(inputs, line);
    salesTaxRate = stof(line);
}

/**
* Calculate the discount on the reservation
**/
void calculateDiscount() {
    discount = 0;

    if (daysToStay >= 3) discount += STAY_DISCOUNT;

    if (numberOfRooms >= 10) discount += BLOCK_DISCOUNT;
    if (numberOfRooms >= 20) discount += BLOCK_DISCOUNT;
    if (numberOfRooms >= 30) discount += BLOCK_DISCOUNT;
}

/**
* Show an invoice to the user
**/
void printInvoice() {
    ofstream output("output.txt");
    output << fixed << setprecision(2);
    output << right << setw(30) << "Cost of renting one room:" << right << setw(10) << roomRate << endl;
    output << right << setw(30) << "Discount Rate per room:" << right << setw(10) << discount << endl;
    output << right << setw(30) << "Number of rooms booked:" << right << setw(10) << numberOfRooms << endl;
    output << right << setw(30) << "Number of days booked:" << right << setw(10) << daysToStay << endl;
    output << right << setw(30) << "Total cost of the rooms:" << right << setw(10) << (roomRate * numberOfRooms * daysToStay) * (1 - discount) << endl;
    output << right << setw(30) << "Sales Tax:" << right << setw(10) << (roomRate * numberOfRooms * daysToStay) * (1 - discount) * salesTaxRate << endl;
    output << right << setw(30) << "Total billing amount:" << right << setw(10) << (roomRate * numberOfRooms * daysToStay) * (1 - discount) * (1 + salesTaxRate) << endl;
    output.close();
}

/**
* Main program
**/
int main()
{
    system("cls");

    getKeyboardInputs();

    getFileInputs();

    calculateDiscount();

    printInvoice();

    system("pause");

    return 0;
}
