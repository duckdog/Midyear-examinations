#include "TutorialScene.h"
#include "sceneManage.h"

TutorialScene::TutorialScene(std::shared_ptr<sceneManage> manage) :
sceneBase(manage),
m_intordaction_ids{SpriteID::introdaction_0,SpriteID::introdaction_1,SpriteID::introdaction_2,SpriteID::introdaction_3},
m_tutorial_ids{SpriteID::tutorial_0,SpriteID::tutorial_1,SpriteID::tutorial_2,SpriteID::tutorial_3,SpriteID::tutorial_4},
m_introdaction_passes{"introdaction_0.png","introdaction_1.png","introdaction_2.png","introdaction_3.png"},
m_tutorial_passes{"tutorial_summons.png","tutorial_choose.png","tutorial_kind.png","tutorial_dareru.png","tutorial_menuicon.png"}
{

    is_touch = false;
    is_end_introdaction = false;
    is_end_tutorial = false;
    current_text_number = 0;
    m_text_cutpos = Vec2i(0,0);
    m_text_cutsize = Vec2i(500,1000);
    m_endtext_pos = Vec2i(0,0);
    m_endtext_size = Vec2i(500,1000);
    m_text_pos = Vec2i(-getWindowWidth() * 0.5f,-getWindowHeight() * 0.5f);
    m_text_size = Vec2i(getWindowWidth()/2,getWindowHeight()/2);
    m_endtext_pos = Vec2i(0,0);
    m_endtext_size = Vec2i(150,51);
    
    for(int i = 0; i < m_intordaction_ids.size(); i++){
      resourceManage::getinstace().add(m_intordaction_ids[i],m_introdaction_passes[i]);
    }
    for(int i = 0; i < m_tutorial_ids.size();i++){
        resourceManage::getinstace().add(m_tutorial_ids[i],m_tutorial_passes[i]);
    }
    
}

void TutorialScene::update(){
    m_manage->Fadein();
    setIntordactionText();
    //ストーリー説明が終わった後、チュートリアル画面へ.
    if(is_end_introdaction) settutorialText();
}

void TutorialScene::draw(){
    gl::clear(Color(1,1,1));
    gl::color(1,1,1);
    
    gl::draw(m_current_text,
             Area(m_text_cutpos,m_text_cutsize),
             Area(m_text_pos,m_text_size));
    
  /*  if(is_end_introdaction){
        gl::draw(m_current_text,
             Area(m_endtext_cutpos,m_endtext_cutsize),
             Area(m_endtext_pos,m_endtext_size));
    }*/
}

void TutorialScene::fadeText(){
    
    
}


void TutorialScene::setIntordactionText(){
    //ストーリー説明が終わったら、チュートリアルに移るフラグを立てる.
    if(current_text_number > 3 && !is_end_introdaction){
      is_end_introdaction = true;
      current_text_number = 0;
    }
    else{
      //チュートリアルのせつめいが終わったら本編へ.
      if(m_tutorial_ids.size() - 1 <= current_text_number) {
          m_manage->changeScene(std::make_shared<mainScene>(m_manage));
      }
      else{
         // if(m_tutorial_ids.size() - 1 <= current_text_number){current_text_number = 0;}
          m_current_text = resourceManage::getinstace().getsprite(m_intordaction_ids[current_text_number]);
      }
    }
}

//チュートリアル用の画像を準備
void TutorialScene::settutorialText(){
    //一番最初の画像だったら、過去の一個前の画像を準備しない.s
    m_past_text = (current_text_number == 0)
    ? resourceManage::getinstace().getsprite(m_tutorial_ids[0]) :resourceManage::getinstace().getsprite(m_tutorial_ids[current_text_number - 1]);
    
    m_current_text = resourceManage::getinstace().getsprite(m_tutorial_ids[current_text_number]);
    m_next_text = resourceManage::getinstace().getsprite(m_tutorial_ids[current_text_number + 1]);
   
}



//app用
void TutorialScene::touchesBegan(cinder::app::TouchEvent event){
    is_touch = true;
    current_text_number++;
}