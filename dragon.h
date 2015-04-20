#ifndef DRAGON_H
#define DRAGON_H

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
    void draw();
};

#endif // DRAGON_H
