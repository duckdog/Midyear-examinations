#pragma once
#include "common.h"
#include "cinder/TriMesh.h"
#include "resources.h"
#include "swipArrow.h"
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
    inline const int getTypeNumber() const {return  kobito_type_number;}
    
    
private:
   
    swipArrowSP m_swiparrow;
    bool is_touch;
    bool is_fadeout;
    int fade_count;
    float move_count;
    int   move_range;
    bool is_touchmove;
    const SpriteID m_id;
    const std::string m_pass;
    Vec2f m_pos;
    Area m_default_size;
    Area m_resize;
    int kobito_type_number;
    Vec2f m_starting_touchpos;
    
    
    
    
};