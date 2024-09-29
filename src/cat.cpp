#include "Cat.h"
#include "Presenter.h"
#include "InputManager.h"
#include "World.h"

extern World world;

Cat::Cat()
{
}

Cat::~Cat()
{
}

void Cat::init()
{
	pos = { 200,520,CAT_WIDTH,CAT_HEIGHT };
	cent = { 100,260 };
	angle = 0;
	vel = { 0,0 };
	txt = loadTexture("rocket.bmp");
	hitbox = calc_hitbox();
	sprite = 0;
	timer = 0;
	boosting = false;
	fuel = maxFuel;
	
}

void Cat::update()
{
	boosting = false;
	timer++;
	if (timer % 6 == 0) {
		sprite++;
	}
	if (sprite == 3)sprite = 0;
	if (angle < 0) angle += 360;
	angle %= 360;

	vel.x *= 0.998;
	vel.y *= 0.998;

	if (InputManager::m_keyboardState[SDL_SCANCODE_SPACE]) boost();
	if (InputManager::m_keyboardState[SDL_SCANCODE_A]) turn(0);
	if (InputManager::m_keyboardState[SDL_SCANCODE_D]) turn(1);

	if (timer >= 60) timer = 0;
	hitbox = calc_hitbox();

	if (fuel == 0 && abs(vel.x) <= 0.1 && abs(vel.y) <= 0.1) { world.game_state = 2; } // game over

	/*
	int svelx = vel.x;
	for (int i = 0; i < 4; i++) {
		int2 dist;
		dist.x = world.m_game.m_asteroid[i].cent.x - cent.x;
		dist.y = world.m_game.m_asteroid[i].cent.y - cent.y;
		long long tdist2 = pow(dist.x, 2) + pow(dist.y, 2);
		cout << "d: " << sqrt(tdist2) << endl;
		vel.x += (float)world.m_game.m_asteroid[i].mass * (float(dist.x)/sqrt(tdist2)) / tdist2;
		vel.y += (float)world.m_game.m_asteroid[i].mass * (float(dist.y)/sqrt(tdist2)) / tdist2;
	}
	cout << "dv: " << (vel.x - svelx) << endl;
	*/
}

void Cat::draw()
{
	Drawable tmp;
	tmp.texture = txt;
	tmp.drect = pos;
	tmp.srect = { sprite * CAT_WIDTH,boosting*CAT_HEIGHT,CAT_WIDTH,CAT_HEIGHT };
	tmp.angle = angle;
	drawObject(tmp);
	if (DEBUG) {
		SDL_SetRenderDrawColor(Presenter::m_main_renderer, 255, 0, 0, 1);
		SDL_RenderDrawRect(Presenter::m_main_renderer, &hitbox);
	}
}

void Cat::exit()
{
	SDL_DestroyTexture(txt);
}

void Cat::getFuel()
{
	fuel += 120;
	fuel = min(fuel, maxFuel);
}

SDL_Rect Cat::calc_hitbox()
{
	SDL_Rect tmp = pos;
	tmp.x += 35;
	tmp.x += 35.0 * cos(angle * 3.14 / 180);
	tmp.y += 35.0 * sin(angle * 3.14 / 180);

	tmp.w = CAT_HITBOX_WIDTH;
	tmp.h = CAT_HITBOX_HEIGHT;
	return tmp;
}

void Cat::boost()
{
	if (fuel <= 0) return;
	vel.x += BOOST_VEL * cos(angle * 3.14 / 180);
	vel.y += BOOST_VEL * sin(angle * 3.14 / 180);
	boosting = true;
	fuel--;
}

void Cat::turn(bool dir) {
	if (dir) angle += D_ANGLE;
	else angle -= D_ANGLE;
}