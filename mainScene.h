#pragma once

#include "sceneBase.h"



class mainScene : public sceneBase{
public:
    mainScene(std::shared_ptr<sceneManage>);
    void draw();
    void update();
    
    void touchBegan(cinder::app::TouchEvent event){}
};
