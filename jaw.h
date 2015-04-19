#ifndef JAW_H
#define JAW_H


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
    void draw();
};

#endif // JAW_H
