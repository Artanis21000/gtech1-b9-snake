#pragma once

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

#define MOVECASE 10

class Segment
{
public:
  Segment(int x, int y);
  ~Segment();
  void Tondaron();

  int GetX();
  int GetY();
  void SetX(int);
  void SetY(int);

  Segment *GetNext();
  void SetNext(Segment *next);

private:
  int x, y;
  Segment *next;
  Segment *head;
  Segment *tail;
};