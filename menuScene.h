#pragma once


#include "sceneBase.h"
#include "massageIcon.h"
#include "menuWindow.h"


class menuScene : public sceneBase{
public:
    menuScene(std::shared_ptr<sceneManage>);
    void draw();
    void update();
    
    void touchesBegan(cinder::app::TouchEvent event);
    void touchesMoved(cinder::app::TouchEvent event);
    void touchesEnded(cinder::app::TouchEvent event);
    void mouseDown(cinder::app::MouseEvent event){}
    
private:
    messageIconSP m_message_icon;
    menuWindowSP m_menuwindow;
    Vec3f closeicon_translate;
    Vec3f closeicon_scale;
    float animation;
};
