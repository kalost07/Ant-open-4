#include "progressBar.h"
#include "World.h"
extern World world;

ProgressBar::ProgressBar()
{
}

ProgressBar::~ProgressBar()
{
}

void ProgressBar::init() {
	txt = loadTexture("sushi.bmp");
	pos = { 1920 / 2 + 1120 / 2 + 10, 1080 - 110, 90, 110 };
}
void ProgressBar::update() {
	pos.y = 1080 - 110 - double(world.m_game.m_board.dist) / world.m_game.m_board.goalDist * (1080 - 110);
}
void ProgressBar::draw() {
	Drawable tmp;
	tmp.drect = pos;
	tmp.texture = txt;
	drawObject(tmp);
}
void ProgressBar::exit() {

}