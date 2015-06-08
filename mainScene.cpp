#include "common.h"
#include "mainScene.h"
#include "sceneManage.h"
#include "kobito_00.h"
#include "earthObject.h"
#include "summonsCircle.h"
#include "touchPaticle.h"
#include "timeManage.h"
#include "menuScene.h"

static bool is_first_play = true;
mainScene::mainScene(std::shared_ptr<sceneManage> manage) :
sceneBase(manage),
m_id(SpriteID::main_bg),m_pass("gamemain2.png"),
use_size(Area(-getWindowWidth()/2,-getWindowHeight()/2,getWindowWidth()/2,getWindowHeight()/2)),
base_size(Area(0,0,640,1435)),
m_drawnumber(drawNumberSP(new drawNumber())),
m_menuWindow(menuWindowSP(new menuWindow())){

 //背景画像を取得
 resourceManage::getinstace().add(m_id,m_pass);
 
 //残像オブジェクトを取得.
    if(is_first_play){
  summonsCircle::create();
  earth::create();
  object::survivor_kobitocreate();
        is_first_play = false;
    }
}


void mainScene::update(){
    
    object::exUpdate();
    m_drawnumber->drawroteupdate();
    m_drawnumber->drawrimitupdate(object::getKobitoamount(),50);
    m_menuWindow->update();
    timeManage::getInstance().checking_lag();
    
    if(m_menuWindow->changescene()){
        m_manage->changeScene(std::make_shared<menuScene>(m_manage));
    }

     /*
   //２秒に一回セーブ
   if(static_cast<int>(getElapsedSeconds()) % 2  == 0){
      timeManage::getInstance().save_shutdown();
      object::shutdown();
    }*/
}

void mainScene::draw(){
    cinder::gl::clear(cinder::Color(0,0,0));
    
    gl::color(1,1,1);
    gl::draw(resourceManage::getinstace().getsprite(m_id),base_size,use_size);
    object::exDraw();
    m_drawnumber->drawrotecount();
    m_drawnumber->drawrimitcount();
    m_menuWindow->draw();
    
}




void mainScene::touchesBegan(cinder::app::TouchEvent event){
   

    object::exTouchesBegan(event);
    m_menuWindow->touchesBegan(event);
    
 }
void mainScene::touchesMoved(cinder::app::TouchEvent event){
    object::exTouchesMoved(event);
    m_menuWindow->touchesMoved(event);
    
}

void mainScene::touchesEnded(cinder::app::TouchEvent event){
    object::exTouchesEnded(event);
    m_menuWindow->touchesEnded(event);

    
}



