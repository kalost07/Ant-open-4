#pragma once

// #include "start_menu.h"
#include "Presenter.h"
#include "InputManager.h"
#include "Game.h"
#include "StartMenu.h"

enum Game_State {
	Main_Menu,
	In_Game,
	Win_Screen
};

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

	Game_State game_state = Main_Menu;
private:
	bool m_isRunning;
};

