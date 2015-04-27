#include "wing.h"


Wing::Wing()
{


}

void Wing::init(Viewer &viewer)
{
    texture = new Texture("./textures/wing.jpg");
    shader = new Shader("./shaders/texture");

    texture0 = glGetUniformLocation( shader->m_program, "texture0");
    texcoord0 = glGetAttribLocation( shader->m_program, "texcoord0");

    glUniform1i(texture0, 0 );
}

void Wing::draw()
{
    glPushMatrix();

    shader->Bind();
    texture->Bind(0);

    glUniform1i(texture0, 0);

    float curvature = sin(animationStep);

    glBegin(GL_POLYGON);
    glNormal3f(0.0, 1.0, 0.0);

    glVertexAttrib2f(texcoord0, 0, 0);
    glVertex3f( 0, 0.1, 0 );
    glVertexAttrib2f(texcoord0, 4, 2);
    glVertex3f( 4, 0.1+curvature*1, 2 );
    glVertexAttrib2f(texcoord0, 9, 0);
    glVertex3f( 9, 0.1+curvature*3, 0 );
    glVertexAttrib2f(texcoord0, 11, -4);
    glVertex3f( 11, 0.1+curvature*8, -4 );
    glVertexAttrib2f(texcoord0, 12, -7);
    glVertex3f( 12, 0.1+curvature*11, -7 );
    glVertexAttrib2f(texcoord0, 5, -4);
    glVertex3f( 5, 0.1+curvature*5, -4 );
    glVertexAttrib2f(texcoord0, 0, -6);
    glVertex3f( 0, 0.1, -6 );

    glEnd();

    glBegin(GL_POLYGON);
    glNormal3f(0.0, -1.0, 0.0);

    glVertexAttrib2f(texcoord0, 0, 0);
    glVertex3f( 0, 0, 0 );
    glVertexAttrib2f(texcoord0, 4, 2);
    glVertex3f( 4, curvature*1, 2 );
    glVertexAttrib2f(texcoord0, 9, 0);
    glVertex3f( 9, curvature*3, 0 );
    glVertexAttrib2f(texcoord0, 11, -4);
    glVertex3f( 11, curvature*8, -4 );
    glVertexAttrib2f(texcoord0, 12, -7);
    glVertex3f( 12, curvature*11, -7 );
    glVertexAttrib2f(texcoord0, 5, -4);
    glVertex3f( 5, curvature*5, -4 );
    glVertexAttrib2f(texcoord0, 0, -6);
    glVertex3f( 0, 0, -6 );

    glEnd();

    glUseProgram(0);
    glPopMatrix();

}

void Wing::animate(float animationStep)
{
    this->animationStep = animationStep;
}
