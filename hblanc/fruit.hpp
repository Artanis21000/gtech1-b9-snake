#pragma once
#define MOVECASE 10

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>

using namespace std;
int fruitX;
int fruitY;

void generateFruit() 
{
    srand (time(NULL));
    fruitX = rand() % 800;
    fruitY = rand() % 800;
}