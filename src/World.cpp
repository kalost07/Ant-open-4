#include "World.h"
#include <iostream>

World::World()
{
	m_isRunning = true;
}

World::~World()
{
}

void World::init()
{
	m_presenter.init();
	menu.init_all_start();
	
	game_state = 0;
}

void World::run()
{

	m_inputManager.handleInput();
	if (game_state == 0) {
		if (m_inputManager.m_mouseOnRelease) {
			if (MouseIsInRect(m_inputManager.m_mouseCoor, menu.m_quit_rect)) {
				quit();
			}
			
			if (MouseIsInRect(m_inputManager.m_mouseCoor, menu.m_play_rect)) {
				game_state = 1;
				m_inputManager.handleInput();
				m_game.init(0);
			}
			if (MouseIsInRect(m_inputManager.m_mouseCoor, menu.m_playBotE_rect)) {
				game_state = 1;
				m_inputManager.handleInput();
				m_game.init(1);
			}
			if (MouseIsInRect(m_inputManager.m_mouseCoor, menu.m_playBotH_rect)) {
				game_state = 1;
				m_inputManager.handleInput();
				m_game.init(2);
			}
		}
	}
	if (game_state == 1) {
		m_game.update();
		if (game_state == 2) menu.init_win_scr(m_game.m_board.endState);
	}
	if (game_state == 2) {
		if (m_inputManager.m_mouseOnRelease) {
			if (MouseIsInRect(m_inputManager.m_mouseCoor, menu.m_quit_rect)) {
				quit();
			}

			if (MouseIsInRect(m_inputManager.m_mouseCoor, menu.m_play_rect)) {
				game_state = 1;
				m_inputManager.handleInput();
				m_game.exit();
				m_game.init(0);
			}
			if (MouseIsInRect(m_inputManager.m_mouseCoor, menu.m_playBotE_rect)) {
				game_state = 1;
				m_inputManager.handleInput();
				m_game.exit();
				m_game.init(1);
			}
			if (MouseIsInRect(m_inputManager.m_mouseCoor, menu.m_playBotH_rect)) {
				game_state = 1;
				m_inputManager.handleInput();
				m_game.exit();
				m_game.init(2);
			}
		}
	}
	m_presenter.draw();
}

// call destroy for all classes to prevent memory leak
void World::destroy()
{
	SDL_DestroyRenderer(m_presenter.m_main_renderer);
	
	SDL_DestroyWindow(m_presenter.m_main_window);
}

bool World::isRunning()
{
	return m_isRunning;
}

void World::quit()
{
	m_isRunning = false;
	m_game.exit();
	destroy();
}
