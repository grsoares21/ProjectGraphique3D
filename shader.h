#ifndef SHADER_H
#define SHADER_H

#include "glCheck.h"

#include <string>
#include <iostream>
#include <fstream>

#ifndef __APPLE__
#include <GL/glut.h>
#else
#include <GLUT/glut.h>
#endif


class Shader
{
public:
    Shader(){}
    Shader(const std::string& fileName);

    void Bind();
    void Unbind();

    virtual ~Shader();

    GLuint m_program;

private:
    static const unsigned int NUM_SHADERS = 2;
    void operator=(const Shader& other) {}
    Shader(const Shader& other) {}

    std::string LoadShader(const std::string& fileName);

    GLuint m_shaders[];

};

#endif // SHADER_H
