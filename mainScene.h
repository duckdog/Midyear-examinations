#pragma once

#include "sceneBase.h"
#include "earthObject.h"


class mainScene : public sceneBase{
public:
    mainScene(std::shared_ptr<sceneManage>);
    void draw();
    void update();
    
    void touchesBegan(cinder::app::TouchEvent event){}
    void mouseDown(cinder::app::MouseEvent event){}
    
private:
    earth m_earth;
    
};
