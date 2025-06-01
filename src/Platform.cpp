#include "Platform.h"
#include "World.h"
extern World world;

SDL_Texture* Platform::txt = loadTexture("platform.bmp");

Platform::Platform()
{
}

Platform::~Platform()
{
}

void Platform::init(int2 p)
{
	pos = { p.x, p.y, 100, 20 };
}

void Platform::baseUpdate() {
	// move from char
	pos.y += world.m_game.m_board.tiger.vel;
}

void Platform::update()
{
	baseUpdate();
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
