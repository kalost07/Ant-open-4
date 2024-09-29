#pragma once

#include "Engine.h"
#include "Cat.h"
#include "GameBackground.h"
#include "Asteroid.h"
#include "Pepper.h"
#include "FuelBar.h"

class Game {
public:
	Game();
	~Game();

	void init();
	void update();
	void draw();
	void exit();

	GameBackground m_bg;
	FuelBar m_fb;
	Cat m_cat;
	int distance;
	int distY;

	Asteroid m_asteroid[5];
	const int ASTEROID_DESPAWN = -1000;

	Pepper m_pepper;
};