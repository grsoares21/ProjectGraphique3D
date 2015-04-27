#ifndef WING_H
#define WING_H

#include "glCheck.h"
#include "texture.h"
#include "shader.h"

#include<math.h>

#include "renderable.h"
#ifndef __APPLE__
#include <GL/glut.h>
#else
#include <GLUT/glut.h>
#endif

#include "cylinder.h"
#include "cube.h"

class Wing : public Renderable
{
//Components
private:
    float animationStep;

//Constructor
public:
    Wing();

//Renderable Methods
public:
    void draw();
    void animate(float animationStep);
    void init(Viewer &);
    Texture *texture;
    Shader *shader;

    GLint texture0;
    GLint texcoord0;
};


#endif // WING_H
