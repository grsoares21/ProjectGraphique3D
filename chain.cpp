#include <cmath>
#include <iostream>
using namespace std;
#include <map>

#include "viewer.h"
#include "chain.h"


Chain::Chain()
    :
    defaultGravity(0.0, -10.0, 0.0),
    defaultMediumViscosity(1.0),
    dt(0.1),
    groundPosition(0.0, 0.0, 0.0),
    groundNormal(0.0, 0.0, 1.0),
    rebound(0.5)
{

}

Chain::~Chain()
{
    clear();
}


void Chain::clear()
{
    std::vector<Particle *>::iterator itP;
    for (itP = particles.begin(); itP != particles.end(); ++itP) {
        delete(*itP);
    }
    particles.clear();

    std::vector<Spring *>::iterator itS;
    for (itS = springs.begin(); itS != springs.end(); ++itS) {
        delete(*itS);
    }
    springs.clear();
}

const qglviewer::Vec &Chain::getFixedParticlePosition() const
{
    return particles[0]->getPosition();	// no check on 0!
}

void Chain::setFixedParticlePosition(const qglviewer::Vec &pos)
{
    if (particles.size() > 0)
        particles[0]->setPosition(pos);
}

void Chain::setGravity(bool onOff)
{
    gravity = (onOff ? defaultGravity : qglviewer::Vec());
}

void Chain::setViscosity(bool onOff)
{
    mediumViscosity = (onOff ? defaultMediumViscosity : 0.0);
}

void Chain::setCollisionsDetection(bool onOff)
{
    handleCollisions = onOff;
}



void Chain::init(Viewer &viewer)
{
    toggleGravity = true;
    toggleViscosity = true;
    toggleCollisions = true;
    clear();

    // global scene parameters
    defaultGravity = qglviewer::Vec(0.0, -10.0, 0.0);
    gravity = defaultGravity;
    defaultMediumViscosity = 0.2;
    mediumViscosity = defaultMediumViscosity;
    handleCollisions = true;
    dt = 0.1;
    groundPosition = qglviewer::Vec(0.0, -7.0, 0.0);
    groundNormal = qglviewer::Vec(0.0, 1.0, 0.0);
    rebound = 0.5;
    // parameters shared by all particles
    particleMass = 1.0;
    particleRadius = 0.25;
    distanceBetweenParticles = 4.0 * particleRadius;
    // parameters shared by all springs
    springStiffness = 30.0;
    springInitLength = 0.5;
    springDamping = 1.0;

    createSystemScene();
    // or another method, e.g. to test collisions on simple cases...
// 	createTestCollisions();

    // add a manipulatedFrame to move particle 0 with the mouse
    viewer.setManipulatedFrame(new qglviewer::ManipulatedFrame());
    viewer.manipulatedFrame()->setPosition(getFixedParticlePosition());

}


///////////////////////////////////////////////////////////////////////////////
void Chain::createSystemScene()
{
    // add a fixed particle
    qglviewer::Vec initPos = qglviewer::Vec(0.0, 0.0, 0.0);
    particles.push_back(new Particle(initPos, qglviewer::Vec(), 0.0, particleRadius));

    // add a second particle
    qglviewer::Vec pos1 = initPos + qglviewer::Vec(0.0, distanceBetweenParticles, 0.0);
    qglviewer::Vec vel1 = qglviewer::Vec(0.0, -0.0, 0.0);
    particles.push_back(new Particle(pos1, vel1, particleMass, particleRadius));

    qglviewer::Vec pos2 = pos1 + qglviewer::Vec(0.0, distanceBetweenParticles, 0.0);
    qglviewer::Vec vel2 = qglviewer::Vec(0.0, -0.0, 0.0);
    particles.push_back(new Particle(pos2, vel2, particleMass, particleRadius));

    qglviewer::Vec pos3 = pos2 + qglviewer::Vec(0.0, distanceBetweenParticles, 0.0);
    qglviewer::Vec vel3 = qglviewer::Vec(0.0, -0.0, 0.0);
    particles.push_back(new Particle(pos3, vel3, particleMass, particleRadius));

    qglviewer::Vec pos4 = pos3 + qglviewer::Vec(0.0, distanceBetweenParticles, 0.0);
    qglviewer::Vec vel4 = qglviewer::Vec(0.0, -0.0, 0.0);
    particles.push_back(new Particle(pos4, vel4, particleMass, particleRadius));

    qglviewer::Vec pos5 = pos4 + qglviewer::Vec(0.0, distanceBetweenParticles, 0.0);
    qglviewer::Vec vel5 = qglviewer::Vec(0.0, -0.0, 0.0);
    particles.push_back(new Particle(pos5, vel5, particleMass, particleRadius));

    qglviewer::Vec pos6 = pos5 + qglviewer::Vec(0.0, distanceBetweenParticles, 0.0);
    qglviewer::Vec vel6 = qglviewer::Vec(0.0, -0.0, 0.0);
    particles.push_back(new Particle(pos6, vel6, particleMass, particleRadius));

    qglviewer::Vec pos7 = pos6 + qglviewer::Vec(0.0, distanceBetweenParticles, 0.0);
    qglviewer::Vec vel7 = qglviewer::Vec(0.0, -0.0, 0.0);
    particles.push_back(new Particle(pos6, vel6, particleMass, particleRadius));

    // add a spring between the two particle
    springs.push_back(new Spring(particles[0], particles[1], springStiffness, springInitLength, springDamping));
    springs.push_back(new Spring(particles[1], particles[2], springStiffness, springInitLength, springDamping));
    springs.push_back(new Spring(particles[2], particles[3], springStiffness, springInitLength, springDamping));
    springs.push_back(new Spring(particles[3], particles[4], springStiffness, springInitLength, springDamping));
    springs.push_back(new Spring(particles[4], particles[5], springStiffness, springInitLength, springDamping));
    springs.push_back(new Spring(particles[5], particles[6], springStiffness, springInitLength, springDamping));
    springs.push_back(new Spring(particles[6], particles[7], springStiffness, springInitLength, springDamping));




    // .. then create a chain of particles
}


