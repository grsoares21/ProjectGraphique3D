#include "jaw.h"

Jaw::Jaw()
{
    teeth = new LowerTeeth();
}

void Jaw::draw()
{
    glPushMatrix();

    teeth->draw();

    glBegin(GL_TRIANGLES);

        glNormal3f(-0.5, 1.0, 0.0);
        glVertex3f(0.0, -0.5, 0.0);
        glVertex3f(1.0, 0.0, 0.5);
        glVertex3f(1.0, 0.0, -0.5);

        glNormal3f(-0.05, 0, -0.1);
        glVertex3f(0.0, -0.5, 0.0);
        glVertex3f(0.2, -0.6, -0.1);
        glVertex3f(0.0, -1.0, 0.0);

        glNormal3f(-0.05, 0, 0.1);
        glVertex3f(0.0, -0.5, 0.0);
        glVertex3f(0.2, -0.6, 0.1);
        glVertex3f(0.0, -1.0, 0.0);

        glNormal3f(0.08, -0.04, 0);
        glVertex3f(0.2, -0.6, -0.1);
        glVertex3f(0.2, -0.6, 0.1);
        glVertex3f(0.0, -1.0, 0.0);

    glEnd();

    glBegin(GL_QUADS);

        glNormal3f(-0.1, 0, -0.2);
        glVertex3f(1.0, 0.0, -0.5);
        glVertex3f(1.0, -0.2, -0.5);
        glVertex3f(0.2, -0.6, -0.1);
        glVertex3f(0.0, -0.5, 0.0);

        glNormal3f(-0.1, 0, 0.2);
        glVertex3f(1.0, 0.0, 0.5);
        glVertex3f(1.0, -0.2, 0.5);
        glVertex3f(0.2, -0.6, 0.1);
        glVertex3f(0.0, -0.5, 0.0);

        glNormal3f(1, 0, 0);
        glVertex3f(1.0, 0.0, -0.5);
        glVertex3f(1.0, 0.0, 0.5);
        glVertex3f(1.0, -0.2, 0.5);
        glVertex3f(1.0, -0.2, -0.5);

        glNormal3f(0.5, -1.0, 0.0);
        glVertex3f(1.0, -0.2, 0.5);
        glVertex3f(1.0, -0.2, -0.5);
        glVertex3f(0.2, -0.6, -0.1);
        glVertex3f(0.2, -0.6, 0.1);

    glEnd();

    glPopMatrix();
}

