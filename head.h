#ifndef HEAD_H
#define HEAD_H


#include "renderable.h"
#ifndef __APPLE__
#include <GL/glut.h>
#else
#include <GLUT/glut.h>
#endif

#include "ears.h"
#include "jaw.h"
#include "eyes.h"

class Head : public Renderable
{
//Components
private:
    Ears *ears;
    Jaw *jaw;
    Eyes *eyes;
    UpperTeeth *upperTeeth;
//Constructor
public:
    Head();
    virtual ~Head();

//Renderable Methods
public:
    void draw();

};

#endif // HEAD_H
