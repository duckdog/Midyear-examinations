#pragma once

#include "object.h"
#include "resources.h"

enum SpriteSize{
    player_W = 256,
    player_H = 256,
    
};

class player : public object{

public:
    player();
    ~player(){}
    
    void update();
    void draw();
    
    const SpriteID m_id;
    const std::string m_pass;

      //  const objectData m_own;
    int m_animationframe;
    Vec2f m_pos;
    Area m_default_size;
    Area m_resize;
private:
    
};