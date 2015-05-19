#include "player.h"


player::player() :
m_id(SpriteID::kobito_s00),m_pass(("kobito_s00.png"))
{
    m_animationframe = 0;
    m_pos = Vec2f(0,0);
    //const Vec2f resize = Vec2f(50,50);
    //m_default_size = Area(0 + 128,0,128 + 128,128);
    //m_resize = Area(m_pos.x,m_pos.y,resize.x,resize.y);

}

void player::update(){
    m_animationframe++;
    m_resize = Area(m_pos.x,m_pos.y,40,40);
    
    if((m_animationframe / 6) % 2 == 0){
        m_default_size = Area(0 + 128,0,128 + 128,128);
    }
    else{
        m_default_size = Area(0,0,128,128);
    }
}

void player::draw(){
  gl::draw(resourceManage::getinstace().getsprite(m_id),
             m_default_size,m_resize);

}


