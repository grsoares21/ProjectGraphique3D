#include "teeth.h"

LowerTeeth::LowerTeeth()
{
}

void LowerTeeth::draw()
{
    glPushMatrix();

    glColor3f(1.0,1.0,1.0);
    glTranslatef(-1, 0, 0);
    glRotatef(27.5,0,0,1);
    glTranslatef(0.8, -0.85, 0);
    for(float i = 0.9; i > 0.1; i -= 0.1)
    {
        glTranslatef(i, -0.1, -(i*0.5)+0.1);
        glRotatef(-90,1,0,0);

        glutSolidCone(0.05,0.1, 20, 20);

        glRotatef(90,1,0,0);
        glTranslatef(-i, 0.1, (i*0.5)-0.1);
    }

    for(float i = 0.9; i > 0.2; i -= 0.1)
    {
        glTranslatef(i, -0.1, (i*0.5)-0.1);
        glRotatef(-90,1,0,0);

        glutSolidCone(0.05,0.1, 20, 20);

        glRotatef(90,1,0,0);
        glTranslatef(-i, 0.1, -(i*0.5)+0.1);
    }


    glPopMatrix();

}


UpperTeeth::UpperTeeth()
{
}

void UpperTeeth::draw()
{
    glPushMatrix();

    glTranslatef(0, 0.1, 0);

    for(float i = 0.9; i > 0.1; i -= 0.1)
    {
        glTranslatef(i, -0.1, -(i*0.5)+0.1);
        glRotatef(90,1,0,0);

        glutSolidCone(0.05,0.1, 20, 20);

        glRotatef(-90,1,0,0);
        glTranslatef(-i, 0.1, (i*0.5)-0.1);
    }

    for(float i = 0.9; i > 0.2; i -= 0.1)
    {
        glTranslatef(i, -0.1, (i*0.5)-0.1);
        glRotatef(90,1,0,0);

        glutSolidCone(0.05,0.1, 20, 20);

        glRotatef(-90,1,0,0);
        glTranslatef(-i, 0.1, -(i*0.5)+0.1);
    }


    glPopMatrix();

}

