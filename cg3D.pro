TEMPLATE = app
TARGET   = cg3D
CONFIG  += qt opengl warn_on debug
QT *= xml opengl 

HEADERS  = *.h

SOURCES  = *.cpp

macx:LIBS *= -framework Glut
linux-g++*:LIBS *= -lGLEW -lglut

# MacOS, default
QGL = -lQGLViewer

# Some Ubuntu variants
exists( /usr/lib/libqglviewer-qt4.so): QGL = -lqglviewer-qt4
exists( /usr/lib/x86_64-linux-gnu/libqglviewer-qt4.so ): QGL = -lqglviewer-qt4

# Ubuntu 14.04 & libqglviewer2
exists( /usr/lib/x86_64-linux-gnu/libQGLViewer.so.2 ): QGL=-lQGLViewer -lGLU

# CentOS
exists( /usr/lib64/libQGLViewer.so ): QGL=-lQGLViewer

LIBS *= $${QGL}
