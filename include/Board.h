#pragma once

#include "Engine.h"
#include "Platform.h"
#include "BreakablePlatform.h"
#include "MovingPlatform.h"
#include "Character.h"
#include <list>
#include "progressBar.h"

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
	int goalDist;
	int dist;
	int maxDist;
	int platDist;

	int pickPlat();

	std::list<unique_ptr<Platform>> platforms;
	void spawnPlatforms(int, int);
	Character tiger;
	ProgressBar pb;

	static SDL_Rect m_rect;
	SDL_Texture* txt;
	SDL_Rect txt_pos;
	const int TXT_HEIGHT = 96;

	const int PLATFORM_DESPAWN = 1500;
	static const double GRAV; // pixel/frame^2
	static bool controlEnabled;
	int endState;
};

