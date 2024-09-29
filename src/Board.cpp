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
	pulCount = 0;
}

void Board::update()
{
	int col;
	if (world.m_game.turn == 0) col = placeInput();
	else {
		switch (world.m_game.botState) {
		case 0:
			col = placeInput();
			break;
		case 1:
			col = botPlaceRandom();
			break;
		case 2:
			col = botPlace();
			break;
		}
	}
	int2 pos = placePul(col, world.m_game.turn);
	if (pos.x != -1) {
		bool win = checkWin(world.m_game.turn);
		if (win) {
			world.game_state = 2;
			endState = world.m_game.turn;
		}
		world.m_game.turn = !world.m_game.turn;
		pulCount++;
		if (world.game_state != 2 && pulCount == 42) {
			world.game_state = 2;
			endState = 2;
		}
	}
	//update pulove
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
int2 Board::placePul(int col,bool player)
{
	if (col == -1)return { -1,-1 };
	for (int i = 0; i < 6; i++) {
		if (pulove[i][col].active == false) {
			int txt_num;
			if (player == 0) txt_num = 0;
			else txt_num = world.m_game.botState + 1;
			pulove[i][col].init({ col * 100 + 1920 / 2 - 700 / 2,1080 - i * 100 - 100 }, player, txt_num);
			return { i,col };
		}
	}
	return { -1,-1 };
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
bool Board::checkWin(bool player)
{
	for (int x = 0; x < 6; x++) {
		for (int y = 0; y < 7; y++) {


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
				for (int j = 0; j < 4; j++) {
					if (x - j * offset.x < 0 || x - j * offset.x>5 || y - j * offset.y < 0 || y - j * offset.y>6
						|| pulove[x - j * offset.x][y - j * offset.y].active == false ||
						player != pulove[x - j * offset.x][y - j * offset.y].m_player) {
						winningLine = false;
					}
				}
				if (winningLine) {
					return true;
				}

			}
		}
	}
	return false;
}


bool Board::checkWinCoords(int2 coords, bool player)
{
	placePul(coords.x,player);
	for (int x = 0; x < 6; x++) {
		for (int y = 0; y < 7; y++) {


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
					while (coords.x - j * offset.x < 0 || coords.x - j * offset.x>5 || coords.y - j * offset.y < 0 || coords.y - j * offset.y>6
						|| pulove[coords.x - j * offset.x][coords.y - j * offset.y].active == false ||
						player != pulove[coords.x - j * offset.x][coords.y - j * offset.y].m_player) {
						winningLine=false;
					}
				}
				if (winningLine) {
					return true;
				}

			}
		}
	}
	return false;
}

void Board::exit()
{
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 7; j++) {
			pulove[i][j].exit(); 
		}
	}
	//quit pulove
}

int Board::botPlace() {

	// Check own wins
	for (int i = 0; i < 7; i++) {
		int2 pos = placePul(i, 1);
		if (pos.x == -1) continue;
		bool win = checkWin(1);
		pulove[pos.x][pos.y].exit();
		if (win) return i;
	}
	// Check opp wins
	for (int i = 0; i < 7; i++) {
		int2 pos = placePul(i, 0);
		if (pos.x == -1) continue;
		bool win = checkWin(0);
		pulove[pos.x][pos.y].exit();
		if (win) return i;
	}
	return botPlaceRandom();
}
int Board::botPlaceRandom() {
	return rand() % 7;
}