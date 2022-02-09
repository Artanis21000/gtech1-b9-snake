#pragma once

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

#define MOVECASE 10
#define UP -1
#define DOWN 1
#define RIGHT -2
#define LEFT 2

int move(int dir);