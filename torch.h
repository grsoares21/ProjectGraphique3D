#ifndef TORCH_H
#define TORCH_H


#include "renderable.h"
#ifndef __APPLE__
#include <GL/glut.h>
#else
#include <GLUT/glut.h>
#endif

#include <QGLViewer/vec.h>
#include "cylinder.h"
#include "fire.h"

class Torch : public Renderable
{
//Attributes
private:
    float size;
    Fire *fire;
//Constructor
public:
    Torch(float s);

//Renderable Methods
public:
    void init(Viewer &);
    void draw();
    void animate();
};

#endif 
