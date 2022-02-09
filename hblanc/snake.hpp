#pragma once
#include "segment.hpp"
#define MOVECASE 10

class Snake 
{
public:
    void Move(int dir);
    void Eat();
    void Print();
private:
    Segment* head;
};