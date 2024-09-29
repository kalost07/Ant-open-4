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
	bool checkWin(bool);
	bool checkWinCoords(int2, bool);

	int placeInput();
	int2 placePul(int,bool);

	Pul pulove[6][7];

	SDL_Rect m_rect;
	SDL_Texture* txt;

	int botPlace();
	int botPlaceRandom();

	int endState;
	int pulCount;
};