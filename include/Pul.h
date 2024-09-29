#pragma once 

#include "defines.h"

class Pul {
public:
	Pul();
	~Pul();

	bool active = false;

	SDL_Rect pos;
	int m_player;
	SDL_Texture* txt;

	void init(int2, int);
	void draw();

	void exit();

};