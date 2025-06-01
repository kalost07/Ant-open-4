#pragma once

#include "Platform.h"
#include "Presenter.h"

class BreakablePlatform : public Platform {
public:
	BreakablePlatform();
	~BreakablePlatform();
	
	bool active = true;
	static SDL_Texture* txt;

	void breakPlatform();
	void init(int2);
	void update();

	SDL_Texture* getTxt() {
		return txt;
	}
};

