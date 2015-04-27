#include "neck.h"

#define deg2rad 0.017453

Neck::Neck()
{
    head = new Head();
    chain = new Chain();
}

void Neck::init(Viewer &viewer)
{
    chain->init(viewer);
    head->init(viewer);
}

void Neck::draw()
{
    glPushMatrix();


    float neckCurvature = 4;

    if(animationStep > 58 && animationStep < 64)
        neckCurvature = 4 + (sin((animationStep-58)*deg2rad*20)) * 7;
    else if(animationStep >= 64 && animationStep < 80)
        neckCurvature = 11;
    else if(animationStep >= 80 && animationStep < 86)
        neckCurvature = 4 + (sin((animationStep-58)*deg2rad*20)) * 7;
    else
        neckCurvature = 4 + sin(animationStep) * 2;

    for(int i = 0; i < 6; i++)
    {
         glColor3f(0.0, 0.3 + i * (0.7/20), 0.0);
        glutSolidSphere(0.3, 30, 30);
        glTranslatef(0, 0.25, 0);
        Cylinder *cylinder = new Cylinder(0.5, 0.3);
        cylinder->draw();
        glTranslatef(0, 0.25, 0);
        glRotatef(neckCurvature, 0, 0, 1);
    }

    glutSolidSphere(0.3, 30, 30);
    glRotatef(-6*neckCurvature, 0, 0, 1);
    chain->draw();
    glTranslatef(-0.65, 0, 0);
    head->draw();
    glColor3f(1,1,1);
    glPopMatrix();
}

void Neck::animate(float animationStep)
{
    this->animationStep = animationStep;
    head->animate(animationStep);
    chain->animate();
}
