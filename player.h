#pragma once

#include "object.h"


enum SpriteSize{
    player_W = 256,
    player_H = 256,
    
};

class player : public object{

public:
    player(const objectData&,const spriteInfo&);
 
    void update();
    void draw();
    
    const spriteInfo table_data;
private:
        const objectData m_own;
    
};