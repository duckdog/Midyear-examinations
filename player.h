#pragma once

#include "object.h"


enum SpriteSize{
    player_W = 256,
    player_H = 256,
    
};

class player : public object{

public:
    player(const spriteInfo&);
    void update();
    void draw();

private:
    const spriteInfo m_resinfo;
    //const objectData m_objdata;
    
};