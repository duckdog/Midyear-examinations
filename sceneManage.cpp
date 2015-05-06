#include "sceneManage.hpp"

void sceneManage::draw(){
    current_frame->draw();
}

void sceneManage::update(){
    current_frame->update();
}

void sceneManage::changeScene(std::shared_ptr<sceneBase> scene){
 current_frame = scene;
 }