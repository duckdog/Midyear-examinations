#include "titleScene.h"
#include "sceneManage.h"
#include "timeManage.h"
#include "kobito_00.h"
#include "common.h"
#include "cinder/Font.h"
#include "titleName.h"
titleScene::titleScene(std::shared_ptr<sceneManage> manage) :
sceneBase(manage){
    is_touch = false;
  
    titleName::create();
}

void titleScene::draw(){
    gl::clear(Color(0,0,0));
    gl::color(1,1,1);
    object::exDraw();
   if(is_touch){
        if(m_manage->Fadeout()){
            m_manage->changeScene(std::make_shared<mainScene>(m_manage));
        }
    }
    
}

void titleScene::update(){
    object::exUpdate();
}

//
void titleScene::mouseDown(cinder::app::MouseEvent event){
    if(event.LEFT_DOWN)
    m_manage->changeScene(std::make_shared<mainScene>(m_manage));
}

//app用
void titleScene::touchesBegan(cinder::app::TouchEvent event){
    is_touch = true;
  // m_manage->changeScene(std::make_shared<mainScene>(m_manage));
 
    
}