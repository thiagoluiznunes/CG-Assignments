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

	std::cout << "Type the coordinates height and width at sequences: " << '\n';
	std::cin >> height >> width;
	std::cout << "Type the color:" << '\n';
	std::cin >> red >> green >> blue >> alpha;

	std::vector<int> rgbaVector;
	rgbaVector.push_back(red);
	rgbaVector.push_back(green);
	rgbaVector.push_back(blue);
	rgbaVector.push_back(alpha);

	putPixel(height, width, rgbaVector);

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
