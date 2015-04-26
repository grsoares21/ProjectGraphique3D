#include <iostream>
using namespace std;
#include "head.h"

Head::Head()
{
    ears = new Ears();
    jaw = new Jaw();
    eyes = new Eyes();
    upperTeeth = new UpperTeeth();
}


void Head::draw()
{
        glPushMatrix();

        glTranslatef(-0.5, 0, 0);
        glEnable(GL_NORMALIZE);

        ears->draw();

        glPushMatrix();

        glTranslatef(1, 0, 0);
        glRotatef(-sin(animationStep)*25,0,0,1); // <- relative angle to animate
        glTranslatef(-1, 0, 0);

        jaw->draw();

        glPopMatrix();

        upperTeeth->draw();

        eyes->draw();

        //Draw base format of the skull
        glBegin(GL_TRIANGLES);


           glNormal3f(-0.25, 0.0, 0.5);
           glVertex3f(0.0, 0.0, 0.0);
           glVertex3f(1.0, 0.0, 0.5);
           glVertex3f(1.0, 0.5, 0.5);

           glNormal3f(-0.5, 1.0, 0.0);
           glVertex3f(0.0, 0.0, 0.0);
           glVertex3f(1.0, 0.5, -0.5);
           glVertex3f(1.0, 0.5, 0.5);

           glNormal3f(-0.25, 0.0, -0.5);
           glVertex3f(0.0, 0.0, 0.0);
           glVertex3f(1.0, 0.5, -0.5);
           glVertex3f(1.0, 0, -0.5);

           glNormal3f(0.0, -1.0, 0.0);
           glVertex3f(0.0, 0.0, 0.0);
           glVertex3f(1.0, 0, 0.5);
           glVertex3f(1.0, 0, -0.5);

        glEnd();

        glBegin(GL_QUADS);

            glNormal3f(1.0, 0.0, 0.0);
            glVertex3f(1.0, 0.5, 0.5);
            glVertex3f(1.0, 0, 0.5);
            glVertex3f(1.0, 0, -0.5);
            glVertex3f(1.0, 0.5, -0.5);

        glEnd();

        glPopMatrix();
}

void Head::animate(float animationStep)
{
    this->animationStep = animationStep;
}


Head::~Head()
{
    free(ears);
    free(eyes);
    free(jaw);
    free(upperTeeth);
}
