#include "sceneManage.hpp"
#include "sceneBase.hpp"
#include "titleScene.hpp"

sceneManage::sceneManage(){
 changeScene(std::make_shared<titleScene>());
}

void sceneManage::draw(){
    current_frame->draw();
}

void sceneManage::update(){
    current_frame->update();
}

void sceneManage::changeScene(std::shared_ptr<sceneBase> scene){
 current_frame = scene;
 }