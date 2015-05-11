#include "player.h"


player::player(const spriteInfo& tableData) :
m_resinfo(tableData){
    resourceManage::getinstace().add(m_resinfo);
  
    //m_own(Player,Vec2f(.0f,.0f),Vec2f(player_W,player_H))

}

void player::update(){
    
}

void player::draw(){
  
    //gl::draw(resourceManage::getinstace().getsprite(m_own.m_id),
    //         m_own.m_pos);
    //

}

//シングルトン　＜マップ＞コンテナの理解