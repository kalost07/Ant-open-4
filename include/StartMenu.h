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

	SDL_Rect m_background_outFuel_rect;
	SDL_Texture* m_background_outFuel_texture;

	SDL_Rect m_outFuel_rect;
	SDL_Texture* m_outFuel_texture;
	
	SDL_Rect m_background_crashed_rect;
	SDL_Texture* m_background_crashed_texture;

	SDL_Rect m_crashed_rect;
	SDL_Texture* m_crashed_texture;
	
	SDL_Rect m_background_escaped_rect;
	SDL_Texture* m_background_escaped_texture;

	SDL_Rect m_escaped_rect;
	SDL_Texture* m_escaped_texture;

	void init_play();
	void init_quit();
	void init_title();
	void init_background_start();

	void init_all_start();

	void init_outFuel();
	void init_background_outFuel();
	void init_outFuel_all();

	void init_crashed();
	void init_background_crashed();
	void init_crashed_all();

	void init_escaped();
	void init_background_escaped();
	void init_escaped_all();



	void draw_quit();
	void draw_play();
	void draw_title();
	void draw_background_start();

	void draw_all_start();

	void draw_outFuel();
	void draw_background_outFuel();
	void draw_outFuel_all();

	void draw_crashed();
	void draw_background_crashed();
	void draw_crashed_all();

	void draw_escaped();
	void draw_background_escaped();
	void draw_escaped_all();
};