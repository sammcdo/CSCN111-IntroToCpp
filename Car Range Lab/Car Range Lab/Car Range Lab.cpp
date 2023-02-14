// Sam McDowell
// Car Range Lab.cpp : This program checks the range of a car based on mpg
// CSCN 111

#include <iostream>

using namespace std;

int main()
{
    int tankCapacity;
    int milesPerGallon;
    int range;

    cout << "Sam's Fuel Calculator!!\n\n";


    cout << "Fuel Efficiency (MPG): ";
    cin >> milesPerGallon;
    cout << "You entered: " << milesPerGallon << "\n\n";


    cout << "Tank Capacity (Gal): ";
    cin >> tankCapacity;
    cout << "You entered: " << tankCapacity << endl;


    range = milesPerGallon * tankCapacity;
    
    
    cout << "\n\n";
    cout << "Total Range: ";
    cout << range << " miles!" << endl;

    return 0;
}
