#pragma once

#include "sceneBase.h"
#include "resources.h"
#include <vector>

class TutorialScene : public sceneBase{
public:
    TutorialScene(std::shared_ptr<sceneManage>);
    void draw();
    void update();
    void fadeText();
    void setIntordactionText();
    void settutorialText();
    void touchesBegan(cinder::app::TouchEvent event);
    void touchesMoved(cinder::app::TouchEvent event){}
    void touchesEnded(cinder::app::TouchEvent event){}
    
    void mouseDown(cinder::app::MouseEvent event){}
    
private:
    bool is_touch;
    bool is_end_introdaction;
    const std::vector<SpriteID> m_intordaction_ids;
    const std::vector<SpriteID> m_tutorial_ids;
    const std::vector<std::string> m_introdaction_passes;
    const std::vector<std::string> m_tutorial_passes;
    Vec2i m_text_cutpos;
    Vec2i m_text_cutsize;
    Vec2i m_text_pos;
    Vec2i m_text_size;
    

    int current_text_number;
    gl::Texture m_past_text;
    gl::Texture m_current_text;
    gl::Texture m_next_text;
    
  };
