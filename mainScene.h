#pragma once

#include "sceneBase.h"



class mainScene : public sceneBase{
public:
    mainScene(std::shared_ptr<sceneManage>);
    void draw();
    void update();
    
   
    void mouseDown(cinder::app::MouseEvent event){}
};
