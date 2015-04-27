#include "teapot.h"


static const vec4 black( 0.0f, 0.0f, 0.0f, 1.0f );
static const vec4 white( 1.0f, 1.0f, 1.0f, 1.0f );
static const vec4 red( 1.0f, 0.0f, 0.0f, 1.0f );

static vec4 mat_ambient( 0.7f, 0.7f, 0.7f, 1.0f );
static vec4 mat_ambient_color( 0.8f, 0.8f, 0.2f, 1.0f );
static vec4 mat_diffuse( 0.1f, 0.5f, 0.8f, 1.0f );

static float no_shininess( 0.0f );
static float low_shininess( 5.0f );
static float high_shininess( 50.0f );

static Light light( vec4( 0.0f, 0.0f, 3.0f, 1.0f ), white, red, white );

static Material material(mat_ambient, mat_diffuse, white, high_shininess);

TeaPot::TeaPot()
{
}

void TeaPot::init(Viewer &viewer)
{
    smoke = new Smoke(10.0);
    smoke->init(viewer);

    shader = new Shader("./shaders/material");

    shader->Bind();
    glUniform4fv( glGetUniformLocation( shader->m_program, "light.la" ), 1, &light.la.x );
    glUniform4fv( glGetUniformLocation( shader->m_program, "light.ld" ), 1, &light.ld.x );
    glUniform4fv( glGetUniformLocation( shader->m_program, "light.ls" ), 1, &light.ls.x );
    glUniform4fv( glGetUniformLocation( shader->m_program, "light.position" ), 1, &light.position.x );
    glUseProgram(0);


}


void TeaPot::draw()
{
    glPushMatrix();

    // ==== SET UP LIGHTS
    glEnable(GL_LIGHTING);
    // disable the default qglviewer light !!
    glDisable(GL_LIGHT0);
    glEnable(GL_LIGHT1);

    glDisable(GL_COLOR_MATERIAL);

    shader->Bind();
    glUniform4fv( glGetUniformLocation(shader->m_program, "light.position" ), 1, &light.position.x );


    glUniform4fv( glGetUniformLocation(shader->m_program, "material.ka" ), 1, &material.ka.x);
    glUniform4fv( glGetUniformLocation(shader->m_program, "material.kd" ), 1, &material.kd.x);
    glUniform4fv( glGetUniformLocation(shader->m_program, "material.ks" ), 1, &material.ks.x);
    glUniform1f( glGetUniformLocation(shader->m_program, "material.shininess" ),  low_shininess);

    glutSolidTeapot(1);

    glEnable(GL_COLOR_MATERIAL);
    glDisable(GL_LIGHT1);
    glEnable(GL_LIGHT0);


    glUseProgram(0);

    if (this->animationStep > 70){
        glTranslatef(1.6f, 0.5f, 0);
        glRotatef(270, 0, 0, 1);
        glScalef(0.1f, 0.1f, 0.1f);
        smoke->draw();
    }

    glPopMatrix();
}

void TeaPot::animate(float step)
{
    this->animationStep = step;
    smoke->animate();
}

