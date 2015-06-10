#pragma once
#include "common.h"
#include "cinder/TriMesh.h"
#include "resources.h"


typedef std::shared_ptr<class swipArrow> swipArrowSP;
class swipArrow{
public:
    swipArrow();
    swipArrow(float arrow_space);
    
    ~swipArrow(){}
    
    void update();
    void update(float pos_y);
    void draw();



private:
    TriMesh mesh;
    float rx,ry,rz;
    Vec3f translates[2];
    Vec3f scales[2];
    ColorA colors[4];
    float move_count;
    int   move_range;
    
};