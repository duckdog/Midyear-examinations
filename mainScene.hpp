#pragma once

#include "sceneBase.hpp"

class sceneManage;

class mainScene : public sceneBase{
public:
    mainScene(sceneManage*);
    void draw();
    void update();
    
    void touchBegan(cinder::app::TouchEvent event){}
};
