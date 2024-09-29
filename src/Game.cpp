#include "Game.h"

Game::Game()
{
}

Game::~Game()
{
}

void Game::init()
{
	srand(time(NULL));
	m_bg.init();
	m_cat.init();
	m_fb.init();
	for (int i = 0; i < 5; i++) {
		m_asteroid[i].init(rand() % 3, 3000 + 600 * i, rand() % 2000 - 500, rand() % 360);
	}
	m_pepper.init(1500,300);
	distance = 0;
	distY = 10000000;
}

void Game::update()
{
	distance += m_cat.vel.x;
	distY += m_cat.vel.y;
	if (distY < 0) distY += 360;
	m_bg.update();
	m_cat.update();
	m_fb.update();
	for (int i = 0; i < 5; i++) {
		if (m_asteroid[i].pos.x <= ASTEROID_DESPAWN) {
			m_asteroid[i].exit();
			m_asteroid[i].init(rand()%3, 3000, rand()%2000-500, rand()%360);	
		}
		m_asteroid[i].update();
	}
	if (m_pepper.pos.x <= ASTEROID_DESPAWN) {
		m_pepper.exit();
		m_pepper.init(3000, rand() % 1500 - 250);
	}
	m_pepper.update();
}

void Game::draw()
{
	m_bg.draw();
	m_cat.draw();
	
	for (int i = 0; i < 5; i++) {
		m_asteroid[i].draw();
	}
	m_pepper.draw();
	m_fb.draw();
}

void Game::exit()
{
	m_bg.exit();
	m_cat.exit();
	m_fb.exit();
	for (int i = 0; i < 5; i++) {
		m_asteroid[i].exit();
	}
	m_pepper.exit();
}
