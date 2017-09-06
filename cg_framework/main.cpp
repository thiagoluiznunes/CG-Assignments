#include "main.h"
#include <vector>

//-----------------------------------------------------------------------------
void MyGlDraw(void)
{
	//*************************************************************************
	// Chame aqui as funções do mygl.h
	//*************************************************************************

	int height, width;
	int red, green, blue, alpha;


	std::vector<int> coordinatesVector;
	std::vector<int> rgbaVector;


	// std::cout << "Type the coordinates height and width at sequences: " << '\n';
	// std::cin >> height >> width;
	// std::cout << "Type the color:" << '\n';
	// std::cin >> red >> green >> blue >> alpha;

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

	coordinatesVector.push_back(0); //x1
	coordinatesVector.push_back(0); //y1
	coordinatesVector.push_back(200); //x2
	coordinatesVector.push_back(200); //y2

	// m = (y2-y1)
	// 		(x2-x1)
	// desde que = x2-x1 >= y2-y1
	rgbaVector.push_back(255);
	rgbaVector.push_back(255);
	rgbaVector.push_back(255);
	rgbaVector.push_back(1);

	// putPixel(width, height, rgbaVector);
	// drawLine(coordinatesVector, rgbaVector);
	ddaAlgorithm(coordinatesVector, rgbaVector);

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
