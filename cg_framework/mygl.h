#ifndef _MYGL_H_
#define _MYGL_H_

#include "definitions.h"
#include <vector>
#include <iostream>
#include <string>
#include <math.h>

//*****************************************************************************
// Defina aqui as suas funções gráficas
//*****************************************************************************

void putPixel(int xWidth, int yHeight, std::vector<int>& myRGBA) {
  for (size_t i = 0; i < 4; i++) {
    FBptr[xWidth*4+i + yHeight*4*IMAGE_WIDTH] = myRGBA.at(i);
  }
}

void drawLine(std::vector<int>& coordinates, std::vector<int>& myRGBA) {
  if(coordinates.at(1) == coordinates.at(3)) {
    int s = coordinates.at(0) - coordinates.at(2);
    if(s < 0) {
      s *= -1;
    }
    for (size_t i = 0; i < s; i++) {
      putPixel(coordinates.at(0) + i, coordinates.at(1), myRGBA);
    }
  }
}
void colorInterpolation(int i, int *j, int dx, std::vector<int>* myRGBA) {
  if(i < dx/2) {
    myRGBA->at(0) = 255-i;
    myRGBA->at(1) = i;
  } else {
    myRGBA->at(0) = 0;
    myRGBA->at(1) = 250-*j;
    myRGBA->at(2) = *j;
    *j = *j + 1;
  }
}
void ddaAlgorithm(std::vector<int>& coordinates, std::vector<int>& myRGBA) {
  int x1 = coordinates.at(0);
  int y1 = coordinates.at(1);
  int x2 = coordinates.at(2);
  int y2 = coordinates.at(3);

  float dx = x2-x1;
  float dy = y2-y1;

  float m = dy/dx;
  float b = y1 - (m*x1);

  int j = 0;
  for (size_t i = 0; i < dx; i++) {
    colorInterpolation(i, &j, dx, &myRGBA);
    putPixel(x1+i, round(m*(x1+i)+b), myRGBA);
  }
}
void bresenhamAlgorithm(std::vector<int>& coordinates, std::vector<int>& myRGBA) {
  int x1 = coordinates.at(0);
  int y1 = coordinates.at(1);
  int x2 = coordinates.at(2);
  int y2 = coordinates.at(3);

  int dx = x2-x1;
  int dy = y2-y1;
  int d = 2*dy-dx;
  int incr_e = 2 * dy;
  int incr_ne = 2 * (dy-dx);
  int x = x1;
  int y = y1;
  putPixel(x,y, myRGBA);

  int j = 0;
  while(x < x2) {
    if(d <= 0) {
      d += incr_e;
      x++;
    } else {
      d += incr_ne;
      x++;
      y++;
    }
    colorInterpolation(x, &j, x2, &myRGBA);
    putPixel(x, y, myRGBA);
  }
  // int j = 0;
  // for (size_t i = x1; i < x2; i++) {
  //   colorInterpolation(i, &j, x2, &myRGBA);
  //   if(d <= 0) {
  //     d += incr_e;
  //   } else {
  //     d += incr_ne;
  //     y++;
  //   }
  //   putPixel(x, y, myRGBA);
  // }
}

#endif // _MYGL_H_
