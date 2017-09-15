#ifndef VERTEX_H
#define VERTEX_H

#include "definitions.h"

class Vertex {
private:
  int x1, x2;
  int y1, y2;
public:
  Vertex(const int x1, const int y1, const int x2, const int y2);
  // ~Vertex();

  int getX1() const;
  int getY1() const;
  int getX2() const;
  int getY2() const;
};
Vertex::Vertex(const int x1Width, const int y1Height, const int x2Width, const int y2Height) {
  x1 = x1Width;
  y1 = y1Height;
  x2 = x2Width;
  y2 = y2Height;
}
int Vertex::getX1() const {
   return x1;
}
int Vertex::getY1() const {
   return y1;
}
int Vertex::getX2() const {
   return x2;
}
int Vertex::getY2() const {
   return y2;
}

#endif
