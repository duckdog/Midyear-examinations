#pragma once

#include "object.h"


enum SpriteSize{
    player_W = 256,
    player_H = 256,
    
};

class player : public object{

public:
    player();
 
    void update();
    void draw();
    const SpriteID m_id;
    const std::string& m_pass;

private:
      //  const objectData m_own;
   
    Vec2f m_pos;
    Vec2f m_size;
};