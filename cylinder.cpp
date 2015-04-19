#include <math.h>
#include "cylinder.h"

#define PI 3.14159265

Cylinder::Cylinder(float cylHeight, float cylRadius)
{
    baseRadius = cylRadius;
    height = cylHeight;
}


void Cylinder::draw()
{
    glPushMatrix();

    glBegin(GL_TRIANGLE_FAN);

        glNormal3f(0.0, 1.0, 0.0);
        glVertex3f(0.0, height / 2, 0.0);
        //Top circle of the cylinder
        for(int i = 0; i <= 360; i+=6)
            glVertex3f(cos(i*PI/180) * baseRadius, height / 2, sin(i*PI/180) * baseRadius);

    glEnd();

    glBegin(GL_TRIANGLE_FAN);
        glNormal3f(0.0, -1.0, 0.0);
        glVertex3f(0.0, - (height / 2), 0.0);

        for(int i = 0; i <= 360; i+=6)
            glVertex3f(cos(i*PI/180) * baseRadius, - (height / 2), sin(i*PI/180) * baseRadius);

    glEnd();

    glBegin(GL_QUAD_STRIP);
        for(int i = 0; i <= 360; i+=6) {
            glNormal3f(cos(i*PI/180), 0.0, sin(i*PI/180));
            glVertex3f(cos(i*PI/180) * baseRadius, - (height / 2), sin(i*PI/180) * baseRadius);
            glVertex3f(cos(i*PI/180) * baseRadius, (height / 2), sin(i*PI/180) * baseRadius);
        }
    glEnd();

    glPopMatrix();
}
