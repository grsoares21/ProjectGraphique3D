#ifndef ROOF_H
#define ROOF_H

#include "renderable.h"
#ifndef __APPLE__
#include <GL/glut.h>
#else
#include <GLUT/glut.h>
#endif

#include <QGLViewer/vec.h>

class Roof : public Renderable
{
//Attributes
private:
    float Xsize, Zsize, height;
//Constructor
public:
    Roof(float Xsize, float Zsize, float height);

//Renderable Methods
public:
    void init(Viewer &);
    void draw();
    void animate();
};
#endif // ROOF_H
