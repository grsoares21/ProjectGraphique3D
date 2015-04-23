#include "neck.h"

Neck::Neck()
{
    head = new Head();
}

void Neck::draw()
{
    glPushMatrix();

    float neckCurvature = 8 - (sin(animationStep)) * 4;

    for(int i = 0; i < 6; i++)
    {
        glutSolidSphere(0.3, 30, 30);
        glTranslatef(0, 0.25, 0);
        Cylinder *cylinder = new Cylinder(0.5, 0.3);
        cylinder->draw();
        glTranslatef(0, 0.25, 0);
        glRotatef(neckCurvature, 0, 0, 1);
    }

    glutSolidSphere(0.3, 30, 30);
    glRotatef(-6*neckCurvature, 0, 0, 1);


    glTranslatef(-0.65, 0, 0);
    head->draw();
    glPopMatrix();
}

void Neck::animate(float animationStep)
{
    this->animationStep = animationStep;
    head->animate(animationStep);
}
