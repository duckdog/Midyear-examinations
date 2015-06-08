
#include "menuWindow.h"



menuWindow::menuWindow() :
m_id{SpriteID::menuicon,SpriteID::closeicon},
m_pass{"menu.png","close.png"}{
    
    resourceManage::getinstace().add(m_id[0],m_pass[0]);
    resourceManage::getinstace().add(m_id[1],m_pass[1]);
                                     
    is_touch = false;
    touch_count = 0;
    m_pos[0] = Vec3f(-50,0,0);
    m_pos[1] = Vec3f(100,0,0);
    
    m_scale = Vec3f(0,0,0);
    m_tgt_scale = Vec3f(60,90,-5);
    rx = ry = rz = 0;
    effect_count = 0;
    
    is_changescene = false;
    
}



void menuWindow::update(){
    effect_count += 0.01f;
    ry += std::sin(effect_count);
   // m_scale.x +=  std::sin(effect_count);
   // m_scale.y +=  std::sin(effect_count);

      if(touch_count > 0){
        touch_count++;
          if(touch_count > 60){
              touch_count = 0;
          }
      }
}

void menuWindow::draw(){

    gl::enableDepthWrite();
    gl::enableDepthRead();
    if(is_touch){
        if(touch_count < 3)
        m_scale +=  (m_tgt_scale - m_scale) * 0.09f;
        else{
            m_scale.y -=   m_scale.y * 0.1f;
            if(m_scale.y <= 1){
                m_scale = Vec3f(0,0,0);
                touch_count = 0;
                is_touch = false;
            }

        }
        gl::pushModelView();
        gl::color(ColorA(1,1,1,1));
        gl::translate(m_pos[0]);
        gl::rotate(Vec3f(rx,ry,rz));
        gl::scale(m_scale);
        resourceManage::getinstace().getsprite(m_id[0]).bind();
        
        gl::drawCube(Vec3f(0,0,0),Vec3f(1,1,1));
        resourceManage::getinstace().getsprite(m_id[0]).unbind();
        gl::popModelView();

    }
    gl::disableDepthWrite();
    gl::disableDepthRead();

    
}
bool menuWindow::changescene(){
    
    bool change = is_changescene;
    return change;
}

void menuWindow::touchesBegan(cinder::app::TouchEvent event){
    
    for(std::vector<TouchEvent::Touch>::const_iterator touch_Iter = event.getTouches().begin();
        touch_Iter != event.getTouches().end();
        touch_Iter++){
        //タッチの位置を取得。
        Vec2f Window   = Vec2f(getWindowWidth() * 0.5, getWindowHeight() * 0.5);
        Vec2f TouchPos = Vec2f(touch_Iter->getX() - Window.x,
                               touch_Iter->getY() - Window.y);
        
        
        
        
        touch_count++;
        m_touch_starting_pos = TouchPos;
        if(TouchPos.x > m_pos[0].x - m_tgt_scale.x * 0.5 && TouchPos.x < m_pos[0].x  + m_tgt_scale.x * 0.5 &&
           TouchPos.y > m_pos[0].y - m_tgt_scale.y * 0.5 && TouchPos.y < m_pos[0].y  + m_tgt_scale.y * 0.5){
            console() << "Open Menu" << std::endl;
            is_changescene = true;
        }

        
        if(touch_count > 1){
            if(is_touch){
                
                
                

            }
            else{ is_touch =true;
            
            
            touch_count = 0;
            ry = 0;
            effect_count = 0;
            m_scale = Vec3f(0,0,0);
            m_pos[0] = Vec3f(TouchPos.x,TouchPos.y - 100,0);
            if(TouchPos.x + m_tgt_scale.x * 0.5 > Window.x) m_pos[0].x  = Window.x - m_tgt_scale.x * 0.5;
            if(TouchPos.y - m_tgt_scale.y  < -Window.y) m_pos[0].y = -Window.y + m_tgt_scale.y ;
            }
        }
        
    }
    
}

void menuWindow::touchesMoved(cinder::app::TouchEvent event){
    for(std::vector<TouchEvent::Touch>::const_iterator touch_Iter = event.getTouches().begin();
        touch_Iter != event.getTouches().end();
        touch_Iter++){
        
        

    }

    
}

void menuWindow::touchesEnded(cinder::app::TouchEvent event){
    //is_touch = false;
    //touch_count = 0;
}