#ifndef PILAR_H
#define PILAR_H


#include "renderable.h"
#ifndef __APPLE__
#include <GL/glut.h>
#else
#include <GLUT/glut.h>
#endif

#include "cylinder.h"
#include "conicalFrustrum.h"

class Pilar : public Renderable
{
//Constructor
public:
    Pilar();

//Renderable Methods
public:
    void draw();
    int size, thickness;
};

#endif 
