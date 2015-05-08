
#include "resources.h"

struct spriteInfo{
    SpriteID m_id;
    std::string m_pass;
};

resourceManage::resourceManage(){
    const spriteInfo tableData[]{
        
        {Player,"daruikoidle.png"},
    };
    
    for(auto& it : tableData){
        m_graph.insert(std::make_pair
        (it.m_id,gl::Texture(loadImage(loadResource(it.m_pass)))));
    }
    
}

resourceManage resourceManage::getinstace(){
    static resourceManage resource;
    return resource;
}

gl::Texture resourceManage::getsprite(const SpriteID id){
    auto it = m_graph.find(id);
    return it->second;
}