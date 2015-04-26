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

    ground = new Ground(10,10);

    for (int i = 0; i < NUM_WALLS; i++){
       // walls[i] = new Wall(10,10);
       // walls[i]->init(viewer);
    }

    roof = new Roof(10,10, 40);

}

void GlobalScene::drawPillars(){
    glPushMatrix();
    int stepPilars = 10;
    for (int i = 0; i < NUM_PILARS/2; i++){
        pilars[i]->draw();
        glTranslatef(stepPilars,0,0);
    }
    glTranslatef(-stepPilars , 20, 0);
    glRotatef(180, 0, 0, 1);
    for (int i = NUM_PILARS/2; i < NUM_PILARS ; i++){
        pilars[i]->draw();
        glTranslatef(stepPilars,0,0);
    }
    glPopMatrix();
}

void GlobalScene::drawGround(){
    ground->draw();
}

void GlobalScene::drawWalls(){

}

void GlobalScene::drawRoof(){

}

void GlobalScene::draw()
{
    drawGround();
    drawPillars();
}

void GlobalScene::animate()
{
    for (int i = 0; i < NUM_PILARS; i++){
        pilars[i]->animate();
    }
}

