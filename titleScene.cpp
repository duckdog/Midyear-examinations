
#include "titleScene.hpp"

titleScene::titleScene(){
    changeScene(std::make_shared<titleScene>());
}

void titleScene::draw(){
    
    gl::clear(Color(0,0,1));
}

void titleScene::update(){
    
}

