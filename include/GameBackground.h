#pragma once

#include "Engine.h"

class GameBackground {
public:
	GameBackground();
	~GameBackground();

	void init();
	void update();
	void draw();
	void exit();

	const float scrollMult = 0.05;

	const int STARS_WIDTH = 540;
	const int STARS_HEIGTH = 360;
	SDL_Texture* stars_txt;
	SDL_Rect star_pos;

	SDL_Texture* planet_txt;
	int curr_planet;
	const int PLANET_SCREEN_DIST = 3000;
	SDL_Rect planet_txt_pos[6] = {
		{59,202,100,100},
		{196,202,100,100},
		{333,202,100,100},
		{59,352,100,100},
		{196,352,100,100},
		{333,352,100,100},
	};
	int planet_appear[6] = { -100, 30000, 80000, 165000, 292000, 508000 };
	int planet_dist[6] = { 10000, 20000, 30000, 50000, 80000, 130000 };
	int planet_switch[6] = { 10000, 50000, 120000, 220000, 400000, 800000 };

};