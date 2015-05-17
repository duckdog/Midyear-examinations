#include "player.h"


player::player() : m_id(SpriteID::Player),m_pass(("daruikoidle.png")){
    
    
    m_pos = Vec2f(0,0);
    m_size = Vec2f(player_W,player_H);
    
    //resourceManage::getinstace().add(m_id,m_pass);
    /*const objectData& objectdata,const spriteInfo& tabledata) :
     m_own(Player,Vec2f(.0f,.0f),Vec2f(player_W,player_H)),
     table_data(SpriteID::Player,"daruikoidle.png"*/
    //resourceManage::getinstace().add(table_data);
}

void player::update(){
    
}

void player::draw(){
  
    gl::draw(resourceManage::getinstace().getsprite(m_id),
             m_pos);
    //

}


