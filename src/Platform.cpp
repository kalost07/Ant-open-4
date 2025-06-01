#include "Platform.h"
#include "Presenter.h"

Platform::Platform()
{
}

Platform::~Platform()
{
}

void Platform::init(int2)
{
}

void Platform::update()
{
}

void Platform::draw()
{
	Drawable tmp;
	tmp.drect = pos;
	tmp.texture = txt;
	drawObject(tmp);
}

void Platform::exit()
{
}
