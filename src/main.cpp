#include "World.h" 
#include <time.h>
#include <cstdlib>
#include "InputManager.h"

#undef main

World world;

static const int SLOWDOWN = 1;
static Uint32 next_time;
static const int TICK_INTERVAL = 1000 / FPS * SLOWDOWN;

Uint32 time_left()
{
	Uint32 now;

	now = SDL_GetTicks();
	if (next_time <= now) return 0;
	else return next_time - now;
}

int main(int* argc, char* argv[])
{
	srand(time(NULL));
	world.init();
	next_time = SDL_GetTicks() + TICK_INTERVAL;
	world.run();

	while (world.isRunning())
	{
		world.run();
		SDL_Delay(time_left());
		next_time += TICK_INTERVAL;
		// cout << "tick\n";
	}

	return 0;
}