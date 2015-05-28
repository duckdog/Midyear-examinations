#include "titleScene.h"
#include "sceneManage.h"
#include "timeManage.h"
#include "kobito_00.h"
titleScene::titleScene(std::shared_ptr<sceneManage> manage) :
sceneBase(manage){
    timeManage::getInstance().timeget();
    timeManage::getInstance().writetime();
    timeManage::getInstance().loadtime();
    

}

void titleScene::draw(){
    cinder::gl::clear(cinder::Color(0,0,1));
    gl::drawString("Mawasukobito_ios",Vec2f(0,0));    
    //m_kobito_00.draw();
}

void titleScene::update(){
    //m_kobito_00.update();
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