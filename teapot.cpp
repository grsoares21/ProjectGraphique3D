#include "teapot.h"

TeaPot::TeaPot()
{
}

void TeaPot::init(Viewer &viewer)
{
    smoke = new Smoke(1.0);
    smoke->init(viewer);
}


void TeaPot::draw()
{
    glPushMatrix();
    glutSolidTeapot(1);
    if (this->animationStep > 68){
        glTranslatef(1.6f, 0.5f, 0);
        glRotatef(270, 0, 0, 1);
        glScalef(0.1f, 0.1f, 0.1f);
        smoke->draw();
    }
    glPopMatrix();
}

void TeaPot::animate(float step)
{
    this->animationStep = step;
    smoke->animate();
}

