#pragma once

#include "Engine.h"
#include "Platform.h"
#include "NormalPlatform.h"
#include "BreakablePlatform.h"
#include "MovingPlatform.h"
#include "Character.h"
#include <list>

class Board {
public:
	Board();
	~Board();

	void init(int);
	void update();
	void draw();
	void exit();

	int placeInput();

	int hole;
	int maxDist;
	int dist;

	std::list<Platform*> platforms;
	Character tiger;

	static SDL_Rect m_rect;
	SDL_Texture* txt;

	static bool controlEnabled;
	int endState;
};

