#pragma once

#include "earthObject.h"
#include "resources.h"


enum kobito_L00SpriteSize{
    kobito_L00W = 128,
    kobito_L00H = 128,
    kobito_L00Resize = 50,
};


class kobito_L00;

typedef std::shared_ptr<kobito_L00> kobito_L00SP;

class kobito_L00 : public object{
    
public:
    ~kobito_L00(){}
    
    void update();
    void draw();
    
    static kobito_L00SP create(Vec2f Touchpos);
    static kobito_L00SP create(Vec2f m_pos,int m_condition);
    
    void touchesBegan(TouchEvent event);
    void touchesMoved(TouchEvent event);
    void touchesEnded(TouchEvent event){}
    //スプライトデータ
    const SpriteID m_id;
    const std::string m_pass;
    
    
private:
    kobito_L00();
    
    
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