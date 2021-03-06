#pragma once

#include "earthObject.h"
#include "resources.h"



enum SpriteSize{
    kobito_sW = 128,
    kobito_sH = 128,
    kobito_sResize = 26,
};

class drawNumber;
class kobito_00;
typedef std::shared_ptr<kobito_00> kobito_00SP;

class kobito_00 : public object{
    
public:
    ~kobito_00(){}
    
    void update();
    void draw();

    static kobito_00SP create(Vec2f Touchpos);
    static kobito_00SP create(Vec2f m_pos,int m_condition);
   
    void touchesBegan(TouchEvent event);
    void touchesMoved(TouchEvent event);
    void touchesEnded(TouchEvent event){}
    //スプライトデータ
    const SpriteID m_id;
    const std::string m_pass;

    
private:
     kobito_00();
    
  
    int m_animationframe;
    int obj_number;
    Color m_color;
    bool random_dir;
    int  move_interval;
    float alpfa;
    float ry;
    Vec2f m_pos;
    Area m_default_size;
    Area m_resize;
    audio::BufferPlayerNodeRef mBufferPlayerNode;
    audio::GainNodeRef gain;
    bool is_play;
    
};