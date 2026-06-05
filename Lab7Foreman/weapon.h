#ifndef WEAPONH
#define WEAPONH
#include "BadGuy.h"
#include "player.h"
class weapon
{
public:
	weapon();
	~weapon();
	void Drawweapon();
	void Fireweapon(player& Player, bool up, bool down, bool left);
	void Updateweapon(int WIDTH, int HEIGHT, int dir);
	void Collideweapon(BadGuy BadGuys[], int cSize);
	int getDir();
private:
	int x;
	int y;
	int boundx;
	int boundy;
	bool live;
	int speed;
	float angle;
	ALLEGRO_BITMAP* image;
	int dir;
};
#endif
