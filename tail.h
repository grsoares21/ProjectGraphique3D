#ifndef TAIL_H
#define TAIL_H

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
};

#endif // TAIL_H
