#include "titleScene.h"
#include "sceneManage.h"

titleScene::titleScene(std::shared_ptr<sceneManage> manage) :
sceneBase(manage) {
    
   }

void titleScene::draw(){
    
       cinder::gl::clear(cinder::Color(0,0,1));
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