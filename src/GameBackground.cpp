#include "GameBackground.h"
#include "Presenter.h"
#include "World.h"

extern World world;

GameBackground::GameBackground()
{
}

GameBackground::~GameBackground()
{
}

void GameBackground::init()
{
	stars_txt = loadTexture("stars.bmp");
	planet_txt = loadTexture("planets.bmp");
	int curr_planet = 0;
}

void GameBackground::update()
{
	star_pos = { int(world.m_game.distance * scrollMult) % STARS_WIDTH,int(world.m_game.distY * scrollMult) % STARS_HEIGTH,STARS_WIDTH,STARS_HEIGTH };
	if (curr_planet >= 6) { world.game_state = 4; }
	else {
		if (world.m_game.distance >= planet_switch[curr_planet]) curr_planet++;
	}
}

void GameBackground::draw()
{
	Drawable tmp;
	tmp.texture = stars_txt;
	tmp.drect = { 0,0,(int)Presenter::m_SCREEN_WIDTH,(int)Presenter::m_SCREEN_HEIGHT };
	tmp.srect = star_pos;
	drawObject(tmp);

	int x_pos = float(PLANET_SCREEN_DIST)/planet_dist[curr_planet] * (planet_appear[curr_planet] - world.m_game.distance);
	Drawable tmp2;
	tmp2.texture = planet_txt;
	tmp2.drect = { x_pos,140,800,800 };
	tmp2.srect = planet_txt_pos[curr_planet];
	drawObject(tmp2);
}

void GameBackground::exit()
{
	SDL_DestroyTexture(stars_txt);
	SDL_DestroyTexture(planet_txt);
}
