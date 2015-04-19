#ifndef TEETH_H
#define TEETH_H


#include "renderable.h"
#ifndef __APPLE__
#include <GL/glut.h>
#else
#include <GLUT/glut.h>
#endif


class LowerTeeth : public Renderable
{
//Constructor
public:
    LowerTeeth();
//Renderable Methods
public:
    void draw();
};




class UpperTeeth : public Renderable
{
//Constructor
public:
    UpperTeeth();
//Renderable Methods
public:
    void draw();
};

#endif // TEETH_H
