#pragma once

#include "sceneBase.h"



class titleScene : public sceneBase{
public:
    titleScene(std::shared_ptr<sceneManage>);
	void draw();
    void update();
 
    void mouseDown(cinder::app::MouseEvent event);


};
