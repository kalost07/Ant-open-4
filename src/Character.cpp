#include "Character.h"
#include "World.h"
extern World world;

Character::Character()
{
}

Character::~Character()
{
}

void Character::init()
{
	pos = { 1920 / 2 - 64 / 2, 1080 - 128 - 200, 64, 128 };
	txt = loadTexture("placeholder");
}

void Character::update()
{
	if (Board::controlEnabled) {
		if (world.m_inputManager.m_keyboardState[SDL_SCANCODE_A] ||
			world.m_inputManager.m_keyboardState[SDL_SCANCODE_LEFT]) {
			pos.x -= world.m_game.getSpeed();
		}
		if (world.m_inputManager.m_keyboardState[SDL_SCANCODE_D] ||
			world.m_inputManager.m_keyboardState[SDL_SCANCODE_RIGHT]) {
			pos.x += world.m_game.getSpeed();
		}
	}
}

void Character::draw()
{
	Drawable tmp;
	tmp.drect = pos;
	tmp.texture = txt;
	drawObject(tmp);
	SDL_SetRenderDrawColor(Presenter::m_main_renderer, 255, 0, 0, 1);
	SDL_RenderDrawRect(Presenter::m_main_renderer, &pos);
}

void Character::exit()
{

}