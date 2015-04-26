#include "dragon.h"

Dragon::Dragon()
{
    animationStep = 0;

    body = new Body();
    neck = new Neck();
    tail = new Tail();
    rightWing = new Wing();
    leftWing = new Wing();
    frontLeftLeg = new Leg();
    frontRightLeg = new Leg();
    backLeftLeg = new Leg();
    backRightLeg = new Leg();

}


void Dragon::init(Viewer &viewer)
{
    neck->init(viewer);
}


void Dragon::draw()
{
    glPushMatrix();

        glEnable(GL_NORMALIZE);

        glTranslatef(0, sin((-animationStep*2)+60)/3, 0);
        body->draw();

        glColor3f(0.0, 0.1, 0.0);
        glTranslatef(-2.5, -1, 1.0);
        glRotatef(40*(sin(-animationStep)+0.3), 0, 0, 1);
        glScalef(2, 2, 2);
        frontLeftLeg->draw();
        glScalef(0.5, 0.5, 0.5);
        glRotatef(-40*(sin(-animationStep)+0.3), 0, 0, 1);
        glTranslatef(2.5, 1, -1.0);


        glTranslatef(-2.5, -1, -1.0);
        glRotatef(40*(sin(-animationStep+180)+0.3), 0, 0, 1);
        glScalef(2, 2, 2);
        frontRightLeg->draw();
        glScalef(0.5, 0.5, 0.5);
        glRotatef(-40*(sin(-animationStep+180)+0.3), 0, 0, 1);
        glTranslatef(2.5, 1, 1.0);

        glTranslatef(2.5, -1, 1.0);
        glRotatef(40*(sin(-animationStep+180)+0.3), 0, 0, 1);
        glScalef(2, 2, 2);
        backLeftLeg->draw();
        glScalef(0.5, 0.5, 0.5);
        glRotatef(-40*(sin(-animationStep+180)+0.3), 0, 0, 1);
        glTranslatef(-2.5, 1, -1.0);

        glTranslatef(2.5, -1, -1.0);
        glRotatef(40*(sin(-animationStep)+0.3), 0, 0, 1);
        glScalef(2, 2, 2);
        backRightLeg->draw();
        glScalef(0.5, 0.5, 0.5);
        glRotatef(-40*(sin(-animationStep)+0.3), 0, 0, 1);
        glTranslatef(-2.5, 1, 1.0);
        glColor3f(1.0, 1.0, 1.0);

        glTranslatef(3.5, -1, 0);
        glRotatef(90, 0, 1, 0);
        glRotatef(40, 1, 0, 0);
        tail->draw();
        glRotatef(-40, 1, 0, 0);
        glRotatef(-90, 0, 1, 0);
        glTranslatef(-3, 0.5, 0);

        glTranslatef(-3.2, 1.2, 0);
        glScalef(2, 1.3, 2);
        neck->draw();
        glScalef(0.5, 1/1.3, 0.5);
        glTranslatef(0, 0.6, 0.7);

    glPopMatrix();
    glPushMatrix();
        glRotatef(270, 0, 1, 0);

        glTranslatef(1, 1, 2.5);
        rightWing->draw();
        glTranslatef(-2, 0, 0);
        glScalef(-1, 1, 1);
        leftWing->draw();

    glPopMatrix();
}

void Dragon::animate()
{
    animationStep += 0.2;

    frontLeftLeg->animate(animationStep-180);
    frontRightLeg->animate(animationStep+180);
    backLeftLeg->animate(animationStep+180);
    backRightLeg->animate(animationStep-180);
    rightWing->animate(animationStep);
    leftWing->animate(animationStep);
    neck->animate(animationStep);

    tail->animate(animationStep);
}
