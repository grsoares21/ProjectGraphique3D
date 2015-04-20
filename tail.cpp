#include "tail.h"

Tail::Tail()
{
}


void Tail::draw()
{
    glPushMatrix();

    int tailCurvature = 3; // <-- value to change to animate


    for(int i = 0; i < 20; i++)
    {
        glutSolidCone(1.6-(i*0.07), 1.8, 20, 20);
        glTranslatef(0, 0, 0.3);
        glRotatef(-tailCurvature, 1, 0, 0);
    }


    glPopMatrix();
}
