#pragma once

#include "sceneBase.hpp"

class sceneBase;
class sceneManage;

class titleScene : public sceneBase{
public:
	void draw();
    void update();
    void touchBegan(TouchEvent event){}
    
    
private:
    ~
};
