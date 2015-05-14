#include "player.h"
#include "objectManage.h"

player::player(std::shared_ptr<objectManage> objmanage,
               const objectData& objectdata,const spriteInfo& tabledata) :
object(objmanage),
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
