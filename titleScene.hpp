#pragma once

#include "sceneBase.hpp"

class sceneManage;

class titleScene : public sceneBase{
public:
    titleScene(sceneManage*);
	void draw();
    void update();
    void touchBegan(cinder::app::TouchEvent event){}

};
