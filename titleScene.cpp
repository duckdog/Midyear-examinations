#include "titleScene.h"
#include "sceneManage.h"
#include "timeManage.h"
#include "kobito_00.h"
#include "common.h"
#include "cinder/Font.h"

titleScene::titleScene(std::shared_ptr<sceneManage> manage) :
sceneBase(manage){
    test = true;
  
}

void titleScene::draw(){
    gl::clear(Color(1,1,1));
   }

void titleScene::update(){
}

//
void titleScene::mouseDown(cinder::app::MouseEvent event){
    if(event.LEFT_DOWN)
    m_manage->changeScene(std::make_shared<mainScene>(m_manage));
}

//app用
void titleScene::touchesBegan(cinder::app::TouchEvent event){
   m_manage->changeScene(std::make_shared<mainScene>(m_manage));
    
}