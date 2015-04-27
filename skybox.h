#ifndef SKYBOX_H
#define SKYBOX_H

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

class Skybox : public Renderable
{
//Attributes
private:
    Texture *texture;
    Shader *shader;
    GLint texture0, texcoord0;

//Constructor
public:
    Skybox();

//Renderable Methods
public:
    void init(Viewer &);
    void draw();
    void animate();
};


#endif // SKYBOX_H
