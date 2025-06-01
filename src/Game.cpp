#include "Game.h"
#include "Presenter.h"
#include "InputManager.h"
#include "World.h"

Game::Game()
{
}

Game::~Game()
{
}

void Game::init(int bot)
{
	m_board.init();
	turn = 0;
	m_bg = loadTexture("background.bmp");
	botState = bot;
}

void Game::update()
{
	m_board.update();
}

void Game::draw()
{
	Drawable tmp;
	tmp.drect = { 0,0,1920,1080 };
	tmp.texture = m_bg;
	drawObject(tmp);
	m_board.draw();
}

void Game::exit()
{
	m_board.exit();
}
