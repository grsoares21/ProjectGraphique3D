#ifndef GLOBALSCENE_H
#define GLOBALSCENE_H
#define NUM_PILARS 13
#define NUM_WALLS 4
#define NUM_TORCHES 2

#include "dragon.h"
#include "renderable.h"
#ifndef __APPLE__
#include <GL/glut.h>
#else
#include <GLUT/glut.h>
#endif

#define OBJECTS 200
#include <QGLViewer/vec.h>
#include "teapot.h"
#include "pilar.h"
#include "ground.h"
#include "skybox.h"
#include "wall.h"
#include "roof.h"

class GlobalScene : public Renderable
{
//Attributes
private:
    Pilar *pilars[NUM_PILARS];
    Ground *ground;
    Wall *walls[NUM_WALLS];
    Dragon *dragon;
    Torch *torches[NUM_TORCHES];
    TeaPot *teapot;
    Skybox *skybox;
    float animationStep;
    void drawPillarsAndTorches();
    void drawSkybox();
    void drawGround();
    void drawWalls();
    void drawImage(void);
//Constructor
public:
    GlobalScene();

//Renderable Methods
public:
    void init(Viewer &);
    void draw();
    void animate();
};

#endif
