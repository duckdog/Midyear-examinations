#pragma once

#include "sceneBase.h"
#include "resources.h"


class TutorialScene : public sceneBase{
public:
    TutorialScene(std::shared_ptr<sceneManage>);
    void draw();
    void update();
    
    void setText();
    void touchesBegan(cinder::app::TouchEvent event);
    void touchesMoved(cinder::app::TouchEvent event){}
    void touchesEnded(cinder::app::TouchEvent event){}
    
    void mouseDown(cinder::app::MouseEvent event);
    
private:
    bool is_touch;
    
    const std::vector<SpriteID> m_ids;
    const std::vector<std::string> m_passes;
    
    int current_text_number;
    gl::Texture m_past_text;
    gl::Texture m_current_text;
    gl::Texture m_next_text;
    
  };
