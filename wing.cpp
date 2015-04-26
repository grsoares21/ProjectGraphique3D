#include "wing.h"


Wing::Wing()
{


}

void Wing::init(Viewer &viewer)
{

}

void Wing::draw()
{
    glPushMatrix();

    float curvature = sin(animationStep);
/*
    glRotatef(curvature*30, 0, 0, 1);
    glRotatef(90, 0, 0.3, 1);
    glTranslatef(0, -3, 0);
    Cylinder *cylinder = new Cylinder(6, 0.2);
    cylinder->draw();

    glTranslatef(0, -3, 0);
    glRotatef(-30, 1, 0, 0);
    glTranslatef(0, -3, 0);
    Cylinder *cylinder2 = new Cylinder(6, 0.2);
    cylinder2->draw();

    glTranslatef(0, -3, 0);
    glRotatef(-30, 1, 0, 0);
    glTranslatef(0, -3, 0);
    Cylinder *cylinder3 = new Cylinder(6, 0.2);
    cylinder3->draw();

    glTranslatef(0, -3, 0);
    glRotatef(-30, 1, 0, 0);
    glTranslatef(0, -3, 0);
    Cylinder *cylinder4 = new Cylinder(6, 0.2);
    cylinder4->draw();

    glTranslatef(0, -3, 0);
    glRotatef(230, 1, 0, 0);
    glTranslatef(0, -5, 0);
    Cylinder *cylinder5 = new Cylinder(10, 0.2);
    cylinder5->draw();

    glTranslatef(0, -5, 0);
    glRotatef(60, 1, 0.6, 0);
    glTranslatef(0, -5, 0);
    Cylinder *cylinder6 = new Cylinder(10, 0.2);
    cylinder6->draw();

    glPopMatrix();
    glPushMatrix();

    GLfloat matrix[16];

    glBegin(GL_POLYGON);

    glGetFloatv (GL_MODELVIEW_MATRIX, matrix);

    glVertex3f( 0,0,0 );
    glVertex3f( 1,0,0 );
    glVertex3f( 1,1,0 );
    glVertex3f( 0,1,0 );

    glEnd();
 */

    glBegin(GL_POLYGON);
    glNormal3f(0.0, 1.0, 0.0);

    glVertex3f( 0, 0.1, 0 );
    glVertex3f( 4, 0.1+curvature*1, 2 );
    glVertex3f( 9, 0.1+curvature*3, 0 );
    glVertex3f( 11, 0.1+curvature*8, -4 );
    glVertex3f( 12, 0.1+curvature*11, -7 );
    glVertex3f( 5, 0.1+curvature*5, -4 );
    glVertex3f( 0, 0.1, -6 );

    glEnd();

    glBegin(GL_POLYGON);
    glNormal3f(0.0, -1.0, 0.0);

    glVertex3f( 0, 0, 0 );
    glVertex3f( 4, curvature*1, 2 );
    glVertex3f( 9, curvature*3, 0 );
    glVertex3f( 11, curvature*8, -4 );
    glVertex3f( 12, curvature*11, -7 );
    glVertex3f( 5, curvature*5, -4 );
    glVertex3f( 0, 0, -6 );

    glEnd();


    glPopMatrix();

}

void Wing::animate(float animationStep)
{
    this->animationStep = animationStep;
}
