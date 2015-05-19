#pragma once

#include "sceneBase.h"
#include "earthObject.h"
#include "resources.h"
class mainScene : public sceneBase{
public:
    mainScene(std::shared_ptr<sceneManage>);
    void draw();
    void update();
    
    void touchesBegan(cinder::app::TouchEvent event);
    void mouseDown(cinder::app::MouseEvent event){}
    
private:
   // earth m_earth;
      //背景画像と、パス定義用
    const SpriteID m_id;
    const std::string& m_pass;
    const Area use_size;
    const Area base_size;
};
