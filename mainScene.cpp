#include "common.h"
#include "mainScene.h"
#include "sceneManage.h"
#include "object.h"


mainScene::mainScene(std::shared_ptr<sceneManage> manage) :
sceneBase(manage){}

void mainScene::draw(){
    cinder::gl::clear(cinder::Color(1,1,1));
    m_earth.draw();

}

void mainScene::update(){
    m_earth.update();
}

