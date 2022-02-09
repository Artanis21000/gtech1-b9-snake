#pragma once
#define MOVECASE 10

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>

using namespace std;
int xf;
int yf;
int sizef;

void generateFruit() 
{
    srand (time(NULL));
    xf = rand() % 640;
    yf = rand() % 640;
    sizef = 15;
}