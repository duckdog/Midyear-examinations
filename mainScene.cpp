
#include "mainScene.h"
#include "sceneManage.h"

mainScene::mainScene(std::shared_ptr<sceneManage> manage) :
sceneBase(manage){}

void mainScene::draw(){
    cinder::gl::clear(cinder::Color(1,0,0));
}

void mainScene::update(){
    
}

