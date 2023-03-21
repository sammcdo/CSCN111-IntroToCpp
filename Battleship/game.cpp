// Sam McDowell
// Lab 5

#include "game.h"
#include "surface.h"
#include <cstdio> //printf
#include <fstream>
#include <string>

using namespace std;

namespace Tmpl8 {
	static Sprite ocean(new Surface("assets/ocean.tga"), 1);
	static Sprite letters(new Surface("assets/letters.tga"), 1);
	static Sprite numbers(new Surface("assets/numbers.tga"), 1);

	ifstream coordinates("coordinates.txt");

	static Sprite carrierHorizontal(new Surface("assets/carrierHorizontal.tga"), 1);
	static Sprite carrierVertical(new Surface("assets/carrierVertical.tga"), 1);
	int carrierX = 0;
	int carrierY = 0;
	bool isCarrierHorizontal = true;

	static Sprite destroyerHorizontal(new Surface("assets/destroyerHorizontal.tga"), 1);
	static Sprite destroyerVertical(new Surface("assets/destroyerVertical.tga"), 1);
	int destroyerX = 0;
	int destroyerY = 0;
	bool isDestroyerHorizontal = true;

	static Sprite battleshipHorizontal(new Surface("assets/battleshipHorizontal.tga"), 1);
	static Sprite battleshipVertical(new Surface("assets/battleshipVertical.tga"), 1);
	int battleshipX = 0;
	int battleshipY = 0;
	bool isBattleshipHorizontal = true;

	static Sprite subHorizontal(new Surface("assets/subHorizontal.tga"), 1);
	static Sprite subVertical(new Surface("assets/subVertical.tga"), 1);
	int subX = 0;
	int subY = 0;
	bool isSubHorizontal = true;

	static Sprite cruiserHorizontal(new Surface("assets/cruiserHorizontal.tga"), 1);
	static Sprite cruiserVertical(new Surface("assets/cruiserVertical.tga"), 1);
	int cruiserX = 0;
	int cruiserY = 0;
	bool isCruiserHorizontal = true;

	void positionBoat(int& x, int& y, bool& isHorizontal) {
		string line;
		getline(coordinates, line);
		x = stoi(line);
		getline(coordinates, line);
		y = stoi(line);
		getline(coordinates, line);
		if (line == "Y") {
			isHorizontal = true;
		} else {
			isHorizontal = false;
		}
	}

	void Game::drawBoat(int& x, int& y, bool& isHorizontal, Sprite& horizontal, Sprite& vertical) {
		if (isHorizontal) {
			horizontal.SetFrame(0);
			horizontal.Draw(screen, x, y);
		} else {
			vertical.SetFrame(0);
			vertical.Draw(screen, x, y);
		}
	}

	// -----------------------------------------------------------
	// Initialize the application
	// -----------------------------------------------------------
	void Game::Init() {
		positionBoat(carrierX, carrierY, isCarrierHorizontal);
		positionBoat(destroyerX, destroyerY, isDestroyerHorizontal);
		positionBoat(battleshipX, battleshipY, isBattleshipHorizontal);
		positionBoat(subX, subY, isSubHorizontal);
		positionBoat(cruiserX, cruiserY, isCruiserHorizontal);
	}
	
	// -----------------------------------------------------------
	// Close down application
	// -----------------------------------------------------------
	void Game::Shutdown()
	{
	}

	// -----------------------------------------------------------
	// Main application tick function
	// -----------------------------------------------------------
	void Game::Tick(float deltaTime)
	{
		// clear the graphics window
		screen->Clear(0);
		// draw a sprite
		ocean.SetFrame(0);
		ocean.Draw(screen, 0, 0);

		letters.SetFrame(0);
		letters.Draw(screen, 40, 0);

		numbers.SetFrame(0);
		numbers.Draw(screen, 0, 40);

		drawBoat(carrierX, carrierY, isCarrierHorizontal, carrierHorizontal, carrierVertical);

		drawBoat(destroyerX, destroyerY, isDestroyerHorizontal, destroyerHorizontal, destroyerVertical);

		drawBoat(battleshipX, battleshipY, isBattleshipHorizontal, battleshipHorizontal, battleshipVertical);

		drawBoat(subX, subY, isSubHorizontal, subHorizontal, subVertical);

		drawBoat(cruiserX, cruiserY, isCruiserHorizontal, cruiserHorizontal, cruiserVertical);
	}
};