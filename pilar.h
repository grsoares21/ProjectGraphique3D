#ifndef PILAR_H
#define PILAR_H


#include "renderable.h"
#ifndef __APPLE__
#include <GL/glut.h>
#else
#include <GLUT/glut.h>
#endif

#include "cylinder.h"
#include "torch.h"
#include "conicalFrustrum.h"

class Pilar : public Renderable
{
    // Attributes
private:
    Torch *torch;
//Constructor
public:
    Pilar(bool addTorch);

//Renderable Methods
public:
    void init(Viewer &);
    void draw();
    void animate();
    int size, thickness;
};

#endif 
