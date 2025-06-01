#pragma once
#include "defines.h"

class Platform {
public:
	Platform();
	~Platform();

	SDL_Rect pos;
	static SDL_Texture* txt;

	virtual void init(int2);
	void baseUpdate();
	virtual void update();
	virtual void draw();
	virtual void exit();

	virtual SDL_Texture* getTxt() {
		return txt;
	}

};

