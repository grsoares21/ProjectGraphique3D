#ifndef BODY_H
#define BODY_H


#include "renderable.h"
#ifndef __APPLE__
#include <GL/glut.h>
#else
#include <GLUT/glut.h>
#endif

#include "cylinder.h"
#include "conicalFrustrum.h"

class Body : public Renderable
{
//Constructor
public:
    Body();

//Renderable Methods
public:
    void draw();
};

#endif // BODY_H
