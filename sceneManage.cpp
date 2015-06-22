#include "sceneManage.h"
#include "sceneBase.h"
#include "titleScene.h"
#include "mainScene.h"
#include "menuScene.h"
#include "touchPaticle.h"


sceneManage::sceneManage():
m_fade_id(SpriteID::fade),
m_fade_pass("white.png"),
fadeout_alpfa(0),
fadein_alpfa(1){
   resourceManage::getinstace().add(m_fade_id,m_fade_pass);
   m_fadetexture = resourceManage::getinstace().getsprite(m_fade_id);
}

void sceneManage::draw(){
    current_frame->draw();
}

void sceneManage::update(){
    current_frame->update();

}


void sceneManage::mouseDown(cinder::app::MouseEvent event){
    current_frame->mouseDown(event);
}

void sceneManage::touchesBegan(cinder::app::TouchEvent event){
        current_frame->touchesBegan(event);
}

void sceneManage::touchesMoved(cinder::app::TouchEvent event){
    current_frame->touchesMoved(event);
}
void sceneManage::touchesEnded(cinder::app::TouchEvent event){
    current_frame->touchesEnded(event);
}

void sceneManage::changeScene(std::shared_ptr<sceneBase> swicth_scene){
    current_frame = swicth_scene;
}

bool sceneManage::Fadeout(){
    fadeout_alpfa += 0.1f;
    gl::color(ColorA(1,1,1,fadeout_alpfa));
    gl::draw(m_fadetexture,Vec2f(-getWindowWidth() * 0.5,-getWindowHeight() * 0.5));
    return fadeout_alpfa > 1.5;
    
}



bool sceneManage::Fadein(){
    fadein_alpfa -= 0.1f;
    gl::color(ColorA(1,1,1,fadein_alpfa));
    gl::draw(m_fadetexture,Vec2f(-getWindowWidth() * 0.5,-getWindowHeight() * 0.5));
    return fadein_alpfa <= 0;
    
}
