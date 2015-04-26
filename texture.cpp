#include "texture.h"

Texture::Texture(const std::string& fileName)
{
    // generates an OpenGL texture id, and store it
    glGenTextures(1, &m_texture);

    // load a texture file as a QImage
    QImage img = QGLWidget::convertToGLFormat(QImage(fileName.c_str()));

    // specify the texture(2D texture, rgba, single file)
    glBindTexture(GL_TEXTURE_2D, m_texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, img.width(), img.height(), 0,
                    GL_RGBA, GL_UNSIGNED_BYTE, img.bits());

}

Texture::~Texture()
{
    glDeleteTextures(1, &m_texture);
}

void Texture::Bind(unsigned int unit)
{
    assert(unit >= 0 && unit <= 31);

    glActiveTexture(GL_TEXTURE0 + unit);
    glBindTexture(GL_TEXTURE_2D, m_texture);
}

