#include "titleScene.h"
#include "sceneManage.h"

titleScene::titleScene(std::shared_ptr<sceneManage> manage) :
sceneBase(manage) {}

void titleScene::draw(){
    
    cinder::gl::clear(cinder::Color(0,0,1));
}

void titleScene::update(){
    
}

