#include "chooceKobitoIcon.h"


chooseKobitoIcon::chooseKobitoIcon():
m_id(SpriteID::kobito_icon),m_pass("kobito_icon.png"),
kobito_type_number(0),
m_swiparrow(swipArrowSP(new swipArrow()))
{
    m_pos = Vec2f(- kobito_iconResize * 0.5,getWindowHeight() /2 - kobito_iconResize);
    m_default_size = Area(0,0,kobito_iconW,kobito_iconH);
    m_resize = Area(m_pos.x,m_pos.y,kobito_iconResize + m_pos.x, kobito_iconResize + m_pos.y);
    
  
  //  //アイコン画像を追加。
    resourceManage::getinstace().add(m_id,m_pass);

    

  
    is_touchmove = false;
    fade_count = 0;
    move_count = 0;
    move_range = 6;
}





void chooseKobitoIcon::update(){
    move_count += 0.05f;
    
    m_default_size = Area(0  + kobito_iconW * kobito_type_number,0,
                          kobito_iconW * (kobito_type_number + 1),kobito_iconH);
    m_pos.y += std::sin(move_count) * 0.2;
    m_swiparrow->update();
}

void chooseKobitoIcon::draw(){
  
    
    gl::pushModelView();
    gl::rotate(Vec3f(0,move_count * 10,0));
    m_resize = Area(m_pos.x,m_pos.y,kobito_iconResize + m_pos.x, kobito_iconResize + m_pos.y);
    gl::draw(resourceManage::getinstace().getsprite(m_id),
             m_default_size,m_resize);
    gl::popModelView();

    m_swiparrow->draw();
    
    
    
        // gl::disable(GL_LIGHTING);
 


}





void chooseKobitoIcon::touchesBegan(TouchEvent event){
    
    for(auto touchIter = event.getTouches().cbegin();
        touchIter != event.getTouches().end();
        touchIter++){
        //タッチの位置を取得。
        Vec2f Window   = Vec2f(getWindowWidth() * 0.5, getWindowHeight() * 0.5);
        Vec2f TouchPos = Vec2f(touchIter->getX() - Window.x,
                               touchIter->getY() - Window.y);
        m_starting_touchpos = TouchPos;
      }
}

void chooseKobitoIcon::touchesMoved(TouchEvent event){
    for(auto touchIter = event.getTouches().cbegin();
        touchIter != event.getTouches().end();
        touchIter++){
        //タッチの位置を取得。
        Vec2f Window   = Vec2f(getWindowWidth() * 0.5, getWindowHeight() * 0.5);
        Vec2f TouchPos = Vec2f(touchIter->getX() - Window.x,
                               touchIter->getY() - Window.y);
        
        if(TouchPos.y > (getWindowHeight() * 0.5) - kobito_iconResize){
          if(!is_touchmove){
            if(m_starting_touchpos.x > TouchPos.x + 1){
              kobito_type_number--;
                if(kobito_type_number < 0){
                    kobito_type_number = 2;
                }
              is_touchmove = true;
          }
            if(m_starting_touchpos.x < TouchPos.x - 1){
              kobito_type_number++;
                if(kobito_type_number > 2){
                    kobito_type_number = 0;
                }
              is_touchmove = true;
            }
          }
        }
    }
    
}

void chooseKobitoIcon::touchesEnded(TouchEvent event){
    is_touchmove = false;
   }
