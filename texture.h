#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>
#include <cassert>
#include <iostream>
#include <QImage>
#include <QGLViewer/qglviewer.h>

#ifndef __APPLE__
#include <GL/glut.h>
#else
#include <GLUT/glut.h>
#endif


class Texture
{
public:
    Texture(){}
    Texture(const std::string& fileName);

    void Bind(unsigned int unit);

    virtual ~Texture();

private:

    GLuint m_texture;
};

#endif // TEXTURE_H
