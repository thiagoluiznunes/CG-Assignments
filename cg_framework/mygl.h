#ifndef _MYGL_H_
#define _MYGL_H_

#include "definitions.h"
#include <vector>

//*****************************************************************************
// Defina aqui as suas funções gráficas
//*****************************************************************************

void putPixel(int x, int y, std::vector<int>& myRGBA) {
  for (size_t i = 0; i < 4; i++) {
    FBptr[x*4+i + y*4*IMAGE_WIDTH] = myRGBA.at(i);
  }
}

void drawLine(std::vector<int>& coordinates, std::vector<int>& myRGBA) {
  if(coordinates.at(0) == coordinates.at(2)) {
    int s = coordinates.at(1) - coordinates.at(3);
    if(s < 0) {
      s *= -1;
    }
    for (size_t i = 0; i < s; i++) {
      putPixel(coordinates.at(0), coordinates.at(1) + i, myRGBA);
    }
  }
}


#endif // _MYGL_H_
