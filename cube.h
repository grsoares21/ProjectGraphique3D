#ifndef _CUBE_
#define _CUBE_

#include "renderable.h"
#ifndef __APPLE__
#include <GL/glut.h>
#else
#include <GLUT/glut.h>
#endif

class Cube : public Renderable
{
//Attributes
private:
    float size;

//Constructor
public:
    Cube(float sideSize);

//Renderable Methods
public:
	void draw();

};

#endif

