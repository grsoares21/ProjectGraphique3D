#ifndef TAIL_H
#define TAIL_H

#include <math.h>

#include "renderable.h"
#ifndef __APPLE__
#include <GL/glut.h>
#else
#include <GLUT/glut.h>
#endif

#include "conicalFrustrum.h"

class Tail : public Renderable
{
//Constructor
public:
    Tail();

//Renderable Methods
public:
    void draw();
    void animate(float animationStep);

//Attributes
private:
    float animationStep;
};

#endif // TAIL_H
