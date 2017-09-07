# CG-First-Task
---
Rasterization Algorithms

## Menu

* [Introduction](#introduction)
* [Points Rasterization](#points-rasterization)
* [Digital Differential Analyzer](#digital-differential-analyzer)
* [Bresenham Algorithm](#bresenham-algorithm)
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
The function above describes:
1. xWidth is the position of the pixel related the screen width.
2. yHeight is the position of the pixel related the screen height.
3. myRGBA is the color vector related the pixel.

The RGBA standard  to require four bytes. Each byte it is destined for the primaries color RGBA that mean RED, GREEN, BLUE and ALPHA. With this function we can draw a point on the screen like the below picture show it.

<p align="center">
	<br>
	<img src="./prints/putPixel.png"/ width=600px height=400px>
	<br>
</p>

---

### Lines Rasterization

#### Digital Differential Analyzer (DDA)
Digital Differential Analyzer (DDA) algorithm is the simple line generation algorithm.

Now let's look more close the DDA Algorithm. Below is the code at C++.
```C++
void ddaAlgorithm(int x1, int y1, int x2, int y2, std::vector<int>& myRGBA) {
  float dx = x2-x1;
  float dy = y2-y1;

  float m = dy/dx;
  float b = y1 - (m*x1);

  int j = 0;
  for (size_t i = 0; i < dx; i++) {
    colorInterpolation(i, &j, dx, &myRGBA);
    putPixel(x1+i, round(m*(x1+i)+b), myRGBA);
  }
}
```
The algorithm above describe:
1. dx is the variation/range between x2 and x1 points.
2. dy is the variation/range between y2 and y1 points.
3. m is the coefficient of the line. 
4. b is the linear coefficient of the line.

<p align="center">
	<br>
	<img src="./prints/lineDDA.png"/ width=510px height=540px>
	<br>
</p>

The image describes a line drawn on the screen using the DDA Algorithm. 

The DA Algorithm only draws in the first quadrant as you can see in the image below and is a problem if you want to draw on other areas of the screen. 

<p align="center">
	<br>
	<img src="./prints/interpolationDDA.png"/ width=510px height=540px>
	<br>
</p>

#### Bresenham Algorithm
The Bresenham algorithm is another incremental scan conversion algorithm. The big advantage of this algorithm is that, it uses only integer calculations. Moving across the x axis in unit intervals and at each step choose between two different y coordinates.

Now let's look more close the DDA Algorithm. Below is the code at C++.
```C++
void ddaAlgorithm(int x1, int y1, int x2, int y2, std::vector<int>& myRGBA) {
  float dx = x2-x1;
  float dy = y2-y1;

  float m = dy/dx;
  float b = y1 - (m*x1);

  int j = 0;
  for (size_t i = 0; i < dx; i++) {
    colorInterpolation(i, &j, dx, &myRGBA);
    putPixel(x1+i, round(m*(x1+i)+b), myRGBA);
  }
}
```
The algorithm above describe:
1. dx is the variation/range between x2 and x1 points.
2. dy is the variation/range between y2 and y1 points.
3. m is the coefficient of the line. 
4. b is the linear coefficient of the line.

<p align="center">
	<br>
	<img src="./prints/lineDDA.png"/ width=510px height=540px>
	<br>
</p>

The image describes a line drawn on the screen using the DDA Algorithm


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
