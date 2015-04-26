#include "body.h"

Body::Body()
{
}


void Body::draw()
{
    glPushMatrix();


    glTranslatef(1, 0, 0);

    glRotatef(-90, 0, 0, 1);

    glColor3f(0.0, 0.3, 0.0);
    ConicalFrustrum *conicalFrustrum = new ConicalFrustrum(2, 1.5, 2);
    conicalFrustrum->draw();

    glRotatef(90, 0, 0, 1);

    glTranslatef(1, 0, 0);

    glutSolidSphere(2, 50, 50);

    glTranslatef(-3, 0, 0);

    glRotatef(90, 0, 0, 1);

    free(conicalFrustrum);

    conicalFrustrum = new ConicalFrustrum(2, 1.5, 2);
    conicalFrustrum->draw();

    glRotatef(-90, 0, 0, 1);

    glTranslatef(-1, 0, 0);

    glutSolidSphere(2, 50, 50);

    free(conicalFrustrum);

    glColor3f(1.0, 1.0, 1.0);
    glPopMatrix();
}
