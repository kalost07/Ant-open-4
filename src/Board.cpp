#include "Board.h"
#include "Presenter.h"
#include "InputManager.h"
#include "World.h"

Board::Board()
{

}

Board::~Board()
{
}

void Board::init()
{
	m_rect = { 0,0,640,480 };
	txt = loadTexture("board.bmp");
	//init pulove
}

void Board::update()
{
	//update pulove
}

void Board::draw()
{
	Drawable tmp;
	tmp.drect = m_rect;
	tmp.texture = txt;
	drawObject(tmp);
	//draw pulove
}

void Board::exit()
{
	//quit pulove
}
