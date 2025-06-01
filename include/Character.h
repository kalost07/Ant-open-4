#pragma once
#include<SDL.h>

class Character
{
public:
	Character();
	~Character();

	void init();
	void update();
	void draw();
	void exit();

	SDL_Rect pos;
	SDL_Texture* txt;
};

