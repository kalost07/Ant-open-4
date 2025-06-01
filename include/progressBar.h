#pragma once

#include "Engine.h"

class ProgressBar {
public:
	ProgressBar();
	~ProgressBar();

	void init();
	void update();
	void draw();
	void exit();

	SDL_Texture* txt;
	SDL_Rect pos;
};