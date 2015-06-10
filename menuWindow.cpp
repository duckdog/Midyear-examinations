
#include "menuWindow.h"
#include "chooceKobitoIcon.h"


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
    is_close = false;
    
}



void menuWindow::update(){
    effect_count += 0.01f;
    ry += std::sin(effect_count);
   // m_scale.x +=  std::sin(effect_count);
   // m_scale.y +=  std::sin(effect_count);

      if(touch_count > 0){
        touch_count++;
          if(touch_count > 30){
              touch_count = 0;
          }
      }
}


void menuWindow::normaldraw(bool falseis_menu_png_trueis_close_png,
                            Vec3f translate,Vec3f scale){
    
    gl::enableDepthWrite();
    gl::enableDepthRead();
    
    gl::pushModelView();
    gl::color(ColorA(1,1,1,1));
    gl::translate(translate);
    gl::rotate(Vec3f(rx,ry,rz));
    gl::scale(scale);
    resourceManage::getinstace().getsprite(m_id[falseis_menu_png_trueis_close_png]).bind();
    
    gl::drawCube(Vec3f(0,0,0),Vec3f(1,1,1));
    resourceManage::getinstace().getsprite(m_id[falseis_menu_png_trueis_close_png]).unbind();
    gl::popModelView();
    
    gl::disableDepthWrite();
    gl::disableDepthRead();
    
}



void menuWindow::draw(bool true_menu_false_close){

    gl::enableDepthWrite();
    gl::enableDepthRead();
    
    if(is_touch){
        if(!is_close)
        m_scale +=  (m_tgt_scale - m_scale) * 0.09f;

        gl::pushModelView();
        gl::color(ColorA(1,1,1,1));
        gl::translate(m_pos[0]);
        gl::rotate(Vec3f(rx,ry,rz));
        gl::scale(m_scale);
        resourceManage::getinstace().getsprite(m_id[true_menu_false_close]).bind();
        
        gl::drawCube(Vec3f(0,0,0),Vec3f(1,1,1));
        resourceManage::getinstace().getsprite(m_id[true_menu_false_close]).unbind();
        gl::popModelView();

    }
    
    
    if(is_close){
        
        m_scale.y -=   m_scale.y * 0.1f;
        if(m_scale.y <= 1){
            m_scale = Vec3f(0,0,0);
            touch_count = 0;
            is_touch = false;
            is_close = false;
            m_pos[0] = Vec3f(-getWindowWidth(),-getWindowHeight(),0);
        }
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
        
        if(TouchPos.y < getWindowHeight() * 0.5  - kobito_iconResize){
            touch_count++;
        }

        m_touch_starting_pos = TouchPos;
        if(TouchPos.x > m_pos[0].x - m_tgt_scale.x * 0.5 && TouchPos.x < m_pos[0].x  + m_tgt_scale.x * 0.5 &&
           TouchPos.y > m_pos[0].y - m_tgt_scale.y * 0.5 && TouchPos.y < m_pos[0].y  + m_tgt_scale.y * 0.5){
            console() << "Open Menu" << std::endl;
            if(!is_close)
            is_changescene = true;
        }

        
        if(touch_count > 1){
            if(is_touch){
                
                is_close = true;
                

            }
            else{
                is_touch = true;
                is_close = false;
            
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


void menuWindow::touchesBegan(cinder::app::TouchEvent event,Vec3f translate, Vec3f scale){
    
    for(std::vector<TouchEvent::Touch>::const_iterator touch_Iter = event.getTouches().begin();
        touch_Iter != event.getTouches().end();
        touch_Iter++){
        //タッチの位置を取得。
        Vec2f Window   = Vec2f(getWindowWidth() * 0.5, getWindowHeight() * 0.5);
        Vec2f TouchPos = Vec2f(touch_Iter->getX() - Window.x,
                               touch_Iter->getY() - Window.y);
        
            touch_count++;

        m_touch_starting_pos = TouchPos;
        if(TouchPos.x > translate.x - scale.x * 0.5 && TouchPos.x < translate.x  + scale.x * 0.5 &&
           TouchPos.y > translate.y - scale.y * 0.5 && TouchPos.y < translate.y  + scale.y * 0.5){
            console() << "Open Menu" << std::endl;
                        is_changescene = true;
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