#include "Platform.h"
#include "World.h"

SDL_Texture* Platform::txt;

Platform::Platform()
{
}

Platform::~Platform()
{
}

void Platform::init(int2 p)
{
	pos = { p.x, p.y, 100, 50 };
}

void Platform::update()
{
}

void Platform::draw()
{
	Drawable tmp;
	tmp.drect = pos;
	tmp.texture = getTxt();
	drawObject(tmp);
	SDL_SetRenderDrawColor(Presenter::m_main_renderer, 255, 0, 0, 1);
	SDL_RenderDrawRect(Presenter::m_main_renderer, &pos);
}

void Platform::exit()
{
}
