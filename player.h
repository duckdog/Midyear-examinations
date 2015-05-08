#pragma once

#include "object.h"


class player : public object{

public:

    player();
    std::shared_ptr<object> m_player;
    void update();
    void draw();

private:
    cinder::gl::Texture sample_player;
        
};