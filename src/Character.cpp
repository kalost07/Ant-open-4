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
	pos = { 1920 / 2 - 64 / 2, 1080 - 128 - 300, 64, 128 };
	txt = loadTexture("tiger.bmp");
	vel = 0;
	startedJumping = false;
}

void Character::update()
{
	if (Board::controlEnabled) {
		if (startedJumping == true) {
			if ((world.m_inputManager.m_keyboardState[SDL_SCANCODE_A] ||
				world.m_inputManager.m_keyboardState[SDL_SCANCODE_LEFT] ) && pos.x>Board::m_rect.x) {
				pos.x -= world.m_game.getSpeed();
			}
			if ((world.m_inputManager.m_keyboardState[SDL_SCANCODE_D] ||
				world.m_inputManager.m_keyboardState[SDL_SCANCODE_RIGHT]) && pos.x < Board::m_rect.x + Board::m_rect.w - pos.w) {
				pos.x += world.m_game.getSpeed();
			}
		}
		else {
			if (world.m_inputManager.m_keyboardState[SDL_SCANCODE_SPACE]) {
				startedJumping = true;
				vel = 15;
			}
		}
		
	}
	if (startedJumping == true) {
		vel -= Board::GRAV;
		for (auto& platform : world.m_game.m_board.platforms) {
			if (collRectRect(pos, platform->pos) && vel < 0) { // jump
				vel = 25;
				if (auto* breakable = dynamic_cast<BreakablePlatform*>(platform.get())) {
					breakable->breakPlatform();
				}
			}
		}
		if (vel < -100) vel = -100;
	}
}

void Character::draw()
{
	Drawable tmp;
	tmp.drect = pos;
	tmp.texture = txt;
	tmp.srect = { 0, 0, 40, 62 };
	if (vel<0) tmp.srect.x = 40;
	drawObject(tmp);
}

void Character::exit()
{

}