#include "dragon.h"

Dragon::Dragon()
{
    body = new Body();
    neck = new Neck();
    tail = new Tail();

    frontLeftLeg = new Leg();
    frontRightLeg = new Leg();
    backLeftLeg = new Leg();
    backRightLeg = new Leg();

}



void Dragon::draw()
{
    glPushMatrix();

        glEnable(GL_NORMALIZE);

        body->draw();

        glTranslatef(-2.5, -1, 1.0);
        glScalef(2, 2, 2);
        frontLeftLeg->draw();
        glScalef(0.5, 0.5, 0.5);
        glTranslatef(2.5, 1, -1.0);

        glTranslatef(-2.5, -1, -1.0);
        glScalef(2, 2, 2);
        frontRightLeg->draw();
        glScalef(0.5, 0.5, 0.5);
        glTranslatef(2.5, 1, 1.0);

        glTranslatef(2.5, -1, 1.0);
        glScalef(2, 2, 2);
        backLeftLeg->draw();
        glScalef(0.5, 0.5, 0.5);
        glTranslatef(-2.5, 1, -1.0);

        glTranslatef(2.5, -1, -1.0);
        glScalef(2, 2, 2);
        backRightLeg->draw();
        glScalef(0.5, 0.5, 0.5);
        glTranslatef(-2.5, 1, 1.0);

        glTranslatef(3, -0.5, 0);
        glRotatef(90, 0, 1, 0);
        glRotatef(40, 1, 0, 0);
        tail->draw();
        glRotatef(-40, 1, 0, 0);
        glRotatef(-90, 0, 1, 0);
        glTranslatef(-3, 0.5, 0);

        glTranslatef(-3.2, 1.2, 0);
        glScalef(2, 1.3, 2);
        neck->draw();
        glScalef(1/2, 1/1.3, 1/2);
        glTranslatef(3.2, -1.2, 0);

    glPopMatrix();
}
