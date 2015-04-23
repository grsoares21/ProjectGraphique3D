#ifndef LEG_H
#define LEG_H

#include <math.h>

#include "renderable.h"
#ifndef __APPLE__
#include <GL/glut.h>
#else
#include <GLUT/glut.h>
#endif

#include "conicalFrustrum.h"

class Leg : public Renderable
{
//Attributes
private:
    float animationStep;

//Constructor
public:
    Leg();

//Renderable Methods
public:
    void draw();
    void animate(float animationStep);
};

#endif // LEG_H
