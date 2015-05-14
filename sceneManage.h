#pragma once
#include "titleScene.h"
#include "mainScene.h"
#include "object.h"

class sceneManage{
public:
    sceneManage();
    
    void update();
    void draw();
    void mouseDown(cinder::app::MouseEvent event);
    void touchesBegan(cinder::app::TouchEvent event);
    void changeScene(std::shared_ptr<sceneBase> scene);
    void changeScene(std::shared_ptr<sceneBase> scene,
                     std::shared_ptr<player>);

    
private:
    std::shared_ptr<sceneBase> current_frame;
    
};

