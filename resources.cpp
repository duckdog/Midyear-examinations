
#include "resources.h"



resourceManage::resourceManage(){
   /* const spriteInfo tableData[]{
        
        {Player,"daruikoidle.png"},
    };
    
    for(auto& it : tableData){
        m_graph.insert(std::make_pair
        (it.m_id,gl::Texture(loadImage(loadResource(it.m_pass)))));
    }
    */
}

gl::Texture resourceManage::getsprite(const SpriteID id){
    auto it = m_graph.find(id);
    return it->second;
}

resourceManage& resourceManage::getinstace(){
    static resourceManage resource;
    return resource;
}
void resourceManage::add(const spriteInfo& spriteinfo){
    
    m_graph.insert
    (std::make_pair(spriteinfo.m_id,gl::Texture(loadImage(loadResource(spriteinfo.m_pass)))));
}

void resourceManage::remove(const SpriteID id){
    auto it = m_graph.find(id);
    m_graph.erase(it);
    
}
void resourceManage::clear(){
    m_graph.clear();
}


