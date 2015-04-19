#ifndef CYLINDER_H
#define CYLINDER_H

#include "renderable.h"
#ifndef __APPLE__
#include <GL/glut.h>
#else
#include <GLUT/glut.h>
#endif

class Cylinder : public Renderable
{
//Attributes
private:
    float height;
    float baseRadius;

//Constructor
public:
    Cylinder(float height, float baseRadius);

//Renderable Methods
public:
    void draw();
};

#endif // CYLINDER_H
