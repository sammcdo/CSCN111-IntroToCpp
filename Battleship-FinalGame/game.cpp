// Sam McDowell
// Lab 5

#include "game.h"
#include "surface.h"
#include <cstdio> //printf
#include <windows.h>
#include <fstream>
#include <Windows.h>
#include <mmsystem.h>
#include <iostream>
#include<string>
#pragma comment(lib, "winmm.lib")
#include <conio.h>


using namespace std;

namespace Tmpl8 {
	int map[9][10]{
		0,0,0,0,0,0,0,0,0,0,
		0,4,0,1,2,2,3,0,0,0,
		0,5,0,0,0,0,0,0,0,0,
		0,6,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,
	};

	bool trymap[9][10] = { };

	int cursorX = 0;   // the column number for the cursor
	int cursorY = 0;   // the row number for the cursor
	int guesses = 0;   // the number of guesses made by the human
	int hits = 0;      // the number of hits (e.g. cells with hits)
	CONST int debounce = 75;    //used to control key debounce-adjust if needed
	static int frame = 0;   //only used for extra-credit

	static Sprite board(new Surface("assets/board.tga"), 1);
	static Sprite up(new Surface("assets/up.tga"), 1);
	static Sprite missx(new Surface("assets/miss.tga"), 1);
	static Sprite top(new Surface("assets/top.tga"), 1);
	static Sprite down(new Surface("assets/down.tga"), 1);
	static Sprite left(new Surface("assets/left.tga"), 1);
	static Sprite right(new Surface("assets/right.tga"), 1);
	static Sprite side(new Surface("assets/side.tga"), 1);
	static Sprite guessespeg(new Surface("assets/guessespeg.tga"), 1);
	static Sprite cursor(new Surface("assets/cursorpeg.tga"), 1);

	


	void Game::drawBoard() {
		board.Draw(screen, 0, 0);

		for (int row = 0; row < 9; row++) {
			for (int col = 0; col < 10; col++) {
				if (map[row][col] != 0) {
					if (map[row][col] == 10) {
						missx.Draw(screen, (col * 40) + 80, (row * 40) + 120);
					}
					if (map[row][col] == 11) {
						left.Draw(screen, (col * 40) + 80, (row * 40) + 120);
					}
					if (map[row][col] == 12) {
						side.Draw(screen, (col * 40) + 80, (row * 40) + 120);
					}
					if (map[row][col] == 13) {
						right.Draw(screen, (col * 40) + 80, (row * 40) + 120);
					}
					if (map[row][col] == 14) {
						top.Draw(screen, (col * 40) + 80, (row * 40) + 120);
					}
					if (map[row][col] == 15) {
						up.Draw(screen, (col * 40) + 80, (row * 40) + 120);
					}
					if (map[row][col] == 16) {
						down.Draw(screen, (col * 40) + 80, (row * 40) + 120);
					}
				}
			}
		}

		cursor.Draw(screen, cursorX * 40 + 80, cursorY * 40 + 120);
		guessespeg.Draw(screen, 80 + (guesses / 2 * 40), 480);
	}

	void Game::playClip(int soundNumber) {
		if (soundNumber == 1) mciSendString("open \"explosion.mp3\" type mpegvideo alias clip", NULL, 0, NULL);
		if (soundNumber == 2) mciSendString("open \"kerplunk.mp3\" type mpegvideo alias clip", NULL, 0, NULL);
		if (soundNumber == 3) mciSendString("open \"won.mp3\" type mpegvideo alias clip", NULL, 0, NULL);
		if (soundNumber == 4) mciSendString("open \"wahwahwah.mp3\" type mpegvideo alias clip", NULL, 0, NULL);
		if (soundNumber == 5) mciSendString("open \"beep.mp3\" type mpegvideo alias clip", NULL, 0, NULL);
		mciSendString("play clip", NULL, 0, NULL);
		Sleep(4000 - debounce);
		mciSendString("close clip", NULL, 0, NULL);
	}

	// -----------------------------------------------------------
	// Initialize the application
	// -----------------------------------------------------------
	void Game::Init() {
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
		drawBoard();

		if (hits >= 6) {
			playClip(3);
			exit(0);
		}

		if (guesses >= 20) {
			playClip(4);
			exit(0);
		}

		Sleep(debounce);

		if ((GetAsyncKeyState(87) & 0x8000) && (cursorY > 0)) cursorY -= 1; // W		
		if ((GetAsyncKeyState(65) & 0x8000) && (cursorX > 0)) cursorX -= 1; // A
		if ((GetAsyncKeyState(68) & 0x8000) && (cursorX < 9)) cursorX += 1; // S
		if ((GetAsyncKeyState(83) & 0x8000) && (cursorY < 8)) cursorY += 1; // D

		if (GetAsyncKeyState(88) & 0x8000) {
			guesses++;

			if (trymap[cursorY][cursorX]) {
				playClip(5);
			}
			else {
				trymap[cursorY][cursorX] = true;

				map[cursorY][cursorX] = map[cursorY][cursorX] + 10;

				if (map[cursorY][cursorX] != 0 && map[cursorY][cursorX] != 10) {
					playClip(1);
					hits++;
				}
				else {
					playClip(2);
				}
			}
		}
	}
};