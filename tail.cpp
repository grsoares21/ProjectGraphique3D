#include "tail.h"

Tail::Tail()
{
}


void Tail::draw()
{
    glPushMatrix();

    float tailCurvature = 3 + sin(animationStep); // <-- value to change to animate
    float tailLength = 6;
    float tailThickness = 1.6;

    for(int i = 0; i < 20; i++)
    {
        glColor3f(0.0, 0.3 + i * (0.7/20), 0.0);
        ConicalFrustrum *conicalFrustrum = new ConicalFrustrum(tailThickness-((tailThickness/20)*i),(tailThickness-((tailThickness/20)*i)) / 2, tailLength / 2);
        //glutSolidCone((tailThickness-((tailThickness/20)*i)), tailLength, 20, 20);
        glRotatef(-90, 1, 0, 0);
        conicalFrustrum->draw();
        glRotatef(90, 1, 0, 0);
        free(conicalFrustrum);
        glTranslatef(0, 0, tailLength/20);
        glRotatef(-tailCurvature, 1, 0, 0);
    }

    glColor3f(1.0, 1.0, 1.0);

    glPopMatrix();
}

void Tail::animate(float animationStep)
{
    this->animationStep = animationStep;
}
