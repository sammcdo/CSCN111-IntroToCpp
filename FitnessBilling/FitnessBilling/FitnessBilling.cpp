// McDowell
// Lab 6: Fitness

#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

bool determineToContinue(bool& hasSeniorDiscount, bool& hasPrepurchaseDiscount, bool& hasPersonalTraining, bool& exit) {
    if (exit) return false;
    if (hasSeniorDiscount && hasPrepurchaseDiscount && hasPersonalTraining) return false;
    return true;
}

void printMenu(bool& hasSeniorDiscount, bool& hasPrepurchaseDiscount, bool& hasPersonalTraining) {
    system("cls");

    cout << "**************************** King McD's Fitness ****************************\n";
    cout << "****************************  Membership Menu   ****************************\n\n";

    cout << "Please consider these options:\n";

    cout << "1. Senior Discount";
    if (hasSeniorDiscount) cout << "*";
    
    cout << "\n2. Yearly Billing Discount";
    if (hasPrepurchaseDiscount) cout << "*";

    cout << "\n3. Personal Training";
    if (hasPersonalTraining) cout << "*";

    cout << "\n4. Exit\n";
}

void getChoice(bool& hasSeniorDiscount, bool& hasPrepurchaseDiscount, bool& hasPersonalTraining, bool& exit) {
    int choice = 0;

    cout << "Enter your selection:\t";
    cin >> choice;

    if (choice == 1) hasSeniorDiscount = true;
    if (choice == 2) hasPrepurchaseDiscount = true;
    if (choice == 3) hasPersonalTraining = true;
    if (choice == 4) exit = true;

}

void printInvoice(bool& hasSeniorDiscount, bool& hasPrepurchaseDiscount, bool& hasPersonalTraining) {
    int numMonths = 12;
    int numSessions = 0;

    if (!hasPrepurchaseDiscount || hasPersonalTraining) {
        cout << "\n\n";
        cout << "****************************   Extra Options    ****************************\n\n";
    }

    if (!hasPrepurchaseDiscount) {
        cout << "How many months would you like to purchase?\t";
        cin >> numMonths;
    }

    if (hasPersonalTraining) {
        cout << "How many sessions of personal training would you like to purchase?\t";
        cin >> numSessions;
    }

    cout << "\n\n";
    cout << "****************************      Invoice       ****************************\n\n";

    double membership = 50 * numMonths;
    double training = 50 * numSessions;
    cout << fixed;
    cout << setw(30) << "Membership Before Discounts:" << setw(8) << setprecision(2) << membership << endl;
    cout << setw(30) << "Personal Training:" << setw(8) << training << endl;
    cout << setw(30) << "Total Fees:" << setw(8) << membership + training << endl;
    cout << "\n";

    double discounts = 0;
    if (hasSeniorDiscount) {
        cout << setw(30) << "Senior Discount (30%):" << setw(8) << round(membership * 0.3) << endl;
        discounts = discounts + (membership * 0.3);
    }
    if (hasPrepurchaseDiscount) {
        cout << setw(30) << "Prepay Discount (15%):" << setw(8) << round(membership * 0.15) << endl;
        discounts = discounts + membership * 0.15;
    }
    if (numSessions > 5) {
        cout << setw(30) << "Training Discount (20%):" << setw(8) << round(training * 0.2) << endl;
        discounts = discounts + training * 0.2;
    }


    cout << setw(30) << "Total Discount:" << setw(8) << (discounts) << endl;
    cout << endl;
    cout << setw(30) << "Grand Total:" << setw(8) << (membership + training - discounts) << endl;

    cout << "\n\n";
    cout << "****************************************************************************\n\n";

}

int main() {
    bool shouldContinue = true;
    bool hasSeniorDiscount = false;
    bool hasPrepurchaseDiscount = false;
    bool hasPersonalTraining = false;
    bool exit = false;

    printMenu(hasSeniorDiscount, hasPrepurchaseDiscount, hasPersonalTraining);
    getChoice(hasSeniorDiscount, hasPrepurchaseDiscount, hasPersonalTraining, exit);
    shouldContinue = determineToContinue(hasSeniorDiscount, hasPrepurchaseDiscount, hasPersonalTraining, exit);

    while (shouldContinue) {
        printMenu(hasSeniorDiscount, hasPrepurchaseDiscount, hasPersonalTraining);
        getChoice(hasSeniorDiscount, hasPrepurchaseDiscount, hasPersonalTraining, exit);
        shouldContinue = determineToContinue(hasSeniorDiscount, hasPrepurchaseDiscount, hasPersonalTraining, exit);
    }

    printInvoice(hasSeniorDiscount, hasPrepurchaseDiscount, hasPersonalTraining);

    system("pause");
}