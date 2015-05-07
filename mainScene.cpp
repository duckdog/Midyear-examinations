
#include "mainScene.hpp"
#include "sceneManage.cpp"

mainScene::mainScene(std::shared_ptr<sceneManage> manage) :
sceneBase(manage){}

void mainScene::draw(){
    cinder::gl::clear(Color(1,0,0));
}

void mainScene::update(){
    
}

