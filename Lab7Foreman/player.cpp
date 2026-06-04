#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_image.h>
#include "player.h"
#include "BadGuy.h"

player::~player()
{
	al_destroy_bitmap(image);
}
player::player(int HEIGHT)
{

	image = al_create_bitmap(64, 64);
	if (!image) {
		exit(1);
	}

	al_set_target_bitmap(image);
	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_draw_filled_rectangle(0, 25, 64, 39, al_map_rgb(75, 75, 75));
	al_draw_filled_rectangle(25, 0, 39, 64, al_map_rgb(50, 50, 50));
	al_draw_circle(32, 32, 8, al_map_rgb(0, 0, 0), 5);

	al_draw_line(0, 32, 64, 32, al_map_rgb(255, 100, 255), 2);
	al_draw_line(32, 0, 32, 64, al_map_rgb(255, 100, 255), 2);
	al_draw_circle(32, 32, 16, al_map_rgb(200, 200, 200), 5);



	x = 20;
	y = HEIGHT / 2;

	speed = 7;
	boundx = al_get_bitmap_width(image);
	boundy = al_get_bitmap_height(image);

}
void player::DrawPlayer()
{
	al_draw_bitmap(image, x, y, 0);
}
void player::MoveUp(BadGuy badguys[], int guysize)
{
	int temp = y;
	y -= speed;
	if (y < 0)
		y = 0;
	for (int i = 0; i < guysize; i++) {
		int cx = badguys[i].getX();
		int cy = badguys[i].getY();
		if ((x < cx + 64 && cx < x + boundx) && (y < cy + 64 && cy < y + boundy)) {
			y = temp;
		}
	}
}
void player::MoveDown(int HEIGHT, BadGuy badguys[], int guysize)
{
	int temp = y;
	y += speed;
	if (y > HEIGHT - boundy)
		y = HEIGHT - boundy;
	for (int i = 0; i < guysize; i++) {
		int cx = badguys[i].getX();
		int cy = badguys[i].getY();
		if ((x < cx + 64 && cx < x + boundx) && (y < cy + 64 && cy < y + boundy)){
			y = temp;
		}
	}
}
void player::MoveLeft(BadGuy badguys[], int guysize)
{
	int temp = x;
	x -= speed;
	if (x < 0)
		x = 0;
	for (int i = 0; i < guysize; i++) {
		int cx = badguys[i].getX();
		int cy = badguys[i].getY();
		if ((y < cy + 64 && cy < y + boundy) && (x < cx + 64 && cx < x + boundx)) {
			x = temp;
		}
	}
}
void player::MoveRight(int WIDTH, BadGuy badguys[], int guysize)
{
	int temp = x;
	x += speed;
	if (x > WIDTH - boundx)
		x = WIDTH - boundx;
	for (int i = 0; i < guysize; i++) {
		int cx = badguys[i].getX();
		int cy = badguys[i].getY();
		if ((y < cy + 64 && cy < y + boundy) && (x < cx + 64 && cx < x + boundx)) {
			x = temp;
		}
	}
}