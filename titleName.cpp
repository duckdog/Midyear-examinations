
#include "titleName.h"
#include "cinder/Rand.h"
titleName::titleName():
m_id{SpriteID::title_0,SpriteID::title_1,SpriteID::title_2,SpriteID::title_3,
     SpriteID::title_4,SpriteID::title_5,},
m_pass{"titleName_0.png","titleName_1.png","titleName_2.png","titleName_3.png",
       "titleName_4.png","titleName_5.png"}{
}

titleNameSP titleName::create(){
    
    titleNameSP obj = titleNameSP(new titleName());
  

    obj->m_rotation = 0;
    obj->is_move = false;
    
    for(int i = 0; i < 6; i++){
        resourceManage::getinstace().add(obj->m_id[i],obj->m_pass[i]);
        obj->m_texture[i] = resourceManage::getinstace().getsprite(obj->m_id[i]);
        
    }
    float window = getWindowWidth();
    float ajust_scale = getWindowWidth() / 10;
    obj->m_scale = Vec3f(ajust_scale,ajust_scale,-ajust_scale);
    obj->m_translate = Vec3f(0,0,0);
    obj->rx = obj->ry = obj->rz = 0;
    obj->animation_count = 0;
    object::m_objects.push_back(obj);
    return obj;
    
    
}

void titleName::update(){
    //オブジェクトが持つm_rote_powerの分だけ地球を回す。
    animation_count += 0.1f;

    rz += std::sin(animation_count);
}



void titleName::draw(){
    
    
       gl::enableDepthWrite();
    gl::enableDepthRead();
    
    
    
    gl::clear(Color(1,1,1));
    for(int i = 0; i < 6 ;i++){
    gl::pushModelView();

    m_texture[i].bind();
    m_translate = Vec3f(-getWindowWidth() * 0.5 + (m_scale.x) + ((m_scale.x + 10) * i) ,0,0);
    gl::translate(m_translate);
    gl::scale(m_scale);
    gl::rotate(Vec3f(rx,ry,rz));
    gl::drawCube(Vec3f(0,0,0),Vec3f(1,1,1));
    m_texture[i].unbind();
    gl::popModelView();
   
    }
  

    
    gl::disableDepthRead();
    gl::disableDepthWrite();
    
 }
    
