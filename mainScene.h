#pragma once

#include "sceneBase.h"
#include "resources.h"
#include "drawNumber.h"
#include "menuWindow.h"
class mainScene : public sceneBase{
public:
    mainScene(std::shared_ptr<sceneManage>);
    void draw();
    void update();
    
    void touchesBegan(cinder::app::TouchEvent event);
    void touchesMoved(cinder::app::TouchEvent event);
    void touchesEnded(cinder::app::TouchEvent event);

    void mouseDown(cinder::app::MouseEvent event){}
    
private:
   // earth m_earth;
      //背景画像と、パス定義用
    const SpriteID m_id;
    const std::string& m_pass;
    const Area use_size;
    const Area base_size;
    drawNumberSP m_drawnumber;
    menuWindowSP m_menuWindow;
 
    bool is_changescene;
    static bool first_play_mainScene;
};
