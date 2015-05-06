#include "sceneManage.hpp"
#include "sceneBase.hpp"
#include "titleScene.hpp"
#include "mainScene.hpp"

//First loding scene.
sceneManage::sceneManage(){
    current_frame = std::make_shared<titleScene>(this);
}

void sceneManage::draw(){
    current_frame->draw();
}

void sceneManage::update(){
    current_frame->update();
}

void sceneManage::changeScene(std::shared_ptr<sceneBase> swicth_scene){
 current_frame = swicth_scene;
 }