#pragma once
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "segment.hpp"

#define MOVECASE 10

class Snake 
{
public:
    void Print();
private:
    Segment* head;
};