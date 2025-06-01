#pragma once

#include "Engine.h"

class Board {
public:
	Board();
	~Board();

	void init(int);
	void update();
	void draw();
	void exit();

	int placeInput();

	int hole;

	static SDL_Rect m_rect;
	SDL_Texture* txt;

	int endState;
};