#include "common.h"
#include "mainScene.h"
#include "sceneManage.h"
#include "kobito_00.h"
#include "earthObject.h"
#include "summonsCircle.h"
#include "touchPaticle.h"
#include "timeManage.h"

mainScene::mainScene(std::shared_ptr<sceneManage> manage) :
sceneBase(manage),
m_id(SpriteID::main_bg),m_pass("main_bg.png"),
use_size(Area(-getWindowWidth()/2,-getWindowHeight()/2,getWindowWidth()/2,getWindowHeight()/2)),
base_size(Area(0,0,640,1435)){

 //背景画像を取得
 resourceManage::getinstace().add(m_id,m_pass);
 
 //地球（立方体）を取得.
  
  summonsCircle::create();
  earth::create();
}

void mainScene::draw(){
    cinder::gl::clear(cinder::Color(0,0,0));
    
    gl::color(1,1,1);
    gl::draw(resourceManage::getinstace().getsprite(m_id),
             base_size,use_size);
    object::exDraw();
}

void mainScene::update(){
    timeManage::getInstance().timeget();
   // timeManage::getInstance().loadtime();
      object::exUpdate();
}

void mainScene::touchesBegan(cinder::app::TouchEvent event){
    
    object::exTouchesBegan(event);

 }
void mainScene::touchesMoved(cinder::app::TouchEvent event){
    object::exTouchesMoved(event);
     m_manage->changeScene(std::make_shared<titleScene>(m_manage));
    
}


