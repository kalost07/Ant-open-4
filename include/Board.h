#pragma once

#include "Engine.h"

class Board {
public:
	Board();
	~Board();

	void init();
	void update();
	void draw();
	void exit();
	

	// Pul pulove

	SDL_Rect m_rect;
	SDL_Texture* txt;
};