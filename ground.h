#ifndef GROUND_H
#define GROUND_H

#include "renderable.h"
#include <QImage>
#ifndef __APPLE__
#include <GL/glut.h>
#else
#include <GLUT/glut.h>
#endif

class Ground : public Renderable
{
//Attributes
private:
    float Xsize, Zsize;
    GLuint loadTexture(const char *filename);
    GLuint textureRock;
    GLint texture0;
    GLint texcoord0;

//Constructor
public:
    Ground(float Xsize, float Zsize);

//Renderable Methods
public:
    void init(Viewer &);
    void draw();
    void animate();
};

#endif // GROUND_H
