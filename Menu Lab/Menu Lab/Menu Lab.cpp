// Lab 8: Waffle House Menu
// Sam McDowell

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <math.h>

using namespace std;

bool keep_going = true;
double running_total = 0;

struct MenuItemType {
	double menuPrice = 0.0;
	string menuItemDescription = "";
	bool isOrdered = false;
};

MenuItemType menuList[8];

void get_data();
void show_menu();
void print_check();

int main() {
	get_data();

	while (keep_going) {
		show_menu();
	}

	print_check();
}

void get_data() {
	ifstream waffle("menu.txt");
	string holdit;
	for (int item = 0; item <= 7; item++) {
		getline(waffle, holdit);
		menuList[item].menuItemDescription = holdit;
		getline(waffle, holdit);
		menuList[item].menuPrice = stof(holdit);
		menuList[item].isOrdered = false;
	}
}

void show_menu() {
	int choice;
	system("cls");
	
	cout << "-----------------------------------------------------\n";
	cout << "------------------- Waffle House --------------------\n";
	
	for (int i = 0; i <= 7; i++) {
		cout << left << setw(5) << i + 1
			<< setw(30) << left << menuList[i].menuItemDescription
			<< setw(10) << right << menuList[i].menuPrice << endl;
	}

	cout << "Enter an item number (1-8):\n";
	cout << "Enter any other number to quit: ";
	cin >> choice;

	if (choice > 8 || choice < 1) {
		keep_going = false;
	}
	else {
		menuList[choice - 1].isOrdered = true;
	}
}

void print_check() {
	system("cls");

	cout << "-----------------------------------------------------\n";
	cout << "------------------- Waffle House --------------------\n";
	cout << "-------------------  Guest Check --------------------\n";

	for (int i = 0; i <= 7; i++) {
		if (menuList[i].isOrdered) {
			cout << left << setw(5) << i + 1
				<< setw(30) << left << menuList[i].menuItemDescription
				<< setw(10) << right << menuList[i].menuPrice << endl;

			running_total = running_total + menuList[i].menuPrice;
		}
	}

	float tax = ceil(running_total * 0.05 * 100) / 100;

	cout << endl;
	cout << left << " " << setw(34) << right << "TAX:"
		<< setw(10) << right << tax << setprecision(2) << fixed << endl;
	cout << left << " " << setw(34) << right << "Total:"
		<< setw(10) << right << tax + running_total << setprecision(2) << fixed << endl;

	system("pause");
}