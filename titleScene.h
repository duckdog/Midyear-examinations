#pragma once

#include "sceneBase.h"
//#include "kobito_00.h"


class titleScene : public sceneBase{
public:
    titleScene(std::shared_ptr<sceneManage>);
    void draw();
    void update();
    
    void touchesBegan(cinder::app::TouchEvent event);
    void touchesMoved(cinder::app::TouchEvent event){}
    void touchesEnded(cinder::app::TouchEvent event){}

    void mouseDown(cinder::app::MouseEvent event);

private:
    bool test;
};
