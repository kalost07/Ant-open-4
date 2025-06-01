#pragma once
#include "defines.h"


class Platform {
public:
	Platform();
	~Platform();

	SDL_Rect pos;
	SDL_Texture* txt;


	virtual void init(int2);
	virtual void update();
	virtual void draw();
	virtual void exit();

};