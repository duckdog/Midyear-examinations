#include "titleScene.h"
#include "TutorialScene.h"
#include "sceneManage.h"
#include "timeManage.h"
#include "kobito_00.h"
#include "common.h"
#include "cinder/Font.h"
#include "titleName.h"
#include "earthObject.h"
titleScene::titleScene(std::shared_ptr<sceneManage> manage) :
sceneBase(manage),
m_shining_ref(shiningObjSP (new shiningObj())){
    is_touch = false;
    
   
    titleName::create();
     
}

void titleScene::draw(){
    gl::clear(Color(1,1,1));
    gl::color(1,1,1);
    object::exDraw();
    m_shining_ref->draw();
   if(is_touch){
        if(m_manage->Fadeout()){
            m_manage->changeScene(std::make_shared<TutorialScene>(m_manage));
        }
    }
    
}

void titleScene::update(){
    object::exUpdate();
    m_shining_ref->update();
}

//
void titleScene::mouseDown(cinder::app::MouseEvent event){
    if(event.LEFT_DOWN)
        m_manage->changeScene(std::make_shared<TutorialScene>(m_manage));
}

//app用
void titleScene::touchesBegan(cinder::app::TouchEvent event){
    is_touch = true;
  // m_manage->changeScene(std::make_shared<mainScene>(m_manage));
 
    
}