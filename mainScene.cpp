
#include "mainScene.h"
#include "sceneManage.h"
#include "object.h"


mainScene::mainScene(std::shared_ptr<sceneManage> manage,
                     std::shared_ptr<object> objects) :
sceneBase(manage,objects){}

void mainScene::draw(){
    cinder::gl::clear(cinder::Color(1,0,0));
}

void mainScene::update(){
    
}

