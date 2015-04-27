#ifndef SMOKE_H
#define SMOKE_H

#define	MAX_PARTICLES	1000		// Number Of Particles To Create

#include <QGLViewer/vec.h>

#include <vector>

#include "particle.h"
#include "renderable.h"

/*
 * This class represents a dynamic system made of particles
 * linked together with damped springs, within a medium with
 * gravity and viscosity.
 * Particles a represented by small spheres, with a radius and a mass.
 * The initial scene is composed of a fixed plane, a static particle
 * that can be controlled by the mouse, and a dynamic particle.
 */


typedef struct						// Create A Structure For Particle
{
    bool	active;					// Active (Yes/No)
    float	life;					// Particle Life
    float	fade;					// Fade Speed
    float	r;						// Red Value
    float	g;						// Green Value
    float	b;						// Blue Value
    float	x;						// X Position
    float	y;						// Y Position
    float	z;						// Z Position
    float	xi;						// X Direction
    float	yi;						// Y Direction
    float	zi;						// Z Direction
    float	xg;						// X Gravity
    float	yg;						// Y Gravity
    float	zg;						// Z Gravity
}
particlesSmoke;							// Particles Structure

class Smoke : public Renderable
{

private:
    float	slowdown;				// Slow Down Particles
    float	xspeed;						// Base X Speed (To Allow Keyboard Direction Of Tail)
    float	yspeed;						// Base Y Speed (To Allow Keyboard Direction Of Tail)
    float   intensity;
    GLuint	loop;						// Misc Loop Variable
    GLuint	delay;						// Rainbow Effect Delay
    particlesSmoke particle[MAX_PARTICLES];	// Particle Array (Room For Particle Info)

public:
    Smoke(float intensity);
    virtual ~Smoke();
    float getIntensity();
    void setIntensity(float i);


private:
    // Reset the scene (remove all particles and springs)
    void clear();

// Renderable methods
public:
    // Init the particle-spring system
    void init(Viewer &);

    // Draw the particle-spring system
    void draw();

    // Update positions and velocities of dynamic objects
    void animate();
};

#endif // SMOKE_H
