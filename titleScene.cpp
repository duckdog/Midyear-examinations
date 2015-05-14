#include "titleScene.h"
#include "sceneManage.h"
#include "player.h"

titleScene::titleScene(std::shared_ptr<sceneManage> manage,
                       std::shared_ptr<object> objects) :
sceneBase(manage,objects){
    
    //resourceManage::getinstace().add(m_player->table_data);
}

void titleScene::draw(){
    cinder::gl::clear(cinder::Color(0,0,1));
    m_player->draw();
}

void titleScene::update(){
    
}

//
void titleScene::mouseDown(cinder::app::MouseEvent event){
    if(event.LEFT_DOWN)
    m_manage->changeScene(std::make_shared<mainScene>(m_manage),
                          std::make_shared<object>(m_obj));
}

//app用
void titleScene::touchesBegan(cinder::app::TouchEvent event){
    m_manage->changeScene(std::make_shared<mainScene>(m_manage),
                          std::make_shared<object>(m_obj));
}