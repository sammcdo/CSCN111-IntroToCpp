#pragma once

namespace Tmpl8 {

class Surface;
class Sprite;
class Game
{
public:
	void SetTarget( Surface* surface ) { screen = surface; }
	void Init();
	void Shutdown();
	void Tick( float deltaTime );
	void MouseUp( int button ) { /* implement if you want to detect mouse button presses */ }
	void MouseDown( int button ) { /* implement if you want to detect mouse button presses */ }
	void MouseMove( int x, int y ) { /* implement if you want to detect mouse movement */ }
	void KeyUp( int key ) { /* implement if you want to handle keys */ }
	void KeyDown( int key ) { /* implement if you want to handle keys */ }
	void drawBoat(int& x, int& y, bool& isHorizontal, Sprite& horizontal, Sprite& vertical); /* Draw a boat on the screen */
private:
	Surface* screen;
};

}; // namespace Tmpl8