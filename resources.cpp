
#include "resources.h"



resourceManage::resourceManage(){
   }

gl::Texture resourceManage::getsprite(const SpriteID id){
    auto it = m_graph.find(id);
    return it->second;
}

resourceManage& resourceManage::getinstace(){
    static resourceManage resource;
    return resource;
}

void resourceManage::add(const SpriteID& m_id,const std::string& m_pass){
    
    m_graph.insert
    (std::make_pair(m_id,gl::Texture(loadImage(loadResource(m_pass)))));
}

void resourceManage::remove(const SpriteID id){
    auto it = m_graph.find(id);
    m_graph.erase(it);
    
}
void resourceManage::clear(){
    m_graph.clear();
}


