#pragma once

#include "sceneBase.hpp"

class sceneBase;
class titleScene : public sceneBase{
public:
	void draw();
    void update();
    void touchBegan(TouchEvent event){}
    
    titleScene();
private:
    titleScene* title;
};
