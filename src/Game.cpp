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

void Game::init()
{
	m_board.init(1);
	m_bg = loadTexture("background.bmp");
	m_winScreen = loadTexture("exit.bmp");
	m_tram = loadTexture("tram.bmp");
	speedLevel = 1;
	level = 1;
	tram.drect = { 0,1080-128-400,400,400 };
}

void Game::update()
{
	if (m_board.dist > m_board.goalDist) {
		return;
	}
	m_board.update();
	
}

void Game::draw()
{
	Drawable tmp;
	tmp.drect = { 0,0,1920,1080 };
	
	drawObject(tmp);
	
	if (m_board.dist > m_board.goalDist) {
		win_animation();
		return;
	}
	else {
		tmp.texture = m_bg;
		tram.drect.x = -1000;;
		m_board.draw();
	}
}

void Game::win_animation()
{	
	m_board.controlEnabled = false;
	Drawable tmp;
	tmp.drect = { 0,0,1920,1080 };
	tmp.texture = m_winScreen;
	if (tram.drect.x > 1920) {
		m_board.exit();
		level++;
		m_board.init(level);
	}
	drawObject(tmp);
	
	tram.texture = m_tram;
	drawObject(tram);
	tram.drect.x += 15;
	m_board.tiger.draw();

	
}

void Game::exit()
{
	m_board.exit();
}

int Game::getSpeed() {
	return 10. * sqrt(speedLevel);
}