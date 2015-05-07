#include "titleScene.hpp"
#include "sceneManage.hpp"

titleScene::titleScene(std::shared_ptr<sceneManage> manage) :
sceneBase(manage) {}

void titleScene::draw(){
    
    gl::clear(Color(0,0,1));
}

void titleScene::update(){
    
}

