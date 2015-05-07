#include "sceneManage.h"
#include "sceneBase.h"
#include "titleScene.h"
#include "mainScene.h"

//First loding scene.
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

void sceneManage::changeScene(std::shared_ptr<sceneBase> swicth_scene){
 current_frame = swicth_scene;
 }