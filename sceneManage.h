#pragma once
#include "common.h"
#include "titleScene.h"
#include "mainScene.h"
#include "resources.h"

class sceneManage{
public:
    sceneManage();
    
    void update();
    void draw();
    void mouseDown(cinder::app::MouseEvent event);
    void touchesBegan(cinder::app::TouchEvent event);
    void touchesMoved(cinder::app::TouchEvent event);
    void touchesEnded(cinder::app::TouchEvent event);

    void changeScene(std::shared_ptr<sceneBase> scene);
    bool Fadeout();
    bool Fadein();

    
    
private:
    std::shared_ptr<sceneBase> current_frame;
    SpriteID m_fade_id;
    std::string m_fade_pass;
    gl::Texture m_fadetexture;
    float fadein_alpfa;
    float fadeout_alpfa;
};

