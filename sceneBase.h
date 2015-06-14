
#pragma once
#include <memory>
#include "common.h"
class sceneManage;
class object;

class sceneBase{
public:
    virtual void update()= 0;
    virtual void draw()= 0;
    virtual void mouseDown(cinder::app::MouseEvent event) = 0;
    virtual void touchesBegan(cinder::app::TouchEvent event) = 0;
    virtual void touchesMoved(cinder::app::TouchEvent event) = 0;
    virtual void touchesEnded(cinder::app::TouchEvent event) = 0;
    
protected:
    sceneBase(std::shared_ptr<sceneManage>);
    std::shared_ptr<sceneManage> m_manage;
   
};


