#ifndef NECK_H
#define NECK_H

#include<math.h>

#include "head.h"

#include "renderable.h"
#ifndef __APPLE__
#include <GL/glut.h>
#else
#include <GLUT/glut.h>
#endif

#include <math.h>
#include "cylinder.h"
#include "cube.h"
#include "chain.h"

class Neck : public Renderable
{
//Components
private:
    float animationStep;
    Head *head;
    Chain *chain;

//Constructor
public:
    Neck();

//Renderable Methods
public:
    void draw();
    void animate(float animationStep);
    void init(Viewer &);
};

#endif // NECK_H
