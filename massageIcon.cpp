

#include "massageIcon.h"



messageIcon::messageIcon():
m_id(SpriteID::message_icon),
m_message_id{SpriteID::message_base,SpriteID::message_00,SpriteID::message_01},
m_pass("message_icon.png"),
m_message_pass{("message_base.png"),("message00.png"),("message01.png")}
{
   
    resourceManage::getinstace().add(m_id,m_pass);
    m_Texture = resourceManage::getinstace().getsprite(m_id);
    for(int i = 0; i < 3; i++){
      resourceManage::getinstace().add(m_message_id[i],m_message_pass[i]);
    }
  
    translate = Vec3f(-100,1,1);
    scale = Vec3f(100,130,30);
    m_pos   = Vec3f(0,0,0);
    rx = ry = rz = 0;
    effect_count = 0;
    is_touch_message = false;
    def_pos = Vec3f(translate);
    tgt_pos = Vec3f(0,200,-100);
    defalt_size = Area(0,0,menu_WH,menu_WH);
    resize      = Area(-getWindowWidth() * 0.5,-getWindowHeight() * 0.5 + 100,
                       getWindowWidth()-getWindowWidth() * 0.5,getWindowHeight() * 0.5 -getWindowHeight() * 0.5+ 100);
    
    
    
}





void messageIcon::update(){
      effect_count += 0.1f;
    
    if(!is_touch_message){
      rx -= std::sin(effect_count);
        translate += (def_pos - translate) * 0.1f;
    }
    else{
        rx = 10;
        translate += (tgt_pos - translate) * 0.1f;
        
    }
    
    
}

void messageIcon::draw(){
    
    gl::pushModelView();
    gl::enableDepthRead();
    gl::enableDepthWrite();
  
    m_Texture.bind();
    gl::translate(translate);
    gl::rotate(Vec3f(rx,ry,rz));
    gl::scale(scale);
    gl::drawCube(m_pos,Vec3f(1,1,1));
    m_Texture.unbind();
    
    gl::disableDepthRead();
    gl::disableDepthWrite();
    gl::popModelView();
    
    
    
    gl::pushModelView();
    if(is_openmessage){
      gl::color(ColorA(1,1,1,0.5));
      gl::draw(resourceManage::getinstace().getsprite(m_message_id[0]),
               defalt_size,resize);
      
      gl::color(ColorA(1,1,1,1));
      gl::draw(resourceManage::getinstace().getsprite(m_message_id[1]),
               defalt_size,resize);
    }
    gl::popModelView();

}



void messageIcon::touchesBegan(TouchEvent event){
    
    for(std::vector<TouchEvent::Touch>::const_iterator touchIter = event.getTouches().begin();
        touchIter != event.getTouches().end();
        touchIter++){
        //タッチの位置を取得。
        Vec2f Window   = Vec2f(getWindowWidth() * 0.5, getWindowHeight() * 0.5 );
        Vec2f TouchPos = Vec2f(touchIter->getX() - Window.x,
                               touchIter->getY() - Window.y);
        
        m_starting_touch_pos = TouchPos;
        if(TouchPos.x > m_pos.x + translate.x - (scale.x * 0.5) && TouchPos.x < m_pos.x + translate.x + scale.x * 0.5  &&
           TouchPos.y > m_pos.y + translate.y - (scale.y * 0.5) && TouchPos.y  < m_pos.y + translate.y + scale.y * 0.5){
            if(is_touch_message){
                is_touch_message = false;
                is_openmessage = false;
            }
            else{
                is_touch_message = true;
                is_openmessage = true;
            }
        }


    }
}

void messageIcon::touchesMoved(TouchEvent event){
    for(std::vector<TouchEvent::Touch>::const_iterator touchIter = event.getTouches().begin();
        touchIter != event.getTouches().end();
        touchIter++){
        //タッチの位置を取得。
        Vec2f Window   = Vec2f(getWindowWidth() * 0.5, getWindowHeight() * 0.5);
        Vec2f TouchPos = Vec2f(touchIter->getX() - Window.x,
                               touchIter->getY() - Window.y);
        
        
        }
    
}

void messageIcon::touchesEnded(TouchEvent event){
    
}
