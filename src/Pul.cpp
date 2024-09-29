#include "Pul.h"
#include "Presenter.h"

Pul::Pul()
{
}

Pul::~Pul()
{
}
void Pul::init(int2 pos1,int player)
{
	m_player = player;
	pos = { pos1.x,pos1.y,100,100 };
	active = true;
	switch (m_player) {
		case 0:
			txt = loadTexture("pul0.bmp");
			break;
		case 1:
			txt = loadTexture("pul1.bmp");
			break;
	}
}

void Pul::draw()
{	
	Drawable tmp;
	tmp.drect = pos;
	tmp.texture = txt;
	drawObject(tmp);
}
	

void Pul::exit() {
	SDL_DestroyTexture(txt);
	active = false;
}

