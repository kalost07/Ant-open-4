#pragma once

#include "Platform.h"
#include "Presenter.h"

static SDL_Texture* model = loadTexture("MovingPlatform.bmp");

class MovingPlatform : Platform {
public:
	MovingPlatform();
	~MovingPlatform();

	int speed = 0;
	SDL_Texture* txt;

};