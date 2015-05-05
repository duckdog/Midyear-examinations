#include "sceneBase.hpp"

sceneBase::sceneBase(){}

void sceneBase::changeScene(std::shared_ptr<sceneBase> scene){
    currentFrame = scene;
}
