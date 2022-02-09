#include"move.hpp"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

int move(int dir)
{
    const Uint8 *keystates = SDL_GetKeyboardState(NULL);
    int new_dir = dir;
    if (keystates[SDL_SCANCODE_UP])
    {
       new_dir = UP;
    }
    if (keystates[SDL_SCANCODE_DOWN])
    {
        new_dir = DOWN;
    }
    if (keystates[SDL_SCANCODE_LEFT])
    {
        new_dir = LEFT;
    }
    if (keystates[SDL_SCANCODE_RIGHT])
    {
       new_dir = RIGHT;
    }
    return (dir == -new_dir) ? dir : new_dir;
}