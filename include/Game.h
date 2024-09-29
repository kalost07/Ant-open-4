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

	bool turn;
};