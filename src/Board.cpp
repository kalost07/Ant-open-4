#include "Board.h"
#include "Presenter.h"
#include "InputManager.h"
#include "World.h"


extern World world;
bool Board::controlEnabled = true;
const double Board::GRAV = 0.75;
SDL_Rect Board::m_rect;

Board::Board()
{

}

Board::~Board()
{

}

void Board::init(int hole)
{
	this->hole = hole;
	m_rect = { 1920 / 2 - 1000 / 2,1080 - 1080,1120,1080 };
	switch (hole) {
		case 1: txt = loadTexture("dirt_background.bmp"); break;
		case 2: txt = loadTexture("stone_background.bmp"); break;
		case 3: txt = loadTexture("pre_hell_background.bmp"); break;
		case 4: txt = loadTexture("hell_background.bmp"); break;
		case 5: txt = loadTexture("abyss_background.bmp"); break;
	}
	Platform::txt = loadTexture("platform.bmp");
	MovingPlatform::txt = loadTexture("movingPlatform.bmp");
	BreakablePlatform::txt = loadTexture("breakablePlatform.bmp");
	
	srand(time(NULL));
	goalDist = int(1000. * hole * sqrt(hole));
	dist = 0;
	maxDist = 0;
	platDist = (hole < 4? 100: 200);
	controlEnabled = true;
	tiger.init();
	spawnPlatforms(-2500, 0);
	platforms.emplace_back(make_unique<Platform>());
	platforms.back()->init({ 1920 / 2 - 64 / 2, 1080 - 300 });
}

int Board::pickPlat() {
	double r = rand01(); // r is between 0.0 and 1.0
	switch (hole) {
		case 1:
			return 0; // Platform 100%
		case 2:
			if (r < 0.7) return 1; // Breakable 70%
			return 0; // Platform 30%
		case 3:
		case 4:
			if (r < 0.6) return 2; // Moving 60%
			if (r < 0.9) return 1; // Breakable 30%
			return 0; // Platform 10%
	}
}

void Board::spawnPlatforms(int start, int end) {
	for (int i = start - start % platDist + platDist; i < end; i += platDist) {
		switch (pickPlat()) {
		case 0: platforms.emplace_back(make_unique<Platform>()); break;
		case 1: platforms.emplace_back(make_unique<BreakablePlatform>()); break;
		case 2: platforms.emplace_back(make_unique<MovingPlatform>()); break;
		}
		platforms.back()->init({ rand() % (m_rect.w - 100) + m_rect.x, 1080 - 300 + (dist - i) - 1500 });
		cout << "spawn for dist " << i << " at " << (1080 - 300 + (dist - i) - 1500) << endl;
	}
}
void Board::update()
{
	for (auto it = platforms.begin(); it != platforms.end();) {
		if ((*it)->pos.y >= PLATFORM_DESPAWN) {
			(*it)->exit();
			it = platforms.erase(it);
			continue;
		}
		if (auto* breakable = dynamic_cast<BreakablePlatform*>((*it).get())) {
			if (breakable->active == false) {
				(*it)->exit();
				it = platforms.erase(it);
				continue;
			}
		}
		(*it)->update();
		it++;
	}
	tiger.update();
	// update dist and spawn platforms
	dist += tiger.vel;
	spawnPlatforms(maxDist, dist);
	maxDist = max(maxDist, dist);
}
int Board::placeInput()
{
	if (world.m_inputManager.m_mouseOnClick && MouseIsInRect(world.m_inputManager.m_mouseCoor, m_rect)) {
		return (world.m_inputManager.m_mouseCoor.x - 610) / 100;
	}

	if (world.m_inputManager.m_keyOnRelease[SDL_SCANCODE_1]) {
		return 0;
	}
	if (world.m_inputManager.m_keyOnRelease[SDL_SCANCODE_2]) {
		return 1;
	}
	if (world.m_inputManager.m_keyOnRelease[SDL_SCANCODE_3]) {
		return 2;
	}
	if (world.m_inputManager.m_keyOnRelease[SDL_SCANCODE_4]) {
		return 3;
	}
	if (world.m_inputManager.m_keyOnRelease[SDL_SCANCODE_5]) {
		return 4;
	}
	if (world.m_inputManager.m_keyOnRelease[SDL_SCANCODE_6]) {
		return 5;
	}
	if (world.m_inputManager.m_keyOnRelease[SDL_SCANCODE_7]) {
		return 6;
	}
	return -1;
}

void Board::draw()
{
	Drawable tmp;
	tmp.drect = m_rect;
	tmp.texture = txt;
	/*
	for (int y = m_rect.y; y < m_rect.y + m_rect.h; y += 96) {
		for (int x = m_rect.x; x < m_rect.x + m_rect.w; x += 160) {
			tmp.drect = { x, y, 160, 96 };
			drawObject(tmp);
		}
	}*/
	drawObject(tmp);
	for (auto& platform : platforms) {
		platform->draw();
	}
	tiger.draw();
}

void Board::exit()
{
	for (auto& platform : platforms) {
		platform->exit();
		
	}
	platforms.clear();
	tiger.exit();
}