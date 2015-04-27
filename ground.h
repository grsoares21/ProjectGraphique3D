#ifndef GROUND_H
#define GROUND_H

#include "renderable.h"
#include "glCheck.h"
#include "texture.h"
#include "shader.h"

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
    Texture *texture;
    Shader *shader;
    GLint texture0, texcoord0;

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
