#include "BreakablePlatform.h"

SDL_Texture* BreakablePlatform::txt = loadTexture("breakablePlatform.bmp");

BreakablePlatform::BreakablePlatform()
{
}

BreakablePlatform::~BreakablePlatform()
{
}

void BreakablePlatform::breakPlatform()
{
	active = false;
}

void BreakablePlatform::init(int2 p) {
	pos.x = p.x;
	pos.y = p.y;
	pos.w = 100;
	pos.h = 20;
	active = true;
}