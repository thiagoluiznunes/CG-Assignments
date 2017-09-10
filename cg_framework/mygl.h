#ifndef _MYGL_H_
#define _MYGL_H_

#include "definitions.h"
#include <vector>
#include <iostream>
#include <string>
#include <cmath>
#include "Vertex.h"

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
void ddaAlgorithm(Vertex vertex, std::vector<int>& myRGBA) {
  int x1 = vertex.getX1();
  int y1 = vertex.getY1();
  int x2 = vertex.getX2();
  int y2 = vertex.getY2();


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
void bresenhamAlgorithm(Vertex vertex, std::vector<int>& myRGBA) {
  int x1 = vertex.getX1();
  int y1 = vertex.getY1();
  int x2 = vertex.getX2();
  int y2 = vertex.getY2();

  int dx = x2-x1;
  int dy = y2-y1;
  int d;
  int incr_e;
  int incr_ne;
  int x = x1;
  int y = y1;
  int j = 0;

  putPixel(x,y, myRGBA);

  //0º a 90º
  if(dx > 0 && dy > 0) {
    //0º a 45º
    if(abs(dx) > abs(dy)) {
      std::cout << "0º a 45º" << '\n';
      d = 2*dy-dx;
      incr_e = 2 * dy;
      incr_ne = 2 * (dy-dx);

      while(x < x2) {
        if(d < 0) {
          d += incr_e;
          x++;
        } else {
          d += incr_ne;
          x++;
          y++;
        }
        colorInterpolation(x, &j, x2, &myRGBA);
        putPixel(x, y, myRGBA);
        // std::cout << "X:" << x << '\n';
        // std::cout << "Y:" << y << '\n';
      }
      j = 0;
    }
    //45º a 90º
    else {
      std::cout << "45º a 90º" << '\n';
      d = dy-2*dx;
      incr_e = 2*(dy-dx);
      incr_ne = -2*dx;

      while(abs(y) < abs(y2)) {
        if(d < 0) {
          d += incr_e;
          x++;
          y++;
        } else {
          d += incr_ne;
          y++;
        }
        colorInterpolation( abs(x), &j, abs(x2), &myRGBA);
        putPixel(x, y, myRGBA);
        // std::cout << "X:" << x << '\n';
        // std::cout << "Y:" << y << '\n';
      }
      j = 0;
    }
  }
  //90º a 180º
  else if(dx < 0 && dy > 0) {
    //90º a 135º
    if(abs(dy) > abs(dx)) {
      // std::cout << "90º a 135º" << '\n';
      d = dy+2*dx;
      incr_e = 2*dx;
      incr_ne = 2*(dy+dx);

      while(abs(y) < abs(y2)) {
        if(d < 0) {
          d += incr_ne;
          // x2++;
          y2--;
        } else {
          d += incr_e;
          y2--;
          x2++;
        }
        colorInterpolation( abs(y2), &j, abs(x2), &myRGBA);
        putPixel(x2, y2, myRGBA);
        std::cout << "X2:" << x2 << '\n';
        std::cout << "Y2:" << y2 << '\n';
      }
      j = 0;
    } else {
      std::cout << "135º a 180º" << '\n';
      d = 2*dy+dx;
      incr_e = 2*(dy+dx);
      incr_ne = 2*dy;

      // x2 = 0;
      while(abs(x2) < abs(x)) {
        if(d < 0) {
          d += incr_ne;
          x2++;
        } else {
          d += incr_e;
          x2++;
          y2--;
        }
        colorInterpolation( abs(x), &j, abs(x2), &myRGBA);
        putPixel(x2, y2, myRGBA);
        // std::cout << "X2:" << x2 << '\n';
        // std::cout << "Y2:" << y2 << '\n';
      }
      j = 0;
    }
  }
  //180º a 270º
  else if(dx < 0 && dy < 0) {
    std::cout << "DRIBE DO RONADINHO1" << '\n';
    x1 = vertex.getY2();
    y1 = vertex.getX2();
    x2 = vertex.getY1();
    y2 = vertex.getX1();

    Vertex v(x1,y1,x2,y2);

    bresenhamAlgorithm(v, myRGBA);
  }
  //270º a 360º
  else {
    //dx > 0 dy < 0
    // std::cout << "DRIBE DO RONADINHO2" << '\n';
    x1 = vertex.getX2();
    y1 = vertex.getY2();
    x2 = vertex.getX1();
    y2 = vertex.getY1();

    Vertex v(x1,y1,x2,y2);

    bresenhamAlgorithm(v, myRGBA);
  }
}
void drawTriangle(Vertex first, Vertex second, Vertex third, std::vector<int>& rgba) {
  bresenhamAlgorithm(first, rgba);
  bresenhamAlgorithm(second, rgba);
  bresenhamAlgorithm(third, rgba);
}
void drawAllQuadrants(std::vector<Vertex> vertex, std::vector<int> rgba) {
  for (size_t i = 0; i < vertex.size(); i++) {
    bresenhamAlgorithm(vertex.at(i), rgba);
  }
}
#endif // _MYGL_H_
