#ifndef WALL_H
#define WALL_H

#include "renderable.h"
#ifndef __APPLE__
#include <GL/glut.h>
#else
#include <GLUT/glut.h>
#endif

#include <QGLViewer/vec.h>

class Wall : public Renderable
{
//Attributes
private:
    float Xsize, Ysize;
//Constructor
public:
    Wall(float Xsize, float Ysize);

//Renderable Methods
public:
    void init(Viewer &);
    void draw();
    void animate();
};

#endif // WALL_H
