#ifndef DRAGON_H
#define DRAGON_H

#include <math.h>

#include "renderable.h"
#ifndef __APPLE__
#include <GL/glut.h>
#else
#include <GLUT/glut.h>
#endif

#include "body.h"
#include "leg.h"
#include "tail.h"
#include "neck.h"

class Dragon : public Renderable
{
//Attributes
private:
    float animationStep;
//Components
private:
    Body *body;
    Neck *neck;
    Tail *tail;

    Leg *frontLeftLeg;
    Leg *frontRightLeg;
    Leg *backLeftLeg;
    Leg *backRightLeg;


//Constructor
public:
    Dragon();

//Renderable Methods
public:
    void init(Viewer &);
    void draw();
    void animate();
};

#endif // DRAGON_H
