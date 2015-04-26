#include "jaw.h"

Jaw::Jaw()
{
    teeth = new LowerTeeth();
}

void Jaw::init(Viewer &viewer)
{
    texture = new Texture("./textures/scales.png");
    shader = new Shader("./shaders/texture");

    texture0 = glGetUniformLocation( shader->m_program, "texture0");
    texcoord0 = glGetAttribLocation( shader->m_program, "texcoord0");
    glUniform1i(texture0, 0 );
}

void Jaw::draw()
{
    glPushMatrix();

    teeth->draw();

    shader->Bind();
    texture->Bind(0);

    glUniform1i(texture0, 0);

    glBegin(GL_TRIANGLES);

        glNormal3f(-0.5, 1.0, 0.0);
        glVertex3f(0.0, -0.5, 0.0);
        glVertex3f(1.0, 0.0, 0.5);
        glVertex3f(1.0, 0.0, -0.5);

        glNormal3f(-0.05, 0, -0.1);
        glVertexAttrib2f(texcoord0, 0, 0);
        glVertex3f(0.0, -0.5, 0.0);
        glVertexAttrib2f(texcoord0, 0, 1);
        glVertex3f(0.2, -0.6, -0.1);
        glVertexAttrib2f(texcoord0, 1, 0.5);
        glVertex3f(0.0, -1.0, 0.0);

        glNormal3f(-0.05, 0, 0.1);
        glVertexAttrib2f(texcoord0, 0, 0);
        glVertex3f(0.0, -0.5, 0.0);
        glVertexAttrib2f(texcoord0, 0, 1);
        glVertex3f(0.2, -0.6, 0.1);
        glVertexAttrib2f(texcoord0, 1, 0.5);
        glVertex3f(0.0, -1.0, 0.0);

        glNormal3f(0.08, -0.04, 0);
        glVertexAttrib2f(texcoord0, 0, 0);
        glVertex3f(0.2, -0.6, -0.1);
        glVertexAttrib2f(texcoord0, 0, 1);
        glVertex3f(0.2, -0.6, 0.1);
        glVertexAttrib2f(texcoord0, 1, 0.5);
        glVertex3f(0.0, -1.0, 0.0);

    glEnd();

    glBegin(GL_QUADS);

        glNormal3f(-0.1, 0, -0.2);
        glVertexAttrib2f(texcoord0, 0, 0);
        glVertex3f(1.0, 0.0, -0.5);
        glVertexAttrib2f(texcoord0, 0, 1);
        glVertex3f(1.0, -0.2, -0.5);
        glVertexAttrib2f(texcoord0, 1, 0);
        glVertex3f(0.2, -0.6, -0.1);
        glVertexAttrib2f(texcoord0, 1, 1);
        glVertex3f(0.0, -0.5, 0.0);

        glNormal3f(-0.1, 0, 0.2);
        glVertexAttrib2f(texcoord0, 0, 0);
        glVertex3f(1.0, 0.0, 0.5);
        glVertexAttrib2f(texcoord0, 0, 1);
        glVertex3f(1.0, -0.2, 0.5);
        glVertexAttrib2f(texcoord0, 1, 0);
        glVertex3f(0.2, -0.6, 0.1);
        glVertexAttrib2f(texcoord0, 1, 1);
        glVertex3f(0.0, -0.5, 0.0);

        glNormal3f(1, 0, 0);
        glVertexAttrib2f(texcoord0, 0, 0);
        glVertex3f(1.0, 0.0, -0.5);
        glVertexAttrib2f(texcoord0, 0, 1);
        glVertex3f(1.0, 0.0, 0.5);
        glVertexAttrib2f(texcoord0, 1, 0);
        glVertex3f(1.0, -0.2, 0.5);
        glVertexAttrib2f(texcoord0, 1, 1);
        glVertex3f(1.0, -0.2, -0.5);

        glNormal3f(0.5, -1.0, 0.0);
        glVertexAttrib2f(texcoord0, 0, 0);
        glVertex3f(1.0, -0.2, 0.5);
        glVertexAttrib2f(texcoord0, 0, 1);
        glVertex3f(1.0, -0.2, -0.5);
        glVertexAttrib2f(texcoord0, 1, 0);
        glVertex3f(0.2, -0.6, -0.1);
        glVertexAttrib2f(texcoord0, 1, 1);
        glVertex3f(0.2, -0.6, 0.1);

    glEnd();

    glUseProgram(0);

    glPopMatrix();
}

