#pragma once

#include "Engine.h"

class FuelBar {
public:
	FuelBar();
	~FuelBar();

	void init();
	void update();
	void draw();
	void exit();

	SDL_Texture* frame_txt;
	SDL_Rect pos;
};