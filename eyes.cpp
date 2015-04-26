#include "eyes.h"

//static vec4 mat_diffuse( 0.1f, 0.5f, 0.8f, 1.0f );

//static Material eyeMaterial()


Eyes::Eyes()
{
}


void Eyes::draw()
{
    glPushMatrix();


    glColor3f(1.0, 0, 0);
    glTranslatef(0.4, 0.1, -0.22);

    glutSolidSphere(0.05, 50, 50);

    glTranslatef(0, 0, 0.44);

    glutSolidSphere(0.05, 50, 50);
    glColor3f(1.0, 1.0, 1.0);
    glPopMatrix();
}
