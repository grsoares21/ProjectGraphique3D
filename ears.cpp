#include <iostream>
using namespace std;
#include "ears.h"


Ears::Ears()
{

}


void Ears::init(Viewer &)
{
    texture = new Texture("./textures/scales.png");
    shader = new Shader("./shaders/texture");

    texture0 = glGetUniformLocation( shader->m_program, "texture0");
    texcoord0 = glGetAttribLocation( shader->m_program, "texcoord0");
    glUniform1i(texture0, 0 );
}

void Ears::draw()
{
    glPushMatrix();

    shader->Bind();
    texture->Bind(0);

    glUniform1i(texture0, 0);

    glBegin(GL_TRIANGLES);

        glNormal3f(-0.9, 0.0, 1.5);
        glVertexAttrib2f(texcoord0, 0, 0);
        glVertex3f(0.0, 0.0, 0.0);
        glVertexAttrib2f(texcoord0, 0, 1);
        glVertex3f(1.5, 0.0, 0.9);
        glVertexAttrib2f(texcoord0, 1, 0.5);
        glVertex3f(1.5, 1, 0.9);

        glNormal3f(0.0, -0.1, 0.0);
        glVertexAttrib2f(texcoord0, 0, 0);
        glVertex3f(0.0, 0.0, 0.0);
        glVertexAttrib2f(texcoord0, 0, 1);
        glVertex3f(1.5, 0.0, 0.9);
        glVertexAttrib2f(texcoord0, 1, 0.5);
        glVertex3f(1.0, 0.0, 0.5);

        glNormal3f(0.05, 0.15, -0.25);
        glVertexAttrib2f(texcoord0, 0, 0);
        glVertex3f(0.0, 0.0, 0.0);
        glVertexAttrib2f(texcoord0, 0, 1);
        glVertex3f(1.0, 0.5, 0.5);
        glVertexAttrib2f(texcoord0, 1, 0.5);
        glVertex3f(1.5, 1, 0.9);

    glEnd();

    glBegin(GL_QUADS);

        glNormal3f(0.4, 0.0, -0.5);
        glVertexAttrib2f(texcoord0, 0, 0);
        glVertex3f(1.0, 0.5, 0.5);
        glVertexAttrib2f(texcoord0, 0, 1);
        glVertex3f(1.0, 0.0, 0.5);
        glVertexAttrib2f(texcoord0, 1, 0);
        glVertex3f(1.5, 0.0, 0.9);
        glVertexAttrib2f(texcoord0, 1, 1);
        glVertex3f(1.5, 1, 0.9);


    glEnd();


    glBegin(GL_TRIANGLES);

        glNormal3f(-0.9, 0.0, -1.5);
        glVertexAttrib2f(texcoord0, 0, 0);
        glVertex3f(0.0, 0.0, 0.0);
        glVertexAttrib2f(texcoord0, 0, 1);
        glVertex3f(1.5, 0.0, -0.9);
        glVertexAttrib2f(texcoord0, 1, 0.5);
        glVertex3f(1.5, 1, -0.9);

        glNormal3f(0.0, -0.1, 0.0);
        glVertexAttrib2f(texcoord0, 0, 0);
        glVertex3f(0.0, 0.0, 0.0);
        glVertexAttrib2f(texcoord0, 0, 1);
        glVertex3f(1.5, 0.0, -0.9);
        glVertexAttrib2f(texcoord0, 1, 0.5);
        glVertex3f(1.0, 0.0, -0.5);

        glNormal3f(0.05, 0.15, 0.25);
        glVertexAttrib2f(texcoord0, 0, 0);
        glVertex3f(0.0, 0.0, 0.0);
        glVertexAttrib2f(texcoord0, 0, 1);
        glVertex3f(1.0, 0.5, -0.5);
        glVertexAttrib2f(texcoord0, 1, 0.5);
        glVertex3f(1.5, 1, -0.9);

    glEnd();

    glBegin(GL_QUADS);

        glNormal3f(0.4, 0.0, 0.5);
        glVertexAttrib2f(texcoord0, 0, 0);
        glVertex3f(1.0, 0.5, -0.5);
        glVertexAttrib2f(texcoord0, 0, 1);
        glVertex3f(1.0, 0.0, -0.5);
        glVertexAttrib2f(texcoord0, 1, 0);
        glVertex3f(1.5, 0.0, -0.9);
        glVertexAttrib2f(texcoord0, 1, 1);
        glVertex3f(1.5, 1, -0.9);
/*
glVertexAttrib2f(texcoord0, 0, 0);
glVertexAttrib2f(texcoord0, 0, 1);
glVertexAttrib2f(texcoord0, 1, 0);
glVertexAttrib2f(texcoord0, 1, 1);*/

    glEnd();

    glUseProgram(0);

    glPopMatrix();
}


