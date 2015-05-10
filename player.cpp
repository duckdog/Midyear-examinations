#include "player.h"


player::player(const SpriteID& sprite_id){

    const Vec2f player_size = Vec2f(player_W,player_H);
    const objectData tableData[]{
        {Player,Vec2f(.0f,.0f),player_size},
        // :other player resources
    };
    for(int i = 0; i < ALL_sprite;++i){
        if(sprite_id == tableData[i].m_id){m_own = tableData[i];}
    }
}

void player::update(){
    
}

void player::draw(){
  
    gl::draw(resourceManage::getinstace().getsprite(m_own.m_id),
             m_own.m_size);
}