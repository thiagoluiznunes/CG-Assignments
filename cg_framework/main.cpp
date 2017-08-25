#include "main.h"
#include <vector>

//-----------------------------------------------------------------------------
void MyGlDraw(void)
{
	//*************************************************************************
	// Chame aqui as funções do mygl.h
	//*************************************************************************
	int red, green, blue, alpha;

	std::cout << "Do type the color:" << '\n';
	std::cin >> red >> green >> blue >> alpha;

	std::vector<int> rgbaVector;
	rgbaVector.push_back(red);
	rgbaVector.push_back(green);
	rgbaVector.push_back(blue);
	rgbaVector.push_back(alpha);

	printPixel(150, 50, rgbaVector);

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
