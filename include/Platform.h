#pragma once
#include "defines.h"


class Platform {
public:
	Platform();
	~Platform();

	SDL_Rect pos;

	void init(int2);
	void update();
	void draw();
	void exit();

};