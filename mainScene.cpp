#include "common.h"
#include "mainScene.h"
#include "sceneManage.h"
#include "object.h"


mainScene::mainScene(std::shared_ptr<sceneManage> manage) :
sceneBase(manage),
m_id(SpriteID::main_bg),m_pass("main_bg.png"),
bg_pos(Vec2f(-getWindowWidth()/2,-getWindowHeight()/2)){

    //背景画像を取得.
   resourceManage::getinstace().add(m_id,m_pass);
}

void mainScene::draw(){
    cinder::gl::clear(cinder::Color(1,1,1));
    
    m_earth.draw();
    
    gl::color(1,1,1);
    gl::draw(resourceManage::getinstace().getsprite(m_id),
             getWindowBounds());

}

void mainScene::update(){
    m_earth.update();
}

