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

	coordinatesVector.push_back(100);
	coordinatesVector.push_back(50);
	coordinatesVector.push_back(500);
	coordinatesVector.push_back(50);


	rgbaVector.push_back(255);
	rgbaVector.push_back(255);
	rgbaVector.push_back(255);
	rgbaVector.push_back(1);

	// putPixel(width, height, rgbaVector);
	drawLine(coordinatesVector, rgbaVector);

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
