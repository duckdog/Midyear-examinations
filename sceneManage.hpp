#pragma once
#include "common.h"
#include <memory>

class sceneBase;

class sceneManage{
public:
    sceneManage();
    
    void update();
    void draw();
    
    void changeScene(std::shared_ptr<sceneBase> scene);
    
private:
    std::shared_ptr<sceneBase> current_frame;
    
};

