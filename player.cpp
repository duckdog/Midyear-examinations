#include "player.h"


player::player() : m_id(SpriteID::Player),m_pass(("daruikoidle.png")){
    
    
    m_pos = Vec2f(0,0);
    m_size = Vec2f(player_W,player_H);

}

void player::update(){
    
}

void player::draw(){
  
    gl::draw(resourceManage::getinstace().getsprite(m_id),
             m_pos);
}


