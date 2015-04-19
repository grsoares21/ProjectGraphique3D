
#include <qapplication.h>
#include "viewer.h"
#include "dynamicSystem.h"
#include "cube.h"
#include "head.h"
#include "neck.h"
#include "body.h"
#include "leg.h"
#include "conicalFrustrum.h"


int main(int argc, char** argv)
{
	// Read command lines arguments.
	QApplication application(argc,argv);

	// Instantiate the viewer.
	Viewer viewer;

	// build your scene here
    viewer.addRenderable(new Leg());

	viewer.setWindowTitle("viewer");
	// Make the viewer window visible on screen.
	viewer.show();

	// Run main loop.
	return application.exec();
}
