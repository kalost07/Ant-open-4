#include "Board.h"
#include "Presenter.h"
#include "InputManager.h"
#include "World.h"

extern World world;

Board::Board()
{

}

Board::~Board()
{

}

void Board::init()
{
	m_rect = { 1920 / 2 - 700 / 2,1080 - 600,700,600 };
	txt = loadTexture("grid.bmp");
	srand(time(NULL));
}

void Board::update()
{

}
int Board::placeInput()
{
	if (world.m_inputManager.m_mouseOnClick && MouseIsInRect(world.m_inputManager.m_mouseCoor, m_rect)) {
		return (world.m_inputManager.m_mouseCoor.x - 610) / 100;
	}

	if (world.m_inputManager.m_keyOnRelease[SDL_SCANCODE_1]) {
		return 0;
	}
	if (world.m_inputManager.m_keyOnRelease[SDL_SCANCODE_2]) {
		return 1;
	}
	if (world.m_inputManager.m_keyOnRelease[SDL_SCANCODE_3]) {
		return 2;
	}
	if (world.m_inputManager.m_keyOnRelease[SDL_SCANCODE_4]) {
		return 3;
	}
	if (world.m_inputManager.m_keyOnRelease[SDL_SCANCODE_5]) {
		return 4;
	}
	if (world.m_inputManager.m_keyOnRelease[SDL_SCANCODE_6]) {
		return 5;
	}
	if (world.m_inputManager.m_keyOnRelease[SDL_SCANCODE_7]) {
		return 6;
	}
	return -1;
}

void Board::draw()
{
	Drawable tmp;
	tmp.drect = m_rect;
	tmp.texture = txt;
	drawObject(tmp);
}

void Board::exit()
{

}