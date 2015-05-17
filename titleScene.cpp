#include "titleScene.h"
#include "sceneManage.h"


titleScene::titleScene(std::shared_ptr<sceneManage> manage) :
sceneBase(manage){
    
    resourceManage::getinstace().add(m_player.m_id,
                                     m_player.m_pass);
}

void titleScene::draw(){
    cinder::gl::clear(cinder::Color(0,0,1));
    m_player.draw();
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