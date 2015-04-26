#ifndef EARS_H
#define EARS_H

#include "glCheck.h"
#include "texture.h"
#include "shader.h"
#include <string>

#include "renderable.h"
#ifndef __APPLE__
#include <GL/glut.h>
#else
#include <GLUT/glut.h>
#endif



class Ears : public Renderable
{
//Constructor
public:
    Ears();

//Renderable Methods
public:
    void init(Viewer &);
    void draw();
    Texture *texture;
    Shader *shader;

    GLint texture0;
    GLint texcoord0;
};

#endif // EARS_H
