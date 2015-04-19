#include "leg.h"
Leg::Leg()
{
}


void Leg::draw()
{
    glPushMatrix();

    //Body joint
    glutSolidSphere(0.5, 50, 50);

    glRotatef(-40, 0, 0, 1);
    glTranslatef(0, -0.5, 0);

    //Upper leg
    ConicalFrustrum *conicalFrustrum = new ConicalFrustrum(0.5, 0.25, 1);
    conicalFrustrum->draw();

    free(conicalFrustrum);

    glTranslatef(0, -0.5, 0);

    //Knee
    glutSolidSphere(0.25, 50, 50);

    glRotatef(80, 0, 0, 1);
    glTranslatef(0, -0.375, 0);

    //Lower leg
    conicalFrustrum = new ConicalFrustrum(0.25, 0.125, 0.75);
    conicalFrustrum->draw();

    free(conicalFrustrum);

    //Foot Joint
    glTranslatef(0, -0.375, 0);
    glutSolidSphere(0.125, 50, 50);


    //Foot
    glRotatef(-30, 0, 0, 1);
    glTranslatef(-0.125, -0.125, 0);
    glScalef(2, 1, 1);

    glutSolidSphere(0.125, 50, 50);

    glScalef(0.5, 1, 1);


    glTranslatef(0.125, 0, 0);
    glRotatef(90, 0, 1, 0);

    //Back claw
    for(int i = 4; i > 0; i--)
    {
        glTranslatef(0.0, 0.0, 0.05);
        glRotatef(6,1,0,0);
        glutSolidCone(0.025*i, 0.1 + 0.025*i, 10, 10);
    }


    //Nails
    glRotatef(180, 0, 1, 0);
    glTranslatef(0, -0.175, 0.4);

    glTranslatef(0.06, 0, 0);
    glRotatef(30, 0, 1, 0);
    glutSolidCone(0.05, 0.25, 10, 10);

    glTranslatef(-0.06, 0, 0);
    glRotatef(-30, 0, 1, 0);
    glutSolidCone(0.05, 0.25, 10, 10);

    glTranslatef(-0.06, 0, 0);
    glRotatef(-30, 0, 1, 0);
    glutSolidCone(0.05, 0.25, 10, 10);



    glPopMatrix();
}
