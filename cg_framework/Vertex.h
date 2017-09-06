#ifndef VERTEX_H
#define VERTEX_H

#include "definitions.h"
#include "Color.h"

class Vertex {
private:
  int x;
  int y;
  // Color color;
public:
  Vertex(const int x, const int y);
  ~Vertex();

  int getX() const;
  int getY() const;
  // Color getColor() const;
};
Vertex::Vertex(const int xWidth, const int yHeight) {
  x = xWidth;
  y = yHeight;
  // color = rgba;
}
int Vertex::getX() const {
   return x;
}
int Vertex::getY() const {
   return y;
}
// Color Vertex::getColor() const {
//    return color;
// }
#endif
