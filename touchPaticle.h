#pragma once
#include "common.h"

#include "cinder/TriMesh.h"
#include "cinder/Camera.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Light.h"
#include "cinder/Rand.h"

///class touchParticle;
//typedef std::shared_ptr<touchParticle> touchParticleSP;

class touchParticle{
public:
    touchParticle();
    ~touchParticle(){}

    void update();
    void draw();
    //static touchParticleSP getInstance();
    void touchesBegan(TouchEvent event);
    void touchesMoved(TouchEvent event);
    void touchesEnded(TouchEvent event);

private:
    std::unique_ptr<gl::Light> light;
    float rx,ry,rz;
    TriMesh mesh;
};