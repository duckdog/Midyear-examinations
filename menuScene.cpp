#include "menuScene.h"

menuScene::menuScene(std::shared_ptr<sceneManage> manage) :
sceneBase(manage),
m_message_icon(messageIconSP(new messageIcon()))
{
    //背景画像を取得
    
    //残像オブジェクトを取得.
    
}


void menuScene::update(){
    m_message_icon->update();


}

void menuScene::draw(){
    
    cinder::gl::clear(cinder::Color(1,1,1));
    
    m_message_icon->draw();
    
}


void menuScene::touchesBegan(cinder::app::TouchEvent event){
    
    
    m_message_icon->touchesBegan(event);
    
}
void menuScene::touchesMoved(cinder::app::TouchEvent event){
    
    
    m_message_icon->touchesMoved(event);
    
}

void menuScene::touchesEnded(cinder::app::TouchEvent event){
    
    
    m_message_icon->touchesEnded(event);
}
