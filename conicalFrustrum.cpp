#include "conicalFrustrum.h"
#include <math.h>

#define PI 3.14159265

ConicalFrustrum::ConicalFrustrum(float baseRadius, float topRadius, float frustrumHeight)
{
    biggestRadius = baseRadius;
    smallestRadius = topRadius;
    height = frustrumHeight;
}

void ConicalFrustrum::draw()
{
    glPushMatrix();

    glBegin(GL_TRIANGLE_FAN);

        glNormal3f(0.0, 1.0, 0.0);
        glVertex3f(0.0, height / 2, 0.0);
        //Top circle of the cylinder
        for(int i = 0; i <= 360; i+=6)
            glVertex3f(cos(i*PI/180) * biggestRadius, height / 2, sin(i*PI/180) * biggestRadius);

    glEnd();

    glBegin(GL_TRIANGLE_FAN);
        glNormal3f(0.0, -1.0, 0.0);
        glVertex3f(0.0, - (height / 2), 0.0);

        for(int i = 0; i <= 360; i+=6)
            glVertex3f(cos(i*PI/180) * smallestRadius, - (height / 2), sin(i*PI/180) * smallestRadius);

    glEnd();

    glBegin(GL_QUAD_STRIP);
        for(int i = 0; i <= 360; i+=6) {

            glNormal3f(cos(i*PI/180) * (biggestRadius), tan((PI/2/180) - atan((biggestRadius - smallestRadius)/height)), sin(i*PI/180) * (biggestRadius));
            glVertex3f(cos(i*PI/180) * smallestRadius, - (height / 2), sin(i*PI/180) * smallestRadius);
            glVertex3f(cos(i*PI/180) * biggestRadius, (height / 2), sin(i*PI/180) * biggestRadius);
        }
    glEnd();

    glPopMatrix();
}
