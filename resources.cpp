
#include "resources.h"

#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>


resourceManage::resourceManage():
mSurfaceComposite(getWindowWidth(),getWindowHeight(),true){
   }


//画像取得
gl::Texture resourceManage::getsprite(const SpriteID id){
    auto it = m_graph.find(id);
    return it->second;
}

//リソースクラスの取得
resourceManage& resourceManage::getinstace(){
    static resourceManage resource;
    return resource;
}


//追加（そのまま）
void resourceManage::add(const SpriteID& m_id,const std::string& m_pass){
    
    m_graph.insert
    (std::make_pair(m_id,gl::Texture(loadImage(loadResource(m_pass)))));
}
//追加（画像リサイズ用）
void resourceManage::add(const SpriteID& m_id,const std::string& m_pass,
                         const Area use_area,const Area pos_area){
    
    //画像のリサイズ処理.
    Surface imageSurface(loadImage(loadResource(m_pass)));
    ci::ip::resize(imageSurface,use_area,&mSurfaceComposite,
                   pos_area,FilterSincBlackman());
    
    m_graph.insert
    (std::make_pair(m_id,gl::Texture(mSurfaceComposite)));
}


//個別消去
void resourceManage::remove(const SpriteID id){
    auto it = m_graph.find(id);
    m_graph.erase(it);
    
}

//完全消去
void resourceManage::clear(){
    m_graph.clear();
}


