#pragma once
#include "titleScene.h"
#include "mainScene.h"


class sceneManage{
public:
    sceneManage();
    
    void update();
    void draw();
    void mouseDown(cinder::app::MouseEvent event);
    void touchesBegan(cinder::app::TouchEvent event);
    void touchesMoved(cinder::app::TouchEvent event);
    void touchesEnded(cinder::app::TouchEvent event);

    void changeScene(std::shared_ptr<sceneBase> scene);
    
    
private:
    std::shared_ptr<sceneBase> current_frame;
    
};

