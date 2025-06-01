#pragma once

#include "Platform.h"
#include "Presenter.h"

static SDL_Texture* model=loadTexture("BreakablePlatform.bmp");

class BreakablePlatform : Platform {
public:
	BreakablePlatform();
	~BreakablePlatform();
	
	bool active = true;
	SDL_Texture* txt;

	void breakPlatform();
	virtual void init();
};