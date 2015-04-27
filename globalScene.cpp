#include "globalScene.h"


GlobalScene::GlobalScene()
{
}

void GlobalScene::init(Viewer &viewer)
{
    for (int i = 0; i < NUM_PILARS; i++){
        pilars[i] = new Pilar(true);
        pilars[i]->init(viewer);
    }

    ground = new Ground(100,100);
    ground->init(viewer);
    for (int i = 0; i < NUM_WALLS; i++){
       // walls[i] = new Wall(10,10);
       // walls[i]->init(viewer);
    }

    roof = new Roof(10,10, 40);

    dragon = new Dragon();
    dragon->init(viewer);
}

void GlobalScene::drawPillars(){
    glPushMatrix();
    int stepPilars = 10;
    glColor3f(0.2,0.2,0.2);
    for (int i = 0; i < NUM_PILARS/2; i++){
        pilars[i]->draw();
        glTranslatef(stepPilars,0,0);
    }
    glTranslatef(-stepPilars , 30, 0);
    glRotatef(180, 0, 0, 1);
    for (int i = NUM_PILARS/2; i < NUM_PILARS ; i++){
        pilars[i]->draw();
        glTranslatef(stepPilars,0,0);
    }
    glPopMatrix();
}

void GlobalScene::drawGround(){
    glPushMatrix();
    glTranslatef(-50, -50, 0);
    ground->draw();
    glPopMatrix();
}

void GlobalScene::drawWalls(){

}

void GlobalScene::drawRoof(){

}

void GlobalScene::draw()
{
    drawGround();
    drawPillars();

    glRotatef(90, 1, 0, 0);
    glTranslatef(15, 5, -15);
    dragon->draw();
}

void GlobalScene::animate()
{
    for (int i = 0; i < NUM_PILARS; i++){
        pilars[i]->animate();
    }
    dragon->animate();
}

