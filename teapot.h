#ifndef TEAPOT_H
#define TEAPOT_H

#include "renderable.h"
#ifndef __APPLE__
#include <GL/glut.h>
#else
#include <GLUT/glut.h>
#endif

#include <QGLViewer/vec.h>
#include "cylinder.h"
#include "smoke.h"

class TeaPot : public Renderable
{
//Attributes
private:
    Smoke *smoke;
//Constructor
public:
    TeaPot();

//Renderable Methods
public:
    void init(Viewer &);
    void draw();
    void animate();
};

#endif // TEAPOT_H
