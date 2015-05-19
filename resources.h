#pragma once
#include "common.h"
#include <map>

enum SpriteID{
    Player,
    main_bg,//
    ALL_sprite,
};

/*struct spriteInfo{
    SpriteID m_id;
    std::string m_pass;
};*/

class resourceManage{
private:
    
    resourceManage();
    std::map<SpriteID, gl::Texture> m_graph;//:キーを指定、テクスチャを保持
    
public:
    SpriteID m_id;
    std::string m_pass;
    static resourceManage& getinstace();
    void add(const SpriteID&,const std::string&);
    void remove(const SpriteID);
    void clear();
    
   gl::Texture getsprite(const SpriteID);
    
    
};

