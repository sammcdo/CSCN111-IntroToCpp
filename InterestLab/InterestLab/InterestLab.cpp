// Sam McDowell
// CSCN 111
// Interest Lab


#include <iostream>
#include <fstream>
#include <string>

using namespace std;


float getInterest() {
    ifstream inputs("filename.txt");
    string line;
    getline(inputs, line);
    float annualInterestRate = stof(line);
    getline(inputs, line);
    float balance = stof(line);
    getline(inputs, line);
    int daysInBillingCycle = stoi(line);
    getline(inputs, line);
    int daysPrepay = stoi(line);
    getline(inputs, line);
    float paymentAmount = stof(line);
    float averageDailyBalance = (balance * daysInBillingCycle - paymentAmount * daysPrepay) / daysInBillingCycle;
    float interest = averageDailyBalance * (annualInterestRate / 12);
    return ceil(interest * 100) / 100;
}

int main() {
    float interest;

    cout << "Credit Card Calculator!\n\n\n";
    cout << "---------------------------------\n";
    cout << " The accrued interest is: $";

    interest = getInterest();

    cout << interest << "\n";

    cout << "---------------------------------\n";

    return 0;
}
