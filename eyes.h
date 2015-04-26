#ifndef EYES_H
#define EYES_H


#include "renderable.h"
#ifndef __APPLE__
#include <GL/glut.h>
#else
#include <GLUT/glut.h>
#endif


class Eyes : public Renderable
{
//Constructor
public:
    Eyes();

//Renderable Methods
public:
    void draw();
};

#endif // EYES_H
