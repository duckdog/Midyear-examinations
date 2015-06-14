#include "TutorialScene.h"
#include "sceneManage.h"

TutorialScene::TutorialScene(std::shared_ptr<sceneManage> manage) :
sceneBase(manage),
m_ids{SpriteID::ALL_sprite},
m_passes{"NULL.png"}{
    is_touch = false;
    current_text_number = 0;
    
}

void TutorialScene::draw(){
    gl::clear(Color(1,1,1));
    gl::color(1,1,1);
      if(is_touch){
        if(m_manage->Fadeout()){
            m_manage->changeScene(std::make_shared<mainScene>(m_manage));
        }
    }
    
}

void TutorialScene::update(){
    
}

void TutorialScene::setText(){
    
    m_past_text = (current_text_number == 0)
    ? resourceManage::getinstace().getsprite(m_ids[0]) :resourceManage::getinstace().getsprite(m_ids[current_text_number - 1]);
    m_current_text = resourceManage::getinstace().getsprite(m_ids[current_text_number]);
    m_next_text = resourceManage::getinstace().getsprite(m_ids[current_text_number + 1]);
    
    current_text_number++;
}

//
void TutorialScene::mouseDown(cinder::app::MouseEvent event){
    if(event.LEFT_DOWN)
        m_manage->changeScene(std::make_shared<mainScene>(m_manage));
}

//app用
void TutorialScene::touchesBegan(cinder::app::TouchEvent event){
    is_touch = true;
    setText();
}