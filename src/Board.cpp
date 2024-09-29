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
	m_rect = { 0,0,640,480 };
	txt = loadTexture("board.bmp");
}

void Board::update()
{
	if (world.m_inputManager.m_keyboardState[SDLK_1]||true) {
		if(placePul(1, world.m_game.turn)) goto skip_input;
	}
	if (world.m_inputManager.m_keyboardState[SDLK_2]) {
		if (placePul(2, world.m_game.turn)) goto skip_input;
	}
	if (world.m_inputManager.m_keyboardState[SDLK_3]) {
		if (placePul(3, world.m_game.turn)) goto skip_input;
	}
	if (world.m_inputManager.m_keyboardState[SDLK_4]) {
		if (placePul(4, world.m_game.turn)) goto skip_input;
	}
	if (world.m_inputManager.m_keyboardState[SDLK_5]) {
		if (placePul(5, world.m_game.turn)) goto skip_input;
	}
	if (world.m_inputManager.m_keyboardState[SDLK_6]) {
		if (placePul(6, world.m_game.turn)) goto skip_input;
	}
	if (world.m_inputManager.m_keyboardState[SDLK_7]) {
		if (placePul(7, world.m_game.turn)) goto skip_input;
	}
	skip_input:
	;
	//update pulove
}

bool Board::placePul(int col,bool player)
{
	for (int i = 0; i < 6; i++) {
		if (pulove[i][col].active == false) {
			pulove[i][col].init({ col * 100,1000 - i * 100 }, player);
			std::cout << "h";
			return true;
		}
	}
	return false;
}
void Board::draw()
{
	Drawable tmp;
	tmp.drect = m_rect;
	tmp.texture = txt;
	drawObject(tmp);
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 7; j++) {
			if (pulove[i][j].active) pulove[i][j].draw();
		}
	}
}

void Board::exit()
{
	//quit pulove
}
