#pragma once

#include "sceneBase.h"
class player;

class titleScene : public sceneBase{
public:
    titleScene(std::shared_ptr<sceneManage>,
               std::shared_ptr<object>);
	void draw();
    void update();
    
    void touchesBegan(cinder::app::TouchEvent event);
    void mouseDown(cinder::app::MouseEvent event);

private:
    std::shared_ptr<player> m_player;
    
};
