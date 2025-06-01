// MovingPlatform.cpp
#include "MovingPlatform.h"
#include "Board.h"

MovingPlatform::MovingPlatform() {}

MovingPlatform::~MovingPlatform() {}

void MovingPlatform::init(int2) {
    pos.w = 50;
    pos.h = 20;
    left = rand() % (Board::m_rect.w - (3 * pos.w)) + Board::m_rect.x;
    right = left + (rand() % (Board::m_rect.w - left));
    while (right - left < pos.w * 3) {
        left = rand() % (Board::m_rect.w - (3 * pos.w)) + Board::m_rect.x;
        right = left + (rand() % (Board::m_rect.w - left));
    }
    pos.x = left;
    pos.y = rand() % (Board::m_rect.h - pos.h) + Board::m_rect.y;
    txt = model;
}

void MovingPlatform::update() {
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
