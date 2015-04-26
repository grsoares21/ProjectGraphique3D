#include "teapot.h"

TeaPot::TeaPot()
{
}

void TeaPot::init(Viewer &viewer)
{
    smoke = new Smoke(1);
    smoke->init(viewer);
}


void TeaPot::draw()
{
    glPushMatrix();
    glutSolidTeapot(1);
    glTranslatef(1.6f, 0.5f, 0);
    glRotatef(270, 0, 0, 1);
    glScalef(0.1f, 0.1f, 0.1f);
    smoke->draw();
    glPopMatrix();
}

void TeaPot::animate()
{
    smoke->animate();
}

