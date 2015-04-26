#include "pilar.h"

Pilar::Pilar(bool addTorch)
{
	size = 20;
	thickness = 4;
    if (addTorch)
        torch = new Torch(2);
}

void Pilar::init(Viewer &viewer){
    if (torch != NULL)
       torch->init(viewer);

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
    if (torch != NULL){
        glRotatef(270,1,0,0);
        glTranslatef(0, thickness/2, 2 );
        glScalef(0.5,0.5,1);
        torch->draw();
    }
    glPopMatrix();
}

void Pilar::animate(){
    if (torch != NULL){
        torch->animate();
    }
}
