#include "ground.h"

Ground::Ground(float x, float z)
{
    Xsize = x;
    Zsize = z;
}

void Ground::init(Viewer &viewer)
{
    texture = new Texture("./Data/rock.jpg");
    shader = new Shader("./shaders/texture");
    texture0 = glGetUniformLocation(shader->m_program, "texture0");
    texcoord0 = glGetAttribLocation(shader->m_program, "texcoord0");
    glUniform1i(texture0,0);
}


void Ground::draw()
{
    glPushMatrix();
    shader->Bind();
    texture->Bind(0);
    glBegin(GL_QUADS);
        glNormal3f(0.0, 0.0, 1.0);
        glVertexAttrib2f(texcoord0, 0, 0);
        glVertex3f(0, 0, 0);
        glVertexAttrib2f(texcoord0, Xsize/10, 0);
        glVertex3f(Xsize, 0, 0);
        glVertexAttrib2f(texcoord0, Xsize/10, Zsize/10);
        glVertex3f(Xsize, Zsize, 0);
       glVertexAttrib2f(texcoord0, 0, Zsize/10);
        glVertex3f(0, Zsize, 0);
    glEnd();
    glPopMatrix();
    glUseProgram(0);
}

void Ground::animate()
{

}
