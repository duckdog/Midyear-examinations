#pragma once

#include "sceneBase.h"
#include "player.h"

class titleScene : public sceneBase{
public:
    titleScene(std::shared_ptr<sceneManage>);
    void draw();
    void update();
    
    void touchesBegan(cinder::app::TouchEvent event);
    void mouseDown(cinder::app::MouseEvent event);

private:
    player m_player;
    
};
