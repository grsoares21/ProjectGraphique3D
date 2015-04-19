#include <iostream>
using namespace std;
#include "ears.h"

Ears::Ears()
{
}


void Ears::draw()
{
    glPushMatrix();

    glBegin(GL_TRIANGLES);

        glNormal3f(-0.9, 0.0, 1.5);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(1.5, 0.0, 0.9);
        glVertex3f(1.5, 1, 0.9);

        glNormal3f(0.0, -0.1, 0.0);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(1.5, 0.0, 0.9);
        glVertex3f(1.0, 0.0, 0.5);

        glNormal3f(0.05, 0.15, -0.25);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(1.0, 0.5, 0.5);
        glVertex3f(1.5, 1, 0.9);

    glEnd();

    glBegin(GL_QUADS);

        glNormal3f(0.4, 0.0, -0.5);
        glVertex3f(1.0, 0.5, 0.5);
        glVertex3f(1.0, 0.0, 0.5);
        glVertex3f(1.5, 0.0, 0.9);
        glVertex3f(1.5, 1, 0.9);


    glEnd();


    glBegin(GL_TRIANGLES);

        glNormal3f(-0.9, 0.0, -1.5);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(1.5, 0.0, -0.9);
        glVertex3f(1.5, 1, -0.9);

        glNormal3f(0.0, -0.1, 0.0);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(1.5, 0.0, -0.9);
        glVertex3f(1.0, 0.0, -0.5);

        glNormal3f(0.05, 0.15, 0.25);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(1.0, 0.5, -0.5);
        glVertex3f(1.5, 1, -0.9);

    glEnd();

    glBegin(GL_QUADS);

        glNormal3f(0.4, 0.0, 0.5);
        glVertex3f(1.0, 0.5, -0.5);
        glVertex3f(1.0, 0.0, -0.5);
        glVertex3f(1.5, 0.0, -0.9);
        glVertex3f(1.5, 1, -0.9);


    glEnd();


    glPopMatrix();
}


