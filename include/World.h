#pragma once

// #include "start_menu.h"
#include "Presenter.h"
#include "InputManager.h"
#include "Game.h"
#include "StartMenu.h"

class World
{
public:
	World();
	~World();

	Presenter m_presenter;
	InputManager m_inputManager;


	void init();
	void run();
	void destroy();

	Game m_game;
	Menu menu;

	bool isRunning();
	void quit();

	int game_state = 0;
private:
	bool m_isRunning;
};