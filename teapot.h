#ifndef TEAPOT_H
#define TEAPOT_H

#include "renderable.h"
#ifndef __APPLE__
#include <GL/glut.h>
#else
#include <GLUT/glut.h>
#endif

#include <QGLViewer/vec.h>
#include "smoke.h"

class TeaPot : public Renderable
{
//Attributes
private:
    Smoke *smoke;
    float animationStep;
//Constructor
public:
    TeaPot();

//Renderable Methods
public:
    void init(Viewer &);
    void draw();
    void animate(float step);
};

#endif // TEAPOT_H
