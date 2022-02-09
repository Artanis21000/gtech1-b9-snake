#pragma once
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
    fruitX = rand() % 600;
    fruitY = rand() % 600;
}