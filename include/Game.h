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
	void win_animation();
	void exit();

	int level;
	int game_state;

	Board m_board;

	SDL_Texture* m_bg;
	SDL_Texture* m_winScreen;
	SDL_Texture* m_tram;
	Drawable tram;



	// Stats
	int speedLevel;

	int getSpeed();
};