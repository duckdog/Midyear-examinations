#include "player.h"
#include "cinder/Rand.h"
#include <vector>
player::player() :
m_id(SpriteID::kobito_s00),m_pass(("kobito_s00.png"))
{
   /*     obj->m_animationframe = 0;
    obj->m_pos = Vec2f(.0f + randFloat(-100,100),getWindowHeight()/2 - (kobito_sResize * 3) + randFloat(-100,100));
    obj->resourceManage::getinstace().add(m_id,m_pass);
    obj->m_resize = Area(m_pos.x,m_pos.y,kobito_sResize + m_pos.x,kobito_sResize + m_pos.y);
    
    
    object::m_objects.push_back(this);
    */
}

playerSP player::create(){
    
    playerSP obj = playerSP(new player());
    obj->m_animationframe = 0;
    obj->m_pos = Vec2f(.0f + randFloat(-100,100),getWindowHeight()/2 - (kobito_sResize * 3) + randFloat(-100,100));
    resourceManage::getinstace().add(obj->m_id,obj->m_pass);
    obj->m_resize = Area(obj->m_pos.x,obj->m_pos.y,
                         kobito_sResize + obj->m_pos.x,kobito_sResize + obj->m_pos.y);
    
    
    object::m_objects.push_back(obj);
    return obj;

}


void player::update(){
    //小人画像のアニメーション
    m_animationframe++;
    if((m_animationframe / 6) % 2 == 0){
        m_default_size = Area(0 + kobito_sW,0,kobito_sW * 2,kobito_sH);
    }
    else{
        m_default_size = Area(0,0,kobito_sW,kobito_sH);
    }
    //移動
    m_resize = Area(m_pos.x,m_pos.y,kobito_sResize + m_pos.x,kobito_sResize + m_pos.y);
    
    console() << m_pos << std::endl;
}

void player::draw(){
    gl::color(Color(1,1,1));
  gl::draw(resourceManage::getinstace().getsprite(m_id),
            m_default_size,m_resize);

}


void player::touchesBegan(cinder::app::TouchEvent event){
    //
    for (std::vector<TouchEvent::Touch>::const_iterator touchIter = event.getTouches().begin();
         touchIter != event.getTouches().end();
         touchIter++) {
        
        
         }

    
}

void player::touchesMoved(cinder::app::TouchEvent event){
    
}
