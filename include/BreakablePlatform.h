#pragma once

#include "Platform.h"
#include "Presenter.h"

class BreakablePlatform : Platform {
public:
	BreakablePlatform();
	~BreakablePlatform();
	
	bool active = true;
	static SDL_Texture* txt;

	void breakPlatform();
	void init(int2);

	SDL_Texture* getTxt() {
		return txt;
	}
};

