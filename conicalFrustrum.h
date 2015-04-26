#ifndef CONICALFRUSTRUM_H
#define CONICALFRUSTRUM_H

#include "renderable.h"
#ifndef __APPLE__
#include <GL/glut.h>
#else
#include <GLUT/glut.h>
#endif

class ConicalFrustrum : public Renderable
{
//Attributes
private:
    float smallestRadius;
    float biggestRadius;
    float height;

//Constructor
public:
    ConicalFrustrum(float baseRadius, float topRadius, float frustrumHeight);

//Renderable Methods
public:
    void draw();

};

#endif // CONICALFRUSTRUM_H
