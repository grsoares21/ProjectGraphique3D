#ifndef EARS_H
#define EARS_H

#include "renderable.h"
#ifndef __APPLE__
#include <GL/glut.h>
#else
#include <GLUT/glut.h>
#endif


class Ears : public Renderable
{
//Constructor
public:
    Ears();

//Renderable Methods
public:
    void draw();

};

#endif // EARS_H
