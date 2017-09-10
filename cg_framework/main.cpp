#include "main.h"
#include <vector>
#include "Vertex.h"
//-----------------------------------------------------------------------------
void MyGlDraw(void)
{
	//*************************************************************************
	// Chame aqui as funções do mygl.h
	//*************************************************************************

	int height, width;
	std::vector<int> rgbaVector;

	//RGBA Color
	rgbaVector.push_back(255);
	rgbaVector.push_back(0);
	rgbaVector.push_back(0);
	rgbaVector.push_back(1);

	//Triangle
	Vertex first(0,0,400,1);
	Vertex second(0,0,200,400);
	Vertex third(400,0,200,400);
	drawTriangle(first, second, third, rgbaVector);

	//All Quadrants

	std::vector<Vertex> array;

	Vertex _45(200,200,400,400);
	Vertex _90(200,200,201,400);
	Vertex _135(200,200,0,400);
	Vertex _180(200,200,0,201);
	Vertex _225(200,200,0,0);
	Vertex _270(200,0,201,200);
	Vertex _315(400,0,200,200);
	Vertex _360(200,200,400,201);

	array.push_back(_45);
	array.push_back(_90);
	array.push_back(_135);
	array.push_back(_180);
	array.push_back(_225);
	array.push_back(_270);
	array.push_back(_315);
	array.push_back(_360);

	// drawAllQuadrants(array, rgbaVector);
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
