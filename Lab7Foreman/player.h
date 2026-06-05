#ifndef PLAYERH
#define PLAYERH
#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include "BadGuy.h"

class player
{
public:
	player(int HEIGHT);
	~player();
	void DrawPlayer(bool left, bool up, bool down);
	void MoveUp(BadGuy badguys[], int guysize);
	void MoveDown(int HEIGHT, BadGuy badguys[], int guysize);
	void MoveLeft(BadGuy badguys[], int guysize);
	void MoveRight(int WIDTH, BadGuy badguys[], int guysize);
	int getBoundX() { return boundx; }
	int getBoundY() { return boundy; }
	int getX() { return x; }
	int getY() { return y; }
private:
	int x;
	int y;
	int speed;
	int boundx;
	int boundy;
	ALLEGRO_BITMAP* image;
};
#endif
