#pragma once

#include "sceneBase.hpp"

class sceneBase;
class titleScene : public sceneBase{
public:
    titleScene();
	void draw();
    void update();
    void touchBegan(TouchEvent event){}
    
    
private:
    ~titleScene();
};
