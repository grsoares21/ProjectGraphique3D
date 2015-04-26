#include "glCheck.h"
#include "viewer.h"
#include "dragon.h"

#include <qapplication.h>

#include "fire.h"
#include "teapot.h"
#include "wing.h"
#include "globalScene.h"


int main(int argc, char** argv)
{
	// Read command lines arguments.
	QApplication application(argc,argv);

	// Instantiate the viewer.
	Viewer viewer;


	// build your scene here
    viewer.addRenderable(new Dragon());

	
	viewer.setWindowTitle("viewer");
	// Make the viewer window visible on screen.
	viewer.show();

	// Run main loop.
	return application.exec();
}
