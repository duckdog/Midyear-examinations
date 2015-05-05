
#pragma once
#include "common.h"



class sceneBase{
public:
    virtual void update()= 0;
    virtual void draw()= 0;
    virtual void touchBegan(TouchEvent event) = 0;
    
    void changeScene(std::shared_ptr<sceneBase> scene);
    sceneBase();
private:
    std::shared_ptr<sceneBase> currentFrame;
};


