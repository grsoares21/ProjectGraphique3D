#ifndef GLOBALSCENE_H
#define GLOBALSCENE_H
#define NUM_PILARS 10
#define NUM_WALLS 4

#include "renderable.h"
#ifndef __APPLE__
#include <GL/glut.h>
#else
#include <GLUT/glut.h>
#endif

#define OBJECTS 200
#include <QGLViewer/vec.h>
#include "pilar.h"
#include "ground.h"
#include "wall.h"
#include "roof.h"

class GlobalScene : public Renderable
{
//Attributes
private:
    Pilar *pilars[NUM_PILARS];
    Ground *ground;
    Wall *walls[NUM_WALLS];
    Roof *roof;
    void drawPillars();
    void drawGround();
    void drawWalls();
    void drawRoof();
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
