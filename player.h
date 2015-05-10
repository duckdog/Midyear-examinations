#pragma once

#include "object.h"
#include "resources.h"

struct objectData{
    SpriteID m_id;
    
    Vec2f m_pos;
    Vec2f m_size;
};


class player : public object{

public:

    player(const SpriteID&);
    std::shared_ptr<object> m_player;
    void update();
    void draw();

private:
    cinder::gl::Texture sample_player;
    objectData m_own;
    
};