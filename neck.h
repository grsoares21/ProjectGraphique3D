#ifndef NECK_H
#define NECK_H

#include "renderable.h"
#ifndef __APPLE__
#include <GL/glut.h>
#else
#include <GLUT/glut.h>
#endif

#include "head.h"
#include "cylinder.h"
#include "cube.h"

class Neck : public Renderable
{
//Components
private:
    Head *head;

//Constructor
public:
    Neck();

//Renderable Methods
public:
    void draw();
};

#endif // NECK_H
