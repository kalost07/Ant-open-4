#pragma once

#include "Engine.h"
#include "Pul.h"

class Board {
public:
	Board();
	~Board();

	void init();
	void update();
	void draw();
	void exit();

	Pul pulove[6][7];

	SDL_Rect m_rect;
	SDL_Texture* txt;
};