#include "common.h"
#include "mainScene.h"
#include "sceneManage.h"
#include "object.h"


mainScene::mainScene(std::shared_ptr<sceneManage> manage) :
sceneBase(manage),
m_id(SpriteID::main_bg),m_pass("main_bg.png"),
use_size(Area(-getWindowWidth()/2,-getWindowHeight()/2,getWindowWidth()/2,getWindowHeight()/2)),
base_size(Area(0,0,640,1435)){

    //背景画像を取得.
   resourceManage::getinstace().add(m_id,m_pass);
   
}

void mainScene::draw(){
    cinder::gl::clear(cinder::Color(0,0,0));
    
    gl::color(1,1,1);
    gl::draw(resourceManage::getinstace().getsprite(m_id),
             base_size,use_size);
   // m_earth.draw();
}

void mainScene::update(){
   // m_earth.update();
   
}

void mainScene::touchesBegan(cinder::app::TouchEvent event){
   
}

