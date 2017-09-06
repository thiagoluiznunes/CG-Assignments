#ifndef COLOR_H
#define COLOR_H

#include "definitions.h"

class Color {
private:
  int R;
  int G;
  int B;
  int A;
public:
  Color(const int R, const int G, const int B, const int A);
  ~Color();

  int getR() const;
  int getG() const;
  int getB() const;
  int getA() const;
};
Color::Color(const int r, const int g, const int b, const int a) {
  R = r;
  G = g;
  B = b;
  A = a;
}
int Color::getR() const {
   return R;
}
int Color::getG() const {
   return G;
}
int Color::getB() const {
   return B;
}
int Color::getA() const {
   return A;
}
#endif
