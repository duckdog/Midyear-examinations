#include "menuScene.h"
#include "sceneManage.h"
menuScene::menuScene(std::shared_ptr<sceneManage> manage) :
sceneBase(manage),
m_message_icon(messageIconSP(new messageIcon())),
m_menuwindow(menuWindowSP(new menuWindow()))
{
    closeicon_translate = Vec3f(-100,getWindowHeight()/2 - 50,0);
    closeicon_scale = Vec3f(100,130,-1);
    animation =0;
}


void menuScene::update(){
    m_message_icon->update();
    m_menuwindow->update();
    if(m_menuwindow->changescene())
    m_manage->changeScene(std::make_shared<mainScene>(m_manage));

    
}

void menuScene::draw(){
    animation += 0.01f;
    cinder::gl::clear(cinder::Color(std::sin(animation * 2),0,std::sin(animation)));
    
    m_message_icon->draw();
    m_menuwindow->normaldraw(true,closeicon_translate,closeicon_scale);//(true);
}


void menuScene::touchesBegan(cinder::app::TouchEvent event){
    
    
    m_message_icon->touchesBegan(event);
    m_menuwindow->touchesBegan(event,closeicon_translate,closeicon_scale);
    
}
void menuScene::touchesMoved(cinder::app::TouchEvent event){
    
    
    m_message_icon->touchesMoved(event);
    }

void menuScene::touchesEnded(cinder::app::TouchEvent event){
    
    
    m_message_icon->touchesEnded(event);
}
