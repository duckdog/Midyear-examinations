#include "sceneManage.h"
#include "sceneBase.h"
#include "titleScene.h"
#include "mainScene.h"



sceneManage::sceneManage(){
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
