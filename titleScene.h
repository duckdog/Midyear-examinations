#pragma once

#include "sceneBase.h"



class titleScene : public sceneBase{
public:
    titleScene(std::shared_ptr<sceneManage>);
	void draw();
    void update();
    
    void touchesBegun(cinder::app::TouchEvent event);
    void mouseDown(cinder::app::MouseEvent event);


};
