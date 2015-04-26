#ifndef WING_H
#define WING_H

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
};


#endif // WING_H
