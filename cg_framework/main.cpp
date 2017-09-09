#include "main.h"
#include <vector>
#include "Vertex.h"
#include "Color.h"
//-----------------------------------------------------------------------------
void MyGlDraw(void)
{
	//*************************************************************************
	// Chame aqui as funções do mygl.h
	//*************************************************************************

	int height, width;
	int red, green, blue, alpha;


	std::vector<int> coordinatesVector;
	std::vector<int> coordinatesVector2;
	std::vector<int> coordinatesVector3;
	std::vector<int> rgbaVector;
	// y
	// ^
	// |
	// |
	// |
	// |
	// |
	// |
	// |
	// |-------------------------> x
	// m = (y2-y1)
	// 		(x2-x1)
	// primeiro quadrante = x2-x1 >= y2-y1

	coordinatesVector.push_back(200); //x1
	coordinatesVector.push_back(100); //y1
	coordinatesVector.push_back(400); //x2
	coordinatesVector.push_back(101); //y2

	rgbaVector.push_back(0);
	rgbaVector.push_back(0);
	rgbaVector.push_back(0);
	rgbaVector.push_back(1);

	// putPixel(width, height, rgbaVector);
	// drawLine(coordinatesVector, rgbaVector);
	int j;
	// for (size_t i = 0; i < 500; i++) {
	// 	coordinatesVector.at(2) = 500-i;
	// 	// ddaAlgorithm(coordinatesVector, rgbaVector);
	// 	// bresenhamAlgorithm(coordinatesVector, rgbaVector);
	// }
		// ddaAlgorithm(coordinatesVector, rgbaVector);
		bresenhamAlgorithm(coordinatesVector, rgbaVector);
}
//-----------------------------------------------------------------------------
int main(int argc, char **argv)
{
	// Inicializações.
	InitOpenGL(&argc, argv);
	InitCallBacks();
	InitDataStructures();

	// Ajusta a função que chama as funções do mygl.h
	DrawFunc = MyGlDraw;

	// Framebuffer scan loop.
	glutMainLoop();

	return 0;
}
