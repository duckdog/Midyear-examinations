#include "player.h"

player::player(){
    sample_player = gl::Texture(loadImage(loadResource("daruikoidle.png")));
}

void player::update(){
    
}

void player::draw(){
    gl::draw(sample_player,Vec2f(256,256));
}