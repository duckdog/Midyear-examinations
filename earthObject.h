#pragma once

#include "object.h"
#include "common.h"

class earth;
typedef std::shared_ptr<earth> earthSP;


class earth : public object  {
    
public:
    earth();
    void update();
    void draw();
    static earthSP create();
    void touchesBegan(TouchEvent event){}
    void touchesMoved(TouchEvent event){}
    void touhesEnded(TouchEvent event){}
    
private:
    // 面情報を定義
    // 三角形の頂点と色
    struct earthObj{
        Vec3f v1,v2,v3;
        Color color;
    };
     std::vector<earthObj> earthobj;
    
    float rx;
    float ry;
    float rz;
    
    
    Vec3f trans;
    Vec3f rote;
    Vec3f scal;
};