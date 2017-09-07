# CG-First-Task
---
Rasterization Algorithms

## Menu

* [Introduction](#introduction)
* [Points Rasterization](#points-rasterization)
* []()
* []()
* []()

---

## Introduction
This project has as objective the implementation of rasterization algorithms to perform the rendering of points and lines. The motivation for this task is to complement the note for the Computer Graphics discipline taught by the teacher Christian Pagot in Federal University of Paraiba.

---

### Points Rasterization
The main concept of the rasterization is the draw point function in a screen. Through this function you can be able to draw vector images. To realize this operation have must to activate the display pixels with specific colors to draw the image requested. The image below will to explain better how work the screen rasterization.

<p align="center">
	<br>
	<img src="./prints/matrix.png"/ width=600px height=400px>
	<br>
</p>

Now let's look more close the function destined to execute the point rasterization. Below is the code at C++.
```C++
void putPixel(int xWidth, int yHeight, std::vector<int>& myRGBA) {
	for (size_t i = 0; i < 4; i++) {
	FBptr[xWidth*4+i + yHeight*4*IMAGE_WIDTH] = myRGBA.at(i);
	}
}
```
The function above describe:
1. xWidth is the position of the pixel related the screen width.
2. yHeight is the position of the pixel related the screen height.
3. myRGBA is the color vector related the pixel.

The RGBA standard  to require four bytes. Each byte it is destined for the primaries color RGBA that mean RED, GREEN, BLUE and ALPHA. With this function we can draw a point in the screen like the below picture show it.



Toolkit: OpenGL | Glut | Computer Graphic | C++

## Requirements ###

* *[A Unix Environment](https://www.ubuntu.com/)** :white_check_mark:
* *[C++ Compiler with support for standard C11]()** :white_check_mark:

## Build Instructions ###

**Obs.: The following instructions were tested on Ubuntu distribution.**

1. Clone de project.

2. Move to the desired project

3. Invoke the makefile

```
$> git clone https://github.com/ThiagoLuizNunes/CG-Assignments.git
$> cd cg-framework
$> make 
```

## Execution Instructions ##
* In the cg-framework.
* Run the created executable file.

```
$> ./cg-task
```

## Contributors

* Thiago Luiz Pereira Nunes ([ThiagoLuizNunes](https://github.com/ThiagoLuizNunes)) thiago.luiz@lavid.ufpb.br

>Created By **[ThiagoLuizNunes](https://www.linkedin.com/in/thiago-luiz-507483112/)** 2017.

---
