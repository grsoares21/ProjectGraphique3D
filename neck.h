#ifndef NECK_H
#define NECK_H

#include<math.h>

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
    float animationStep;
    Head *head;

//Constructor
public:
    Neck();

//Renderable Methods
public:
    void draw();
    void animate(float animationStep);
};

#endif // NECK_H
