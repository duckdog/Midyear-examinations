#include "player.h"


player::player(const objectData& objectdata,const spriteInfo& tabledata) :
m_own(Player,Vec2f(.0f,.0f),Vec2f(player_W,player_H)),
table_data(SpriteID::Player,"daruikoidle.png"){
    //resourceManage::getinstace().add(table_data);
    
    
}

void player::update(){
    
}

void player::draw(){
  
    gl::draw(resourceManage::getinstace().getsprite(m_own.m_id),
             m_own.m_pos);
    //

}
