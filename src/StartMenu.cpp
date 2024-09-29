#include "StartMenu.h"
#include "Presenter.h"

void Menu::init_quit()
{
	m_quit_rect = { 840,800,400,200 };
	m_quit_texture = loadTexture("quit.bmp");
}

void Menu::init_play()
{
	m_play_rect = { 840,500,400,200 };
	m_play_texture = loadTexture("play.bmp");
}
void Menu::init_playBotE()
{
	m_playBotE_rect = { 340,500,400,200 };
	m_playBotE_texture = loadTexture("playBotE.bmp");
}
void Menu::init_playBotH()
{
	m_playBotH_rect = { 1340,500,400,200 };
	m_playBotH_texture = loadTexture("playBotH.bmp");
}

void Menu::init_title()
{
	m_title_rect = { (1920 - 1000) / 2,100,1000,500 };
	m_title_texture = loadTexture("title.bmp");
}

void Menu::init_background_start()
{
	m_background_start_rect = { 0,0,1920,1080 };
	m_background_start_texture = loadTexture("background.bmp");
}

void Menu::init_win(bool player)
{
	m_win_rect = { (1920 - 600) / 2,50,600,300 };
	if (player == 0) m_win_texture = loadTexture("win1.bmp");
	else m_win_texture = loadTexture("win2.bmp");
}

void Menu::init_all_start()
{
	init_background_start();
	init_quit();
	init_title();
	init_play();
	init_playBotE();
	init_playBotH();
}

void Menu::init_win_scr(bool player)
{
	init_quit();
	init_play();
	init_playBotE();
	init_playBotH();
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
void Menu::draw_playBotE()
{
	Drawable tmp;
	tmp.texture = m_playBotE_texture;
	tmp.drect = m_playBotE_rect;

	tmp.srect = { 0,0,m_play_rect.w,m_play_rect.h };
	drawObject(tmp);
}
void Menu::draw_playBotH()
{
	Drawable tmp;
	tmp.texture = m_playBotH_texture;
	tmp.drect = m_playBotH_rect;

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
	tmp.srect = { 0,0,m_win_rect.w,m_win_rect.h };
	drawObject(tmp);
}

void Menu::draw_all_start()
{
	draw_background_start();
	draw_quit();
	draw_play();
	draw_playBotE();
	draw_playBotH();
	draw_title();
}

void Menu::draw_win_scr()
{
	draw_quit();
	draw_play();
	draw_playBotE();
	draw_playBotH();
	draw_win();
}