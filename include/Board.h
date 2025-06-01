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

	int placeInput();

	SDL_Rect m_rect;
	SDL_Texture* txt;

	int endState;
};