#ifndef HEAD_H
#define HEAD_H

#include <math.h>
#include "ears.h"
#include "fire.h"
#include "jaw.h"
#include "eyes.h"

#include "renderable.h"
#ifndef __APPLE__
#include <GL/glut.h>
#else
#include <GLUT/glut.h>
#endif


class Head : public Renderable
{
//Attributes
private:
    float animationStep;
    GLint texture0;
    GLint texcoord0;
//Components
private:
    Ears *ears;
    Jaw *jaw;
    Eyes *eyes;
    UpperTeeth *upperTeeth;
    Texture *texture;
    Shader *shader;
    Fire *fire;
//Constructor
public:
    Head();
    virtual ~Head();

//Renderable Methods
public:
    void init(Viewer &);
    void draw();
    void animate(float animationStep);

};

#endif // HEAD_H
