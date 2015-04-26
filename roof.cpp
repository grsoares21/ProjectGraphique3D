#include "roof.h"

Roof::Roof(float x, float z, float h)
{
    Xsize = x;
    Zsize = z;
    height = h;
}

void Roof::init(Viewer &viewer)
{
}


void Roof::draw()
{
    glPushMatrix();
    glBegin(GL_QUADS);
         glVertex3f(0, 0, height);
         glVertex3f(Xsize, 0, height);
         glVertex3f(Xsize, Zsize, height);
         glVertex3f(0, Zsize, height);
    glEnd();
    glPopMatrix();
}

void Roof::animate()
{

}
