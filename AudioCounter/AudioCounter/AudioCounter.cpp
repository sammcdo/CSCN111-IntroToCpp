// Sam McDowell, Brendan Burford, Christina Metric, Jordan Munster, Emily Bonus
// Lab 6B

#include <iostream>
#include <string>
#include <Windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

using namespace std;

/* Ask the user for numbers until they are valid */
void askForNumbers(int& a, int& b) {
	cout << "Enter the first number:\t\t";
	cin >> a;
	cout << "Enter the second number:\t";
	cin >> b;

	while ((a >= b) || (max(a,b) >= 10001)) {
		cout << "You failed, bad numbers. Try again\n";

		cout << "Enter the first number:\t\t";
		cin >> a;
		cout << "Enter the second number:\t";
		cin >> b;
	}

}

int main()
{
	int a = 0;
	int b = -1;

	askForNumbers(a, b);

	// Count up from the starting number to the final number and say them
	for (int i = a; i <= b; i++)
	{

		int thousands = i / 1000;

		int hundreds = (i % 1000) / 100;

		int tens = (i % 100) / 10;

		int ones = i % 10;

		int lastdigits = (tens * 10) + ones;

		wstring name;
		wstring extension;

		if (thousands > 0) {
			name = to_wstring(thousands);
			extension = L"000";
			name = name + extension;
			
			PlaySound((name + L".wav").c_str(), NULL, SND_FILENAME | SND_SYNC);
		}

		if (hundreds > 0) {
			name = to_wstring(hundreds);
			extension = L"00";
			name = name + extension;
			
			PlaySound((name + L".wav").c_str(), NULL, SND_FILENAME | SND_SYNC);
		}

		if ((tens || hundreds || thousands) && lastdigits == 0) continue;
		name = to_wstring(lastdigits);
		extension = L"";
		name = name + extension;

		PlaySound((name + L".wav").c_str(), NULL, SND_FILENAME | SND_SYNC);

	}

	system("pause");
}