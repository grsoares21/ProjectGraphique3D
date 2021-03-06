#include "glCheck.h"
#include "viewer.h"
#include "teapot.h"

#include <qapplication.h>

#include "globalScene.h"


int main(int argc, char** argv)
{
	// Read command lines arguments.
	QApplication application(argc,argv);

	// Instantiate the viewer.
	Viewer viewer;


	// build your scene here
    viewer.addRenderable(new GlobalScene());

	
	viewer.setWindowTitle("viewer");
	// Make the viewer window visible on screen.
	viewer.show();

	// Run main loop.
	return application.exec();
}
