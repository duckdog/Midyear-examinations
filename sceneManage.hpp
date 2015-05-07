#pragma once
#include "titleScene.hpp"
#include "mainScene.hpp"

class sceneManage{
public:
    sceneManage();
    
    void update();
    void draw();
    
    void changeScene(std::shared_ptr<sceneBase> scene);
    
private:
    std::shared_ptr<sceneBase> current_frame;
    
};

