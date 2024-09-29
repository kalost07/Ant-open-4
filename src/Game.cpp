#include "Game.h"

Game::Game()
{
}

Game::~Game()
{
}

void Game::init()
{
	m_board.init();
}

void Game::update()
{
	m_board.update();
}

void Game::draw()
{
	m_board.draw();
}

void Game::exit()
{
	m_board.exit();
}
