
#pragma once
#include "common.h"
#include "sceneManage.hpp"

class sceneManage;

class sceneBase{
public:
    
    virtual void update()= 0;
    virtual void draw()= 0;
    virtual void touchBegan(TouchEvent event) = 0;
protected:
    sceneBase(sceneManage*);
    sceneManage* _manage;
    
};