///////////////////////////////////////////////////////////////////////////////
void Chain::draw()
{
    glPushMatrix();
    glPushAttrib(GL_COLOR_BUFFER_BIT);
    glPushAttrib(GL_CURRENT_BIT);

	// Particles
    glColor3f(0.4,0.4,0.4);
	std::vector<Particle *>::iterator itP;
	for (itP = particles.begin(); itP != particles.end(); ++itP) {
		(*itP)->draw();
	}

	// Springs
    glColor3f(0.6, 0.6, 0.6);
    glLineWidth(5.0);
	std::vector<Spring *>::iterator itS;
	for (itS = springs.begin(); itS != springs.end(); ++itS) {
		(*itS)->draw();
	}
    glColor3f(1.0, 1.0, 1.0);

    glPopAttrib();
    glPopAttrib();


    glPopMatrix();
}


void Chain::animate()
{

//======== 1. Compute all forces
    // map to accumulate the forces to apply on each particle
    std::map<const Particle *, qglviewer::Vec> forces;

    // weights
    std::vector<Particle *>::iterator itP;
    for (itP = particles.begin(); itP != particles.end(); ++itP) {
        Particle *p = *itP;
        forces[p] = gravity * p->getMass();
    }

    // damped springs
    std::vector<Spring *>::iterator itS;
    for (itS = springs.begin(); itS != springs.end(); ++itS) {
        Spring *s = *itS;
        qglviewer::Vec f12 = s->getCurrentForce();
        forces[s->getParticle1()] += f12;
        forces[s->getParticle2()] -= f12; // opposite force
    }

    //viscosity
    for (itP = particles.begin(); itP != particles.end(); ++itP) {
        Particle *p = *itP;
        forces[p] += -mediumViscosity * p->getVelocity();
    }


//======== 2. Integration scheme


    // update particles positions
    for (itP = particles.begin(); itP != particles.end(); ++itP) {
        Particle *p = *itP;
        p->setVelocity(p->getVelocity() + dt*(forces[p] * p->getInvMass()));
        //q = q + dt * v
        p->incrPosition(dt * p->getVelocity());
    }


//======== 3. Collisions
    if (handleCollisions) {
        for (itP = particles.begin(); itP != particles.end(); ++itP) {
            collisionParticleGround(*itP);
        }
        for(unsigned int i = 1; i < particles.size(); ++i) {
            Particle *p1 = particles[i - 1];
            Particle *p2 = particles[i];
            collisionParticleParticle(p1, p2);
        }
    }
}



void Chain::collisionParticleGround(Particle *p)
{
    // don't process fixed particles (ground plane is fixed)
    if (p->getInvMass() == 0)
        return;

    // particle-plane distance
    double penetration = (p->getPosition() - groundPosition) * groundNormal;
    penetration -= p->getRadius();
    if (penetration >= 0)
        return;

    // penetration velocity
    double vPen = p->getVelocity() * groundNormal;

    // updates position and velocity of the particle
    p->incrPosition(-penetration * groundNormal);
    p->incrVelocity(-(1 + rebound) * vPen * groundNormal);
}


void Chain::collisionParticleParticle(Particle *p1, Particle *p2)
{

}


void Chain::keyPressEvent(QKeyEvent* e, Viewer& viewer)
{
    // Get event modifiers key
    const Qt::KeyboardModifiers modifiers = e->modifiers();

        /* Controls added for Lab Session 6 "Physicall Modeling" */
        if ((e->key()==Qt::Key_G) && (modifiers==Qt::NoButton)) {
        toggleGravity = !toggleGravity;
        setGravity(toggleGravity);
        viewer.displayMessage("Set gravity to "
            + (toggleGravity ? QString("true") : QString("false")));

    } else if ((e->key()==Qt::Key_V) && (modifiers==Qt::NoButton)) {
        toggleViscosity = !toggleViscosity;
        setViscosity(toggleViscosity);
        viewer.displayMessage("Set viscosity to "
            + (toggleViscosity ? QString("true") : QString("false")));

    } else if ((e->key()==Qt::Key_C) && (modifiers==Qt::NoButton)) {
        toggleCollisions = !toggleCollisions;
        setCollisionsDetection(toggleCollisions);
        viewer.displayMessage("Detects collisions "
            + (toggleCollisions ? QString("true") : QString("false")));

    } else if ((e->key()==Qt::Key_Home) && (modifiers==Qt::NoButton)) {
        // stop the animation, and reinit the scene
        viewer.stopAnimation();
        init(viewer);
        viewer.manipulatedFrame()->setPosition(getFixedParticlePosition());
        toggleGravity = true;
        toggleViscosity = true;
        toggleCollisions = true;
    }
}

void Chain::mouseMoveEvent(QMouseEvent*, Viewer& v)
{
        setFixedParticlePosition(v.manipulatedFrame()->position());
}
