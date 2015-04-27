#include "skybox.h"

#include "ground.h"

Skybox::Skybox()
{

}

void Skybox::init(Viewer &viewer)
{
    texture = new Texture("./Data/bg.jpg");
    shader = new Shader("./shaders/texture");
    texture0 = glGetUniformLocation(shader->m_program, "texture0");
    texcoord0 = glGetAttribLocation(shader->m_program, "texcoord0");
    glUniform1i(texture0,0);
}


void Skybox::draw()
{
    glPushMatrix();
    shader->Bind();
    texture->Bind(0);
    float size = 1;

    glBegin(GL_QUADS);

        // for each face, define a normal (first) the a
        // 0 3 2 1
        glNormal3f(0.0, 0.0, 1.0);
        glVertexAttrib2f(texcoord0, 0, 0);
        glVertex3f((size / 2), -(size / 2), -(size / 2));
        glVertexAttrib2f(texcoord0, 1, 0);
        glVertex3f((size / 2), (size / 2), -(size / 2));
        glVertexAttrib2f(texcoord0, 1, 1);
        glVertex3f(-(size / 2), (size / 2), -(size / 2));
        glVertexAttrib2f(texcoord0, 0, 1);
        glVertex3f(-(size / 2), -(size / 2), -(size / 2));

        // 0 4 7 3
        glNormal3f(0.0, 1.0, 0.0);
        glVertexAttrib2f(texcoord0, 0, 0);
        glVertex3f((size / 2), -(size / 2), -(size / 2));
        glVertexAttrib2f(texcoord0, 1, 0);
        glVertex3f((size / 2), -(size / 2), (size / 2));
        glVertexAttrib2f(texcoord0, 1, 1);
        glVertex3f(-(size / 2), -(size / 2), (size / 2));
        glVertexAttrib2f(texcoord0, 0, 1);
        glVertex3f(-(size / 2), -(size / 2), -(size / 2));

        // 1 5 4 0
        glNormal3f(-1.0, 0.0, 0.0);
        glVertexAttrib2f(texcoord0, 0, 0);
        glVertex3f((size / 2), (size / 2), -(size / 2));
        glVertexAttrib2f(texcoord0, 1, 0);
        glVertex3f((size / 2), (size / 2), (size / 2));
        glVertexAttrib2f(texcoord0, 1, 1);
        glVertex3f((size / 2), -(size / 2), (size / 2));
        glVertexAttrib2f(texcoord0, 0, 1);
        glVertex3f((size / 2), -(size / 2), -(size / 2));

        // 2 6 5 1
        glNormal3f(0.0, -1.0, 0.0);
        glVertexAttrib2f(texcoord0, 0, 0);
        glVertex3f(-(size / 2), (size / 2), -(size / 2));
        glVertexAttrib2f(texcoord0, 1, 0);
        glVertex3f(-(size / 2), (size / 2), (size / 2));
        glVertexAttrib2f(texcoord0, 1, 1);
        glVertex3f((size / 2), (size / 2), (size / 2));
        glVertexAttrib2f(texcoord0, 0, 1);
        glVertex3f((size / 2), (size / 2), -(size / 2));

        // 3 7 6 2
        glNormal3f(1.0, 0.0, 0.0);
        glVertexAttrib2f(texcoord0, 0, 0);
        glVertex3f(-(size / 2), -(size / 2), -(size / 2));
        glVertexAttrib2f(texcoord0, 1, 0);
        glVertex3f(-(size / 2), -(size / 2), (size / 2));
        glVertexAttrib2f(texcoord0, 1, 1);
        glVertex3f(-(size / 2), (size / 2), (size / 2));
        glVertexAttrib2f(texcoord0, 0, 1);
        glVertex3f(-(size / 2), (size / 2), -(size / 2));

        // 4 5 6 7
        glNormal3f(0.0, 0.0, -1.0);
        glVertexAttrib2f(texcoord0, 0, 0);
        glVertex3f((size / 2), -(size / 2), (size / 2));
        glVertexAttrib2f(texcoord0, 1, 0);
        glVertex3f((size / 2), (size / 2), (size / 2));
        glVertexAttrib2f(texcoord0, 1, 1);
        glVertex3f(-(size / 2), (size / 2), (size / 2));
        glVertexAttrib2f(texcoord0, 0, 1);
        glVertex3f(-(size / 2), -(size / 2), (size / 2));

    glEnd();


    glPopMatrix();
    glUseProgram(0);
}

void Skybox::animate()
{

}
