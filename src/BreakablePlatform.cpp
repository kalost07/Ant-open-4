#include "BreakablePlatform.h"

SDL_Texture* BreakablePlatform::txt = loadTexture("BreakablePlatform.bmp");

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

}

void BreakablePlatform::update() {
	baseUpdate();
}