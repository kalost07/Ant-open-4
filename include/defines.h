#pragma once

#include <iostream>
#include <string>

#include <vector>
#include <SDL.h>

using namespace std;

#define D(x) cerr << #x << " = " << (x) << " | " << __LINE__ << endl;
#define Dex(x) cerr << #x << " = " << (x) << " | " << __LINE__ << " " << __FILE__ << endl;
#define __FILE_NAME__ (strrchr(__FILE__, '\\' ) ? strrchr(__FILE__, '\\') + 1 : __FILE__)

static string MENU_FOLDER = "menu\\";
static string MAIN_FOLDER = "main\\";
static string IMG_FOLDER = "img\\";
static string CONFIG_FOLDER = "config\\";
static string FONT_FOLDER = "ttf\\";
static string SOUND_FOLDER = "music\\";
static string TITLE_SCREEN_FOLDER = "titleScreen\\";
static string WIN_SCREEN_FOLDER = "winScreen\\";
static string GAME_FOLDER = "game\\";

const float GRAVITY = 32;
const int FPS = 60;
const bool DEBUG = false;

struct int2
{
    int x = 0;
    int y = 0;
};

struct float2
{
    float x = 0;
    float y = 0;
};

enum class SOUND
{
    NONE = 0,
    BACKGROUND = 1
};

struct Drawable
{
    SDL_Texture* texture = nullptr;
    SDL_Rect drect = { 0 }; /// The rect where we draw
    SDL_Rect srect = { 0,0,1920,1080 }; /// The part of the sprite we draw
    SDL_RendererFlip flip = SDL_FLIP_NONE;
    int angle = 0;
};
