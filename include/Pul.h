#pragma once 

#include "defines.h"

class Pul {
public:
	Pul();
	~Pul();

	bool active = false;

	SDL_Rect pos;
	int m_player;
	SDL_Texture* m_txt;

	void init(int2, int, int);
	void draw();

};