#include "Pul.h"
#include "Presenter.h"

Pul::Pul()
{
}

Pul::~Pul()
{
}
void Pul::init(int2 coords,int player)
{
	m_player = player;
	m_coords = coords;
	drawable.drect.w = 100;
	drawable.drect.h = 100;
	active = true;

}

void Pul::draw()
{	
	switch (m_player) {
	case 0:
		drawable.texture = loadTexture("pul0.bmp");
		break;
	case 1:
		drawable.texture = loadTexture("pul1.bmp");
		break;
	}
	drawObject(drawable);
}
	

