#include <iostream>
using namespace std;
#include "head.h"

Head::Head()
{
    fire = new Fire(10);
    ears = new Ears();
    jaw = new Jaw();
    eyes = new Eyes();
    upperTeeth = new UpperTeeth();
}

void Head::init(Viewer &viewer)
{
    fire->init(viewer);
    ears->init(viewer);
    jaw->init(viewer);
    texture = new Texture("./textures/scales.png");
    shader = new Shader("./shaders/texture");

    texture0 = glGetUniformLocation( shader->m_program, "texture0");
    texcoord0 = glGetAttribLocation( shader->m_program, "texcoord0");
    glUniform1i(texture0, 0 );
}


void Head::draw()
{
        glPushMatrix();


        glTranslatef(-0.5, 0, 0);

        ears->draw();

        glPushMatrix();

        if(animationStep >= 60 && animationStep < 64)
        {
            glTranslatef(1, 0, 0);
            glRotatef(-sin(animationStep/1.5)*25,0,0,1); // <- relative angle to animate
            glTranslatef(-1, 0, 0);
        } else if(animationStep >= 64 && animationStep < 80)
        {

            glRotatef(90,1, 0, 0);
            glRotatef(20,0, 0, 1);
            fire->draw();
            glRotatef(-20,0, 0, 1);
            glRotatef(-90,1, 0, 0);

            glTranslatef(1, 0, 0);
            glRotatef(-sin(64/1.5)*25,0,0,1); // <- relative angle to animate
            glTranslatef(-1, 0, 0);
        }
        else
        {
            glTranslatef(1, 0, 0);
            glRotatef((-sin(animationStep)-2)*2.5,0,0,1); // <- relative angle to animate
            glTranslatef(-1, 0, 0);
        }



        jaw->draw();


        glPopMatrix();

        upperTeeth->draw();

        eyes->draw();



        shader->Bind();
        texture->Bind(0);

        glUniform1i(texture0, 0);

        //Draw base format of the skull
        glBegin(GL_TRIANGLES);

           glNormal3f(0.0, -1.0, 0.0);
           glVertex3f(0.0, 0.0, 0.0);
           glVertex3f(1.0, 0, 0.5);
           glVertex3f(1.0, 0, -0.5);

           glNormal3f(-0.25, 0.0, 0.5);
           glVertexAttrib2f(texcoord0, 0, 0);
           glVertex3f(0.0, 0.0, 0.0);
           glVertexAttrib2f(texcoord0, 0, 1);
           glVertex3f(1.0, 0.0, 0.5);
           glVertexAttrib2f(texcoord0, 1, 0.5);
           glVertex3f(1.0, 0.5, 0.5);

           glNormal3f(-0.5, 1.0, 0.0);
           glVertexAttrib2f(texcoord0, 0, 0);
           glVertex3f(0.0, 0.0, 0.0);
           glVertexAttrib2f(texcoord0, 0, 1);
           glVertex3f(1.0, 0.5, -0.5);
           glVertexAttrib2f(texcoord0, 1, 0.5);
           glVertex3f(1.0, 0.5, 0.5);

           glNormal3f(-0.25, 0.0, -0.5);
           glVertexAttrib2f(texcoord0, 0, 0);
           glVertex3f(0.0, 0.0, 0.0);
           glVertexAttrib2f(texcoord0, 0, 1);
           glVertex3f(1.0, 0.5, -0.5);
           glVertexAttrib2f(texcoord0, 1, 0.5);
           glVertex3f(1.0, 0, -0.5);


        glEnd();

        glBegin(GL_QUADS);

            glNormal3f(1.0, 0.0, 0.0);
            glVertexAttrib2f(texcoord0, 0, 0);
            glVertex3f(1.0, 0.5, 0.5);
            glVertexAttrib2f(texcoord0, 0, 1);
            glVertex3f(1.0, 0, 0.5);
            glVertexAttrib2f(texcoord0, 1, 0);
            glVertex3f(1.0, 0, -0.5);
            glVertexAttrib2f(texcoord0, 1, 1);
            glVertex3f(1.0, 0.5, -0.5);

        glEnd();

        glUseProgram(0);

        glPopMatrix();
}

void Head::animate(float animationStep)
{
    fire->animate();
    this->animationStep = animationStep;
 }


Head::~Head()
{
    free(ears);
    free(eyes);
    free(jaw);
    free(upperTeeth);
}
