#include "sceneBase.hpp"

void sceneBase::changeScene(std::shared_ptr<sceneBase> scene){
    currentFrame = scene;
}