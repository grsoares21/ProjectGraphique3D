#ifndef WALL_H
#define WALL_H

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

#include <QGLViewer/vec.h>

class Wall : public Renderable
{
//Attributes
private:
    float Xsize, Ysize;
    GLuint loadTexture(const char *filename);
    Texture *texture;
    Shader *shader;
    GLint texture0, texcoord0;

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
