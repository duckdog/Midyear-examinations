#pragma once

#include "object.h"
#include "resources.h"

enum SpriteSize{
    kobito_sW = 128,
    kobito_sH = 128,
    kobito_sResize = 30,
};

class player;
typedef std::shared_ptr<player> playerSP;

class player : public object{
    
public:
    ~player(){}
    
    void update();
    void draw();
    static playerSP create();
    void touchesBegan(TouchEvent event);
    void touchesMoved(TouchEvent event);
    
    //スプライトデータ
    const SpriteID m_id;
    const std::string m_pass;

    //const objectData m_own;
    int m_animationframe;
    Vec2f m_pos;
    Area m_default_size;
    Area m_resize;
private:
     player();
};