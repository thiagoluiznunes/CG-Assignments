#ifndef _MYGL_H_
#define _MYGL_H_

#include "definitions.h"
#include <vector>

//*****************************************************************************
// Defina aqui as suas funções gráficas
//*****************************************************************************

void printPixel(int x, int y, std::vector<int>& myRGBA) {
  for (size_t i = 0; i < 4; i++) {
    FBptr[x*4+i + y*4*IMAGE_WIDTH] = myRGBA.at(i);
  }
}


#endif // _MYGL_H_
