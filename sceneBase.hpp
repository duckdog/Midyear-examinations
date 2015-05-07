
#pragma once

class sceneManage;

class sceneBase{
public:
    virtual void update()= 0;
    virtual void draw()= 0;
    virtual void touchBegan(cinder::app::TouchEvent event) = 0;
protected:
    sceneBase(std::shared_ptr<sceneManage>);
    std::shared_ptr<sceneManage> m_manage;
    
};


