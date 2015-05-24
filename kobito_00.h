#pragma once

#include "object.h"
#include "resources.h"

enum SpriteSize{
    kobito_sW = 128,
    kobito_sH = 128,
    kobito_sResize = 35,
};

class kobito_00;
typedef std::shared_ptr<kobito_00> kobito_00SP;

class kobito_00 : public object{
    
public:
    ~kobito_00(){}
    
    void update();
    void draw();
    static kobito_00SP create();
    void touchesBegan(TouchEvent event);
    void touchesMoved(TouchEvent event);
    void touchesEnded(TouchEvent event){}
    //スプライトデータ
    const SpriteID m_id;
    const std::string m_pass;

    //const objectData m_own;
    int m_animationframe;
    Vec2f m_pos;
    Area m_default_size;
    Area m_resize;
private:
     kobito_00();
};