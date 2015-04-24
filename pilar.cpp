#include "pilar.h"



Pilar::Pilar()
{
	size = 20;
	thickness = 4;
}


void Pilar::draw()
{
    glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glTranslatef(0, size/2, 0);
	Cylinder *cylinder = new Cylinder(size, thickness/3);
    	cylinder->draw();
	glTranslatef(0, size/2 , 0);
	Cylinder *cylinderBase = new Cylinder(3, thickness/2);
    	cylinderBase->draw();
	glTranslatef(0, -size+1.5, 0);
	Cylinder *cylinderTop = new Cylinder(3, thickness/2);
    	cylinderTop->draw();
    glPopMatrix();
}
