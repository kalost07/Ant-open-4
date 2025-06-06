#include "Engine.h"

std::random_device rd;  // Seed source
std::mt19937 gen(rd()); // Mersenne Twister engine
std::uniform_real_distribution<> dis(0.0, 1.0);

double rand01() {
    return dis(gen);
}

SDL_Texture* LoadTexture(string configFile, SDL_Renderer* renderer)
{
    SDL_Texture* texture = nullptr;

    try
    {
        configFile = IMG_FOLDER + configFile;

        SDL_Surface* loadingSurface = SDL_LoadBMP(configFile.c_str());

        texture = SDL_CreateTextureFromSurface(renderer, loadingSurface);

        SDL_FreeSurface(loadingSurface);

        if (texture == nullptr)
        {
            throw (-1);
        }
    }
    catch (int i)
    {
        if (i < 0)
        {
            cout << "NO TEXTURE LOADED: " << configFile << endl;

            configFile = IMG_FOLDER + "textureNotLoaded.bmp";

            SDL_Surface* loadingSurface = SDL_LoadBMP(configFile.c_str());
            texture = SDL_CreateTextureFromSurface(renderer, loadingSurface);
            SDL_FreeSurface(loadingSurface);
        }
    }
    bool nuuh = false;

    return texture;
}
bool MouseIsInRect(int2 coor, SDL_Rect rect)
{
    if (coor.x >= rect.x && coor.x <= rect.x + rect.w && coor.y >= rect.y && coor.y <= rect.y + rect.h)
    {
        return true;
    }

    return false;
}

bool collRectRect(SDL_Rect a, SDL_Rect b)
{
    if (a.x < b.x + b.w && a.x + a.w > b.x && a.y < b.y + b.h && a.y + a.h > b.y)
        return true;

    return false;
}
bool checkInOffBounds(SDL_Rect rect, int screenWidth, int screenHeight)
{
    if (rect.x + rect.w > screenWidth)
    {
        return true;
    }

    if (rect.x < 0)
    {
        return true;
    }

    if (rect.y + rect.h > screenHeight)
    {
        return true;
    }

    if (rect.y < 0)
    {
        return true;
    }

    return false;
}

