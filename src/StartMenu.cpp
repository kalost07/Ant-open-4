#include "StartMenu.h"
#include "Presenter.h"

void Menu::init_quit()
{
	m_quit_rect = { 105,800,400,200 };
	m_quit_texture = loadTexture("quit.bmp");
}

void Menu::init_play()
{
	m_play_rect = { 105,500,400,200 };
	m_play_texture = loadTexture("play.bmp");
}

void Menu::init_title()
{
	m_title_rect = { 0,0,1920,1080 };
	m_title_texture = loadTexture("title.bmp");
}

void Menu::init_background_start()
{
	m_background_start_rect = { 0,0,1920,1080 };
	m_background_start_texture = loadTexture("background.bmp");
}

void Menu::init_win(int player)
{
	m_win_rect = { (1920 - 400) / 2,250,400,200 };
	switch (player) {
	case 0:
		m_win_texture = loadTexture("win1.bmp");
		break;
	case 1:
		m_win_texture = loadTexture("win2.bmp");
		break;
	case 2:
		m_win_texture = loadTexture("draw.bmp");
		break;
	}
}

void Menu::init_all_start()
{
	init_background_start();
	init_quit();
	init_title();
	init_play();
}

void Menu::init_win_scr(int player)
{
	init_quit();
	init_play();
	init_win(player);
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

void Menu::draw_win()
{
	Drawable tmp;
	tmp.texture = m_win_texture;
	tmp.drect = m_win_rect;
	tmp.srect = { 0,0,600,300 };
	drawObject(tmp);
}

void Menu::draw_all_start()
{
	draw_title();
	draw_background_start();
	draw_quit();
	draw_play();
	
}

void Menu::draw_win_scr()
{
	draw_quit();
	draw_play();
	draw_win();
}