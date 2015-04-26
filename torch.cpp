#include "torch.h"

Torch::Torch(float s)
{
    size = s;
}

void Torch::init(Viewer &viewer)
{
    fire = new Fire(1);
    fire->init(viewer);
}


void Torch::draw()
{
    glPushMatrix();

    glTranslatef(0, 0, size);
    glRotatef(180 , 1, 0, 0);
    glutSolidCone(2, size, 40, 40);
    glRotatef(90, 1, 0, 0);
    glTranslatef(0, -0.1, 0);
    Cylinder *cylinder = new Cylinder(0.2, 2);
    cylinder->draw();
    glRotatef(-90, 1, 0, 0);
    glRotatef(270, 0, 1, 0);
    fire->draw();
    glPopMatrix();
}

void Torch::animate()
{
    fire->animate();
}
