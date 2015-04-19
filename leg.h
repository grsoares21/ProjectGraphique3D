#ifndef LEG_H
#define LEG_H

#include "renderable.h"
#ifndef __APPLE__
#include <GL/glut.h>
#else
#include <GLUT/glut.h>
#endif

#include "conicalFrustrum.h"

class Leg : public Renderable
{
//Constructor
public:
    Leg();

//Renderable Methods
public:
    void draw();
};

#endif // LEG_H
