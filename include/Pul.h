#pragma once 

#include "defines.h"

class Pul {
public:
	Pul();
	~Pul();

	bool active = false;

	int2 m_coords;
	int m_player;
	Drawable drawable;

	void init(int2, int);
	void draw();

};