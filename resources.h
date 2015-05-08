#pragma once
#include <map>
#include "common.h"

enum SpriteID{
    Player,
    
    ALL_sprite,
};

enum SpriteSize{
    player_W = 256,
    player_H = 256,
    
};

class resourceManage{
private:
    
    resourceManage();
    std::map<SpriteID, gl::Texture> m_graph;//:キーを指定、テクスチャを保持
    
public:
    static resourceManage getinstace();
    
   gl::Texture getsprite(const SpriteID);
    
    
};

