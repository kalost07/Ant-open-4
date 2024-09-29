#include "Pul.h"
#include "Presenter.h"

Pul::Pul()
{
}

Pul::~Pul()
{
}
void Pul::init(int2 pos1,int player,int txt_num)
{
	m_player = player;
	pos = { pos1.x,pos1.y,100,100 };
	active = true;
	switch (txt_num) {
		case 0:
			m_txt = loadTexture("pul0.bmp");
			break;
		case 1:
			m_txt = loadTexture("pul1.bmp");
			break;
		case 2:
			m_txt = loadTexture("pulBotE.bmp");
			break;
		case 3:
			m_txt = loadTexture("pulBotH.bmp");
			break;
	}
}

void Pul::draw()
{	
	Drawable tmp;
	tmp.drect = pos;
	tmp.texture = m_txt;
	drawObject(tmp);
}
	

