#pragma once

#include "Engine.h"
#include "Board.h"

class Game {
public:
	Game();
	~Game();

	void init();
	void update();
	void draw();
	void exit();

	Board m_board;

	SDL_Texture* m_bg;

	bool turn;
};