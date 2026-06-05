#include "BadGuy.h"
BadGuy::~BadGuy()
{
	al_destroy_bitmap(image);
}
BadGuy::BadGuy()
{
	image = al_create_bitmap(64, 64);
	if (!image) {
		exit(1);
	}

	al_set_target_bitmap(image);
	al_clear_to_color(al_map_rgb(0, 0, 0));

	x = 0;
	y = 0;

	al_draw_filled_rectangle(25, 10, 39, 54, al_map_rgb(100, 100, 120));
	al_draw_filled_ellipse(32, 32, 32, 16, al_map_rgb(255, 0, 255));
	al_draw_filled_circle(32, 32, 4, al_map_rgb(255, 255, 255));
	al_draw_filled_circle(16, 32, 4, al_map_rgb(120, 255, 255));
	al_draw_filled_circle(48, 32, 4, al_map_rgb(255, 255, 120));
	boundx = al_get_bitmap_width(image) * .75;
	boundy = al_get_bitmap_height(image) * .75;
	live = false;

}
void BadGuy::DrawBadGuy()
{


	if (live)
	{
		al_draw_bitmap(image, x, y, 0);
	}

}
void BadGuy::StartBadGuy(int WIDTH, int HEIGHT, BadGuy badguys[], int guysize)
{
	int tempx = 0;
	int tempy = 0;
	bool makeIt = true;
	bool collide = false;
	if (!live) {
		if (rand() % 500 == 0) {

			//loops until no collisions are detected, then starts bad guy
			while (makeIt) {
				collide = false;
				do {
					tempx = rand() % (WIDTH - boundx);
				} while (tempx < 100);
				do {
					tempy = rand() % (HEIGHT - boundy);
				} while (tempy < 100);

				for (int i = 0; i < guysize; i++) {
					int badx = badguys[i].getX();
					int bady = badguys[i].getY();
					if ((tempx < badx + 64 && tempx + boundx > badx) && (tempy < bady + 64 && bady < tempy + boundy)) {
						collide = true;
						break;
					}
				}
				if (!collide) {
					live = true;
					x = tempx;
					y = tempy;
					makeIt = false;
				}
			}
		}
	}
}