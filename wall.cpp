#include "wall.h"

Wall::Wall(float x, float y)
{
    Xsize = x;
    Ysize = y;
}

void Wall::init(Viewer &viewer)
{
    texture = new Texture("./Data/wall.png");
    shader = new Shader("./shaders/texture");
    texture0 = glGetUniformLocation(shader->m_program, "texture0");
    texcoord0 = glGetAttribLocation(shader->m_program, "texcoord0");
    glUniform1i(texture0,0);
}


void Wall::draw()
{
    glPushMatrix();
    shader->Bind();
    texture->Bind(0);
     glUniform1i(texture0,0);
    glBegin(GL_QUADS);
        glNormal3f(0.0, 0.0, 1.0);
        glVertexAttrib2f(texcoord0, 0, 0);
        glVertex3f(0, 0, 0);
        glVertexAttrib2f(texcoord0, Xsize/10, 0);
        glVertex3f(Xsize, 0, 0);
        glVertexAttrib2f(texcoord0, Xsize/10, Ysize/10);
        glVertex3f(Xsize, 0, Ysize);
       glVertexAttrib2f(texcoord0, 0, Ysize/10);
        glVertex3f(0, 0, Ysize);
    glEnd();
    glPopMatrix();
    glUseProgram(0);
}

void Wall::animate()
{

}
