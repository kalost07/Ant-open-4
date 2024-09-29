#include "StartMenu.h"
#include "Presenter.h"

void Menu::init_quit()
{
	m_quit_rect.x = 1240;
	m_quit_rect.y = 600;
	m_quit_rect.w = 400;
	m_quit_rect.h = 200;
	m_quit_texture = loadTexture("quit.bmp");
}

void Menu::init_play()
{
	m_play_rect.x = 340;
	m_play_rect.y = 600;
	m_play_rect.w = 400;
	m_play_rect.h = 200;
	m_play_texture = loadTexture("play.bmp");
}

void Menu::init_title()
{
	m_title_rect.w = 1000;
	m_title_rect.x = (1920 - m_title_rect.w) / 2;
	m_title_rect.y = 100;
	m_title_rect.h = 500;
	m_title_texture = loadTexture("title.bmp");
}

void Menu::init_background_start()
{
	m_background_start_rect.x = 0;
	m_background_start_rect.y = 0;
	m_background_start_rect.w = 1920;
	m_background_start_rect.h = 1080;
	m_background_start_texture = loadTexture("background.bmp");
}

void Menu::init_all_start()
{
	init_background_start();
	init_quit();
	init_title();
	init_play();
}


void Menu::draw_quit()
{
	Drawable tmp;
	tmp.texture = m_quit_texture;
	tmp.drect = m_quit_rect;

	tmp.srect = { 0,0,m_quit_rect.w,m_quit_rect.h };
	drawObject(tmp);
}

void Menu::draw_play()
{
	Drawable tmp;
	tmp.texture = m_play_texture;
	tmp.drect = m_play_rect;

	tmp.srect = { 0,0,m_play_rect.w,m_play_rect.h };
	drawObject(tmp);
}

void Menu::draw_title()
{
	Drawable tmp;
	tmp.texture = m_title_texture;
	tmp.drect = m_title_rect;

	tmp.srect = { 0,0,m_title_rect.w,m_title_rect.h };
	drawObject(tmp);
}

void Menu::draw_background_start()
{
	Drawable tmp;
	tmp.texture = m_background_start_texture;
	tmp.drect = m_background_start_rect;
	tmp.srect = { 0,0,m_background_start_rect.w,m_background_start_rect.h };
	drawObject(tmp);
}

void Menu::draw_all_start()
{
	draw_background_start();
	draw_quit();
	draw_play();
	draw_title();
}
