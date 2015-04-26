#include "wall.h"

Wall::Wall(float x, float y)
{
    Xsize = x;
    Ysize = y;
}

void Wall::init(Viewer &viewer)
{
}


void Wall::draw()
{
    glPushMatrix();
    glBegin(GL_QUADS);
         glVertex3f(0, 0, 0);
         glVertex3f(Xsize, 0, 0);
         glVertex3f(Xsize, 0, Ysize);
         glVertex3f(0, 0, Ysize);
    glEnd();
    glPopMatrix();
}

void Wall::animate()
{

}
