// Planets Lab
// Sam McDowell

#include <iostream>
#include <string>

using namespace std;

enum planet { Mercury, Venus, Earth, Moon, Mars, Jupiter, Saturn, Uranus, Neptune, Pluto };

bool validPlanet(string, planet&);
float calculateWeight(float, int planetNumber);

int main() {
	cout << "Weight Calculator:\n";
	string planetNameEntered = "";
	planet planetNumber;
	int weightOnEarth;
	float weightOnAnotherPlanet = 0.0;

	do {
		cout << "Enter a planet:\n";
		cout << "Valid planets are: Mercury, Venus, Earth, Moon, Mars, Jupiter, Saturn, Uranus, Neptune, Pluto\n";
		cin >> planetNameEntered;
	} while (!validPlanet(planetNameEntered, planetNumber));

	cout << "Enter weight on Earth in pounds:\t";
	cin >> weightOnEarth;
	weightOnAnotherPlanet = calculateWeight(weightOnEarth, planetNumber);

	cout << "Weight on " << planetNameEntered << ": " << weightOnAnotherPlanet << endl << endl;

	system("pause");
}

bool validPlanet(string planetNameEntered, planet& planetNumber) {
	if (planetNameEntered == "Mercury") {
		planetNumber = Mercury;
		return true;
	}
	if (planetNameEntered == "Venus") {
		planetNumber = Venus;
		return true;
	}
	if (planetNameEntered == "Earth") {
		planetNumber = Earth;
		return true;
	}
	if (planetNameEntered == "Moon") {
		planetNumber = Moon;
		return true;
	}
	if (planetNameEntered == "Mars") {
		planetNumber = Mars;
		return true;
	}
	if (planetNameEntered == "Jupiter") {
		planetNumber = Jupiter;
		return true;
	}
	if (planetNameEntered == "Saturn") {
		planetNumber = Saturn;
		return true;
	}
	if (planetNameEntered == "Uranus") {
		planetNumber = Uranus;
		return true;
	}
	if (planetNameEntered == "Neptune") {
		planetNumber = Neptune;
		return true;
	}
	if (planetNameEntered == "Pluto") {
		planetNumber = Pluto;
		return true;
	}
	system("cls");
	cout << "You have entered an invalid planet name. Try again.\n";
	return false;
}

float calculateWeight(float weightOnEarth, int planetNumber) {
	switch (planetNumber) {
	case 0:
		return weightOnEarth * 0.4155;
		break;
	case 1:
		return weightOnEarth * 0.8975;
		break;
	case 2:
		return weightOnEarth * 1.0;
		break;
	case 3:
		return weightOnEarth * 0.166;
		break;
	case 4:
		return weightOnEarth * 0.3507;
		break;
	case 5:
		return weightOnEarth * 2.5374;
		break;
	case 6:
		return weightOnEarth * 1.0677;
		break;
	case 7:
		return weightOnEarth * 0.8947;
		break;
	case 8:
		return weightOnEarth * 1.1794;
		break;
	case 9:
		return weightOnEarth * 0.0899;
		break;
	}
}