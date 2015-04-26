#ifndef JAW_H
#define JAW_H

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

#include "teeth.h"

class Jaw : public Renderable
{
//Components
private:
    LowerTeeth  *teeth;
//Constructor
public:
    Jaw();

//Renderable Methods
public:
    void init(Viewer &);
    void draw();
    Texture *texture;
    Shader *shader;

    GLint texture0;
    GLint texcoord0;

};

#endif // JAW_H
