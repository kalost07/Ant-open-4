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

bool Board::checkWin(int2 coords)
{
	for (int i = 0; i < 8; i++) {
		int2 offset;
		switch (i) {
		case 0:
			offset = { -1,-1 };
			break;
		case 1:
			offset = { 1,-1 };
			break;
		case 2:
			offset = { 0,-1 };
			break;
		case 3:
			offset = { -1,0 };
			break;
		case 4:
			offset = { 1,0 };
			break;
		case 5:
			offset = { -1,1 };
			break;
		case 6:
			offset = { 0,1 };
			break;
		case 7:
			offset = { 1,1 };
			break;
		}
		bool winningLine = true;
		for (int j = 1; j < 4; j++) {
			if (coords.x - j * offset.x < 0 || coords.x - j * offset.x>5 || coords.y - j * offset.y < 0 || coords.y - j * offset.y>6
				|| pulove[coords.x][coords.y].m_player != pulove[coords.x - j * offset.x][coords.y - j * offset.y].m_player) {
				winningLine = false;
			}
		}
		if (winningLine) {
			return true;
		}

	}
	return false;
}

void Board::exit()
{
	//quit pulove
}
