#pragma once
#include "common.h"
#include "cinder/TriMesh.h"
#include "resources.h"
#define PI 3.141592

enum kobito_iconSpriteSize{
    kobito_iconW = 128,
    kobito_iconH = 128,
    kobito_iconResize = 70,
};



class chooseKobitoIcon;
typedef std::shared_ptr<chooseKobitoIcon> KobitoIconSP;

class chooseKobitoIcon{
public:
    
    chooseKobitoIcon();
    ~chooseKobitoIcon(){}
    
    
    void update();
    void draw();
       
    void touchesBegan(TouchEvent event);
    void touchesMoved(TouchEvent event);
    void touchesEnded(TouchEvent event);
    inline const int gettypenumber(){return  kobito_type_number;}
    
    
private:
    float rx,ry,rz;
    Vec3f translates[2];
    Vec3f scales[2];
    ColorA colors[4];
    float move_count;
    int   move_range;
    
    TriMesh mesh;
    bool is_touch;
    bool is_fadeout;
    int fade_count;
    bool is_touchmove;
    
    const SpriteID m_id;
    const std::string m_pass;
    Vec2f m_pos;
    Area m_default_size;
    Area m_resize;
    
    int kobito_type_number;
    Vec2f m_starting_touchpos;
    
};