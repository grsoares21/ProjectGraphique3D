#include <cmath>
#include <iostream>
#include <map>
#include <GL/glut.h>
#include "fire.h"

static GLfloat colors[12][3]=		// Rainbow Of Colors
{
	{1.0f,0.5f,0.5f},{1.0f,0.75f,0.5f},{1.0f,1.0f,0.5f},{0.75f,1.0f,0.5f},
	{0.5f,1.0f,0.5f},{0.5f,1.0f,0.75f},{0.5f,1.0f,1.0f},{0.5f,0.75f,1.0f},
	{0.5f,0.5f,1.0f},{0.75f,0.5f,1.0f},{1.0f,0.5f,1.0f},{1.0f,0.5f,0.75f}
};


Fire::Fire(float intensity)
{
    this->intensity = intensity;
    slowdown=2.0f;
}

Fire::~Fire()
{
	clear();
}


void Fire::clear()
{

}

float Fire::getIntensity(){
	return intensity;
}

void Fire::setIntensity(float i){
	intensity = i;
}

///////////////////////////////////////////////////////////////////////////////
void Fire::init(Viewer &viewer)
{

	for (loop=0;loop<MAX_PARTICLES;loop++)				// Initials All The Textures
	{
		particle[loop].active=true;								// Make All The Particles Active
		particle[loop].life=1.0f;								// Give All The Particles Full Life
        particle[loop].fade=float(rand()%100)/1000.0f+0.003f;	// Random Fade Speed
		particle[loop].r=colors[loop*(12/MAX_PARTICLES)][0];	// Select Red Rainbow Color
		particle[loop].g=colors[loop*(12/MAX_PARTICLES)][1];	// Select Red Rainbow Color
		particle[loop].b=colors[loop*(12/MAX_PARTICLES)][2];	// Select Red Rainbow Color
		particle[loop].xi=float((rand()%50)-26.0f)*10.0f;		// Random Speed On X Axis
		particle[loop].yi=float((rand()%50)-25.0f)*10.0f;		// Random Speed On Y Axis
		particle[loop].zi=float((rand()%50)-25.0f)*10.0f;		// Random Speed On Z Axis
		particle[loop].xg=-intensity;									// Set Horizontal Pull To Zero
		particle[loop].yg=0.0f;								// Set Vertical Pull Downward
		particle[loop].zg=0.0f;									// Set Pull On Z Axis To Zero
	}

}


///////////////////////////////////////////////////////////////////////////////

void Fire::draw()
{
    glPushAttrib(GL_COLOR_BUFFER_BIT);
    glPushAttrib(GL_CURRENT_BIT);
    glPushAttrib(GL_SMOOTH);
    glPushAttrib(GL_SRC_ALPHA);
    glPushAttrib(GL_ONE);
    glPushAttrib(GL_PERSPECTIVE_CORRECTION_HINT);
    glPushAttrib(GL_NICEST);
    glPushAttrib(GL_POINT_SMOOTH_HINT);
    glPushMatrix();


    glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
    glClearColor(0.0f,0.0f,0.0f,0.0f);					// Black Background
    glClearDepth(1.0f);									// Depth Buffer Setup
    glEnable(GL_BLEND);									// Enable Blending
    glBlendFunc(GL_SRC_ALPHA,GL_ONE);					// Type Of Blending To Perform
    glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST);	// Really Nice Perspective Calculations
    glHint(GL_POINT_SMOOTH_HINT,GL_NICEST);				// Really Nice Point Smoothing
   glBindTexture(GL_TEXTURE_2D, textureImage);

    for (loop=0;loop<MAX_PARTICLES;loop++)					// Loop Through All The Particles
	{
		if (particle[loop].active)							// If The Particle Is Active
		{
			float x=particle[loop].x;						// Grab Our Particle X Position
			float y=particle[loop].y;						// Grab Our Particle Y Position
			float z=particle[loop].z;					// Particle Z Pos + Zoom

			// Draw The Particle Using Our RGB Values, Fade The Particle Based On It's Life
			glColor4f(particle[loop].r,particle[loop].g,particle[loop].b,particle[loop].life);
            glBegin(GL_POLYGON);

            glVertex3f( x+0.5, y-0.5, z+0.5 );      // P1 is red
            glVertex3f( x-0.5, y+0.5, z+0.5 );      // P2 is green
            glVertex3f( x+0.5, y+0.5, z-0.5 );      // P3 is blue
            glVertex3f( x-0.5, y-0.5, z-0.5 );      // P4 is purple

            glEnd();
		}
    }
    glPopMatrix();
    glPopAttrib();
    glPopAttrib();
    glPopAttrib();
    glPopAttrib();
    glPopAttrib();
    glPopAttrib();
    glPopAttrib();
    glPopAttrib();
}


///////////////////////////////////////////////////////////////////////////////
void Fire::animate()
{
	for (loop=0;loop<MAX_PARTICLES;loop++)					// Loop Through All The Particles
	{
		if (particle[loop].active)							// If The Particle Is Active
		{
			particle[loop].xg=-intensity;			

			particle[loop].x+=particle[loop].xi/(slowdown*1000);// Move On The X Axis By X Speed
			particle[loop].y+=particle[loop].yi/(slowdown*1000);// Move On The Y Axis By Y Speed
			particle[loop].z+=particle[loop].zi/(slowdown*1000);// Move On The Z Axis By Z Speed

			particle[loop].xi+=(1.0f-particle[loop].life)*particle[loop].xg*20;			
			particle[loop].yi+=(1.0f-particle[loop].life)*particle[loop].yg*20;			
			particle[loop].zi+=(1.0f-particle[loop].life)*particle[loop].zg*20;			
			
			particle[loop].xi+=particle[loop].xg;			// Take Pull On X Axis Into Account
			particle[loop].yi+=particle[loop].yg;			// Take Pull On Y Axis Into Account
			particle[loop].zi+=particle[loop].zg;			// Take Pull On Z Axis Into Account
			particle[loop].life-=particle[loop].fade;		// Reduce Particles Life By 'Fade'

			if (particle[loop].life<0.0f)					// If Particle Is Burned Out
			{
				particle[loop].life=1.0f;					// Give It New Life
                particle[loop].fade=float(rand()%100)/1000.0f+0.012f;	// Random Fade Value
				particle[loop].x=0.0f;						// Center On X Axis
				particle[loop].y=0.0f;						// Center On Y Axis
				particle[loop].z=0.0f;						// Center On Z Axis
				particle[loop].xi=xspeed+float((rand()%60)-32.0f);	// X Axis Speed And Direction
				particle[loop].yi=yspeed+float((rand()%60)-30.0f);	// Y Axis Speed And Direction
				particle[loop].zi=float((rand()%60)-30.0f);	// Z Axis Speed And Direction
                particle[loop].r=colors[0][0];			// Select Red From Color Table
                particle[loop].g=colors[0][1];			// Select Green From Color Table
                particle[loop].b=colors[0][2];			// Select Blue From Color Table
			}
		}
    }
}
