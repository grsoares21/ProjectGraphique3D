
#include <qapplication.h>
#include "viewer.h"
#include "dynamicSystem.h"
#include "dragon.h"
#include "fire.h"
#include "conicalFrustrum.h"
#include "pilar.h"
#include "torch.h"


int main(int argc, char** argv)
{
	// Read command lines arguments.
	QApplication application(argc,argv);

	// Instantiate the viewer.
	Viewer viewer;
//	Fire *fire = new Fire();
//	fire->setIntensity(10.0f);


	

	// build your scene here
//   	viewer.addRenderable(new Dragon());
//	viewer.addRenderable(new Fire(10));

	
    viewer.addRenderable(new Torch(2));
	
	viewer.setWindowTitle("viewer");
	// Make the viewer window visible on screen.
	viewer.show();

	// Run main loop.
	return application.exec();
}
