#pragma once

#include "Engine.h"

class Pepper {
public:
	Pepper();
	~Pepper();

	void init(int,int);
	void update();
	void draw();
	void exit();

	SDL_Rect pos;
	SDL_Texture* txt;

	SDL_Rect hitbox;
	SDL_Rect calc_hitbox();

	bool eaten;

	static const int FUEL_RECOVERY = 50;
};