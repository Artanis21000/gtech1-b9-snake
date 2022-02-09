#pragma once
#define MOVECASE 10

class Segment
{
public:
  Segment(int x, int y);
  ~Segment();

  int GetX();
  int GetY();
  void SetX(int);
  void SetY(int);

  Segment *GetNext();
  void SetNext(Segment *next);

private:
  int x, y;
  Segment *next;
};