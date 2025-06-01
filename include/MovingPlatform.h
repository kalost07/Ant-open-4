#pragma once

#include "Platform.h"
#include "Presenter.h"

static SDL_Texture* model = loadTexture("MovingPlatform.bmp");

class MovingPlatform : public Platform { 
public:
    MovingPlatform();
    ~MovingPlatform();

    void init(int2) override; 
    void update() override;

    int speed = 2; 
    int dir = 1;
    int left;
    int right;

private:
    void move();
};
