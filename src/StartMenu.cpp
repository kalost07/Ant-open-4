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

void Menu::init_background_outFuel()
{
	m_background_outFuel_rect.x = 0;
	m_background_outFuel_rect.y = 0;
	m_background_outFuel_rect.w = 1920;
	m_background_outFuel_rect.h = 1080;
	//m_background_outFuel_texture = loadTexture("backgroundOutFuel.bmp");
}

void Menu::init_background_crashed()
{
	m_background_crashed_rect.x = 0;
	m_background_crashed_rect.y = 0;
	m_background_crashed_rect.w = 1920;
	m_background_crashed_rect.h = 1080;
	m_background_crashed_texture = loadTexture("backgroundCrashed.bmp");
}

void Menu::init_background_escaped()
{
	m_background_escaped_rect.x = 0;
	m_background_escaped_rect.y = 0;
	m_background_escaped_rect.w = 1920;
	m_background_escaped_rect.h = 1080;
	m_background_escaped_texture = loadTexture("backgroundEscaped.bmp");
}

void Menu::init_outFuel()
{
	m_outFuel_rect.w = 1000;
	m_outFuel_rect.x = (1920 - m_outFuel_rect.w) / 2;
	m_outFuel_rect.y = 100;
	m_outFuel_rect.h = 500;
	m_outFuel_texture = loadTexture("outFuel.bmp");
}
void Menu::init_crashed()
{
	m_crashed_rect.w = 1000;
	m_crashed_rect.x = (1920 - m_crashed_rect.w) / 2;
	m_crashed_rect.y = 100;
	m_crashed_rect.h = 500;
	m_crashed_texture = loadTexture("crashed.bmp");
}
void Menu::init_escaped()
{
	m_escaped_rect.w = 1000;
	m_escaped_rect.x = (1920 - m_escaped_rect.w) / 2;
	m_escaped_rect.y = 100;
	m_escaped_rect.h = 500;
	m_escaped_texture = loadTexture("escaped.bmp");
}

void Menu::init_crashed_all() {
	init_crashed();
	init_background_crashed();
}

void Menu::init_outFuel_all() {
	init_outFuel();
	init_background_outFuel();
}


void Menu::init_escaped_all() {
	init_escaped();
	init_background_escaped();
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

void Menu::draw_outFuel()
{
	Drawable tmp;
	tmp.texture = m_outFuel_texture;
	tmp.drect = m_outFuel_rect;

	tmp.srect = { 0,0,m_outFuel_rect.w,m_outFuel_rect.h };
	drawObject(tmp);
}

void Menu::draw_background_outFuel()
{
	Drawable tmp;
	tmp.texture = m_background_outFuel_texture;
	tmp.drect = m_background_outFuel_rect;
	tmp.srect = { 0,0,m_background_outFuel_rect.w,m_background_outFuel_rect.h };
	drawObject(tmp);
}

void Menu::draw_outFuel_all()
{
	draw_background_outFuel();
	draw_outFuel();
}

void Menu::draw_crashed()
{
	Drawable tmp;
	tmp.texture = m_crashed_texture;
	tmp.drect = m_crashed_rect;

	tmp.srect = { 0,0,m_crashed_rect.w,m_crashed_rect.h };
	drawObject(tmp);
}

void Menu::draw_background_crashed()
{
	Drawable tmp;
	tmp.texture = m_background_crashed_texture;
	tmp.drect = m_background_crashed_rect;
	tmp.srect = { 0,0,m_background_crashed_rect.w,m_background_crashed_rect.h };
	drawObject(tmp);
}

void Menu::draw_crashed_all()
{
	draw_background_crashed();
	draw_crashed();
}


void Menu::draw_escaped()
{
	Drawable tmp;
	tmp.texture = m_escaped_texture;
	tmp.drect = m_escaped_rect;

	tmp.srect = { 0,0,m_escaped_rect.w,m_escaped_rect.h };
	drawObject(tmp);
}

void Menu::draw_background_escaped()
{
	Drawable tmp;
	tmp.texture = m_background_escaped_texture;
	tmp.drect = m_background_escaped_rect;
	tmp.srect = { 0,0,m_background_escaped_rect.w,m_background_escaped_rect.h };
	drawObject(tmp);
}

void Menu::draw_escaped_all()
{
	draw_background_escaped();
	draw_escaped();
}
