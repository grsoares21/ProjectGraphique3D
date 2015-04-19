#include <iostream>
using namespace std;
#include "cube.h"

/*
          Z
          |
    7 ------- 6
     /|      /|
    / |     / |   ---> Y
 4 -------5 |
   | 3----|-- 2
   | /     | /
   |/      |/
 0 ------- 1
      /
     X         
*/

Cube::Cube(float sideSize)
{
    size = sideSize;
}

void Cube::draw()
{
	glPushMatrix();

    glBegin(GL_QUADS);

        // for each face, define a normal (first) the a
        // 0 3 2 1
        glNormal3f(0.0, 0.0, -1.0);
        glVertex3f((size / 2), -(size / 2), -(size / 2));
        glVertex3f((size / 2), (size / 2), -(size / 2));
        glVertex3f(-(size / 2), (size / 2), -(size / 2));
        glVertex3f(-(size / 2), -(size / 2), -(size / 2));

        // 0 4 7 3
        glNormal3f(0.0, -1.0, 0.0);
        glVertex3f((size / 2), -(size / 2), -(size / 2));
        glVertex3f((size / 2), -(size / 2), (size / 2));
        glVertex3f(-(size / 2), -(size / 2), (size / 2));
        glVertex3f(-(size / 2), -(size / 2), -(size / 2));

        // 1 5 4 0
        glNormal3f(1.0, 0.0, 0.0);
        glVertex3f((size / 2), (size / 2), -(size / 2));
        glVertex3f((size / 2), (size / 2), (size / 2));
        glVertex3f((size / 2), -(size / 2), (size / 2));
        glVertex3f((size / 2), -(size / 2), -(size / 2));

        // 2 6 5 1
        glNormal3f(0.0, 1.0, 0.0);
        glVertex3f(-(size / 2), (size / 2), -(size / 2));
        glVertex3f(-(size / 2), (size / 2), (size / 2));
        glVertex3f((size / 2), (size / 2), (size / 2));
        glVertex3f((size / 2), (size / 2), -(size / 2));

        // 3 7 6 2
        glNormal3f(-1.0, 0.0, 0.0);
        glVertex3f(-(size / 2), -(size / 2), -(size / 2));
        glVertex3f(-(size / 2), -(size / 2), (size / 2));
        glVertex3f(-(size / 2), (size / 2), (size / 2));
        glVertex3f(-(size / 2), (size / 2), -(size / 2));

        // 4 5 6 7
        glNormal3f(0.0, 0.0, 1.0);
        glVertex3f((size / 2), -(size / 2), (size / 2));
        glVertex3f((size / 2), (size / 2), (size / 2));
        glVertex3f(-(size / 2), (size / 2), (size / 2));
        glVertex3f(-(size / 2), -(size / 2), (size / 2));

    glEnd();

	glPopMatrix();
}


//==================== 1. Immediate method ===================================
// immediate definition of individual vertex properties




