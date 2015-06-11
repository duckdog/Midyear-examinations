
#pragma once
#include "common.h"

#include "cinder/TriMesh.h"
#include "cinder/Camera.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Light.h"
#include "cinder/Rand.h"


typedef std::shared_ptr<class shiningObj> shiningObjSP;
class shiningObj{
public:
    shiningObj();
    ~shiningObj(){}
    
    static shiningObj& getInstance();
    void update();
    void draw();
    void fadeout();
    static shiningObjSP create();
    
    void touchesBegan(TouchEvent event);
    void touchesMoved(TouchEvent event);
    void touchesEnded(TouchEvent event);
    
    
private:
      float rx,ry,rz;
    
    Vec3f translates;
    Vec3f scales;
    
    
    bool is_touch;
    bool is_fadeout;
    int fade_count;
    bool is_move;
    
    float  animation = 0;
    
};