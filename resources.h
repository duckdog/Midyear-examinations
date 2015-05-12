#pragma once
#include "common.h"
#include <map>


enum SpriteID{
    Player,
    
    ALL_sprite,
};
struct spriteInfo{
    spriteInfo(SpriteID,std::string);
    SpriteID m_id;
    std::string m_pass;
};


class resourceManage{
private:
    
    resourceManage();
    std::map<SpriteID, gl::Texture> m_graph;//:キーを指定、テクスチャを保持
    
public:
    static resourceManage& getinstace();
    void add(const spriteInfo&);
    void remove(const SpriteID);
    void clear();
    
   gl::Texture getsprite(const SpriteID);
    
    
};

