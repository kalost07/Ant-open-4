#include "Board.h"
#include "Presenter.h"
#include "InputManager.h"
#include "World.h"

extern World world;
bool Board::controlEnabled = true;

Board::Board()
{

}

Board::~Board()
{

}

void Board::init(int hole)
{
	this->hole = hole;
	m_rect = { 1920 / 2 - 1000 / 2,1080 - 1080,1000,1080 };
	txt = loadTexture("grid.bmp");
	srand(time(NULL));
	maxDist = int(10000. * hole * sqrt(hole));
	dist = 0;
	controlEnabled = true;
	tiger.init();
	platforms.emplace_back();
	for (auto platform : platforms) {
		platform.init({1000,500});
	}
}

void Board::update()
{
	for (auto platform : platforms) {
		platform.update();
	}
	tiger.update();
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
	for (auto platform : platforms) {
		platform.draw();
	}
	tiger.draw();
}

void Board::exit()
{
	for (auto platform : platforms) {
		platform.exit();
	}
	tiger.exit();
}