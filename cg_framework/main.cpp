#include "main.h"
#include <vector>
#include "Vertex.h"
// #include "Color.h"
//-----------------------------------------------------------------------------
void MyGlDraw(void)
{
	//*************************************************************************
	// Chame aqui as funções do mygl.h
	//*************************************************************************

	int height, width;
	int red, green, blue, alpha;
	std::vector<int> rgbaVector;

	Vertex first(0,0,400,1);
	Vertex second(0,0,200,400);
	Vertex third(400,0,200,400);

	rgbaVector.push_back(255);
	rgbaVector.push_back(0);
	rgbaVector.push_back(0);
	rgbaVector.push_back(1);

	// bresenhamAlgorithm(first, rgbaVector);
	// bresenhamAlgorithm(second, rgbaVector);
	// bresenhamAlgorithm(third, rgbaVector);
	drawTriangle(first, second, third, rgbaVector);

	// ddaAlgorithm(first, rgbaVector);
	//int j;
	// for (size_t i = 0; i < 500; i++) {
	// 	coordinatesVector.at(2) = 500-i;
	// 	// ddaAlgorithm(coordinatesVector, rgbaVector);
	// 	// bresenhamAlgorithm(coordinatesVector, rgbaVector);
	// }
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
