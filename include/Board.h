#pragma once

#include "Engine.h"
#include "Platform.h"
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

	std::list<unique_ptr<Platform>> platforms;
	Character tiger;

	static SDL_Rect m_rect;
	SDL_Texture* txt;

	const int PLATFORM_DESPAWN = 1500;
	static const double GRAV; // pixel/frame^2
	static bool controlEnabled;
	int endState;
};

