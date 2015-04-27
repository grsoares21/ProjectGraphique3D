#include "globalScene.h"


GlobalScene::GlobalScene()
{
}

void GlobalScene::init(Viewer &viewer)
{
    animationStep=0;

    for (int i = 0; i < 10; i++){
        pilars[i] = new Pilar(true);
        pilars[i]->init(viewer);
    }
    for (int i = 10; i < 13; i++){
        pilars[i] = new Pilar(false);
        pilars[i]->init(viewer);
    }

    for (int i = 0; i < NUM_TORCHES; i++){
        torches[i] = new Torch(3);
        torches[i]->init(viewer);
    }

    teapot = new TeaPot();
    teapot->init(viewer);

    dragon = new Dragon();
    dragon->init(viewer);

    ground = new Ground(100,100);
    ground->init(viewer);
    for (int i = 0; i < NUM_WALLS; i++){
       walls[i] = new Wall(50,50);
       walls[i]->init(viewer);
    }
    skybox = new Skybox();
    skybox->init(viewer);

 }

void GlobalScene::drawPillarsAndTorches(){
    glPushMatrix();
    int step = 10;
    glColor3f(0.2,0.2,0.2);
    for (int i = 0; i < 5; i++){
        pilars[i]->draw();
        glTranslatef(step,0,0);
    }
    glTranslatef(-step , 30, 0);
    glRotatef(180, 0, 0, 1);
    for (int i = 5; i < 10 ; i++){
        pilars[i]->draw();
        glTranslatef(step,0,0);
    }
    glTranslatef(18,70,0);
    step = 7;
    for (int i = 10; i < 13 ; i++){
        pilars[i]->draw();
        glTranslatef(step,0,0);
    }
    glTranslatef(-3*step,0,20);
    torches[0]->draw();
    glTranslatef(step*2,0,0);
    torches[1]->draw();

    glRotatef(90, 1, 0, 0);
    glTranslatef(-step,2.2,0);
    glColor3f(0.8,0.8,0.8);
    teapot->draw();

    glPopMatrix();
}

void GlobalScene::drawGround(){
    glPushMatrix();
    glTranslatef(-50, -50, 0);
    ground->draw();
    glPopMatrix();
}


void GlobalScene::drawSkybox(){
    //glPushMatrix();
    glScalef(2000,2000,2000);
    skybox->draw();
    glScalef(0.0005,0.0005,0.0005);

    //glPopMatrix();
}

void GlobalScene::drawWalls(){
    glPushMatrix();

    glTranslatef(-50, -50, 0);
    walls[0]->draw();
    glTranslatef(50, 0, 0);
    walls[1]->draw();
    glRotatef(90, 0, 0, 1);
    glTranslatef(0, -50, 0);
    walls[2]->draw();
    glTranslatef(50, 0, 0);
    walls[3]->draw();

    glPopMatrix();


}

void GlobalScene::draw()
{
    drawSkybox();
    drawGround();
    drawWalls();
    drawPillarsAndTorches();
    glRotatef(90, 1, 0, 0);
    glTranslatef(15, 5, -15);
    dragon->draw();

}

void GlobalScene::animate()
{
    animationStep += 0.2;
    teapot->animate(animationStep);
    for (int i = 0; i < NUM_PILARS; i++){
        pilars[i]->animate();
    }
    for (int i = 0; i < NUM_TORCHES; i++){
        torches[i]->animate();
    }
    dragon->animate();
}

