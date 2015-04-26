#include "ground.h"

Ground::Ground(float x, float z)
{
    Xsize = x;
    Zsize = z;
}

void Ground::init(Viewer &viewer)
{
}


void Ground::draw()
{

    glNormal3f(0.0, 0.0, 1.0);
    glPushMatrix();
    glBegin(GL_QUADS);
        glVertex3f(0, 0, 0);
         glVertex3f(Xsize, 0, 0);
        glVertex3f(Xsize, Zsize, 0);
         glVertex3f(0, Zsize, 0);
    glEnd();
    glPopMatrix();
}

void Ground::animate()
{

}
