#pragma once
#include "common.h"
#include "resources.h"

struct objectData{
    objectData(SpriteID,Vec2f,Vec2f);
    SpriteID m_id;
    
    Vec2f m_pos;
    Vec2f m_size;
};

class object{
    
public:
    virtual void update() = 0;
    virtual void draw() = 0;
protected:
    object();
};
