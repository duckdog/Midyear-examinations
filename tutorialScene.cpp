#include "tutorialScene.h"
#include "sceneManage.h"

tutorialScene::tutorialScene(std::shared_ptr<sceneManage> manage) :
sceneBase(manage){
    is_touch = false;
    
}

void tutorialScene::draw(){
    gl::clear(Color(1,1,1));
    gl::color(1,1,1);
      if(is_touch){
        if(m_manage->Fadeout()){
            m_manage->changeScene(std::make_shared<mainScene>(m_manage));
        }
    }
    
}

void tutorialScene::update(){
    
}

//
void tutorialScene::mouseDown(cinder::app::MouseEvent event){
    if(event.LEFT_DOWN)
        m_manage->changeScene(std::make_shared<mainScene>(m_manage));
}

//app用
void tutorialScene::touchesBegan(cinder::app::TouchEvent event){
    is_touch = true;
      
}