// MovingPlatform.cpp
#include "MovingPlatform.h"
#include "Board.h"

SDL_Texture* MovingPlatform::txt = loadTexture("movingPlatform.bmp");

MovingPlatform::MovingPlatform() {}

MovingPlatform::~MovingPlatform() {}

void MovingPlatform::init(int2 p) {
    pos.w = 100;
    pos.h = 20;
    left = rand() % (Board::m_rect.w - (pos.w*3)) + Board::m_rect.x;
    right = (rand() % (Board::m_rect.w))+ Board::m_rect.x;
    while (right - left < pos.w*3 ) {
        left = rand() % (Board::m_rect.w - (pos.w)) + Board::m_rect.x;
        right = rand() % (Board::m_rect.w)+Board::m_rect.x;
    }
    pos.x = left+rand()%(right-left);
    pos.y = p.y;
}

void MovingPlatform::update() {
    baseUpdate();
    move();
}

void MovingPlatform::move() {
    pos.x += dir * speed;
    if (pos.x < left) {
        dir = 1;
        pos.x = left;
    }
    if (pos.x > right - pos.w) {
        dir = -1;
        pos.x = right - pos.w;
    }
}
