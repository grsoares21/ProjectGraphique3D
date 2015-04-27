#include "dragon.h"

#define deg2rad 0.017453

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
    rightWing->init(viewer);
    leftWing->init(viewer);
}


void Dragon::draw()
{
    glPushMatrix();

        glEnable(GL_NORMALIZE);


        if(animationStep < 15)
            glTranslatef(-2*animationStep, 0.0, 0.0);
        else if(animationStep >= 15 && animationStep < 37.5)
            glTranslatef(-30 - sin((animationStep-15)*4*deg2rad)*20, 0.0, sin((animationStep-15)*4*deg2rad)*30);
        else
            glTranslatef(-30 - sin(90*deg2rad)*20, 0.0, sin(90*deg2rad)*30);

        if(animationStep >= 15 && animationStep < 37.5)
            glRotatef((animationStep-15)*4, 0, 1, 0);
        else if(animationStep > 37.5)
            glRotatef(90, 0, 1, 0);

        glTranslatef(0, sin((-animationStep*2)+60)/3, 0);

        if(animationStep >= 40 && animationStep < 58)
            glTranslatef(0.0, (animationStep - 40), 0.0);
        else if(animationStep >= 58)
            glTranslatef(0.0, 18, 0.0);

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


        if(animationStep < 15)
            glTranslatef(-2*animationStep, 0.0, 0.0);
        else if(animationStep >= 15 && animationStep < 37.5)
            glTranslatef(-30 - sin((animationStep-15)*4*deg2rad)*20, 0.0, sin((animationStep-15)*4*deg2rad)*30);
        else
            glTranslatef(-30 - sin(90*deg2rad)*20, 0.0, sin(90*deg2rad)*30);

        if(animationStep >= 15 && animationStep < 37.5)
            glRotatef((animationStep-15)*4, 0, 1, 0);
        else if(animationStep > 37.5)
            glRotatef(90, 0, 1, 0);

        if(animationStep >= 40 && animationStep < 58)
            glTranslatef(0.0, (animationStep - 40), 0.0);
        else if(animationStep >= 58)
            glTranslatef(0.0, 18, 0.0);

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
