#pragma once
#include "Engine.h"

class Menu {
public:
	SDL_Rect m_background_start_rect;
	SDL_Texture* m_background_start_texture;

	SDL_Rect m_title_rect;
	SDL_Texture* m_title_texture;

	SDL_Rect m_quit_rect;
	SDL_Texture* m_quit_texture;

	SDL_Rect m_play_rect;
	SDL_Texture* m_play_texture;

	SDL_Rect m_playBotE_rect;
	SDL_Texture* m_playBotE_texture;

	SDL_Rect m_playBotH_rect;
	SDL_Texture* m_playBotH_texture;

	SDL_Rect m_win_rect;
	SDL_Texture* m_win_texture;

	void init_play();
	void init_playBotE();
	void init_playBotH();
	void init_quit();
	void init_title();
	void init_background_start();
	void init_win(int);

	void init_all_start();
	void init_win_scr(int);

	void draw_quit();
	void draw_play();
	void draw_playBotE();
	void draw_playBotH();
	void draw_title();
	void draw_background_start();
	void draw_win();

	void draw_all_start();
	void draw_win_scr();
};