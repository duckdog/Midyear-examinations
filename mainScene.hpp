#pragma once

#include "sceneBase.hpp"

class sceneBase;
class mainScene : public sceneBase{
public:
    void draw();
    void update();
    
    void touchBegan(TouchEvent event){}
};
