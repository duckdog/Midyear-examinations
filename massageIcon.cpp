

#include "massageIcon.h"
#include "object.h"


messageIcon::messageIcon():
m_id(SpriteID::message_icon),
m_message_id{SpriteID::message_base,SpriteID::message_00,SpriteID::message_01,SpriteID::message_02,SpriteID::message_03,
                                    SpriteID::message_04,SpriteID::message_05},
m_pass("message_icon.png"),
m_message_pass{("message_base.png"),("message00.png"),("message01.png"),("message02.png"),("message03.png"),
                                    ("message04.png"),("message05.png")},
m_swiparrow(swipArrowSP(new swipArrow(4.5)))
{
   
    earth_rotate_ref = (*object::earth_date())->m_rotation;
    resourceManage::getinstace().add(m_id,m_pass);
    m_Texture = resourceManage::getinstace().getsprite(m_id);
    
    
    for(int i = 0; i < 8; i++){
      resourceManage::getinstace().add(m_message_id[i],m_message_pass[i]);
    }
  
    translate = Vec3f(-100,1,1);
    scale = Vec3f(100,130,30);
    m_pos   = Vec3f(0,0,0);
    m_message_pos = Vec3f(- getWindowWidth() * 0.5,-getWindowHeight() * 0.5 + 100,0);
    rx = ry = rz = 0;
    effect_count = 0;
    is_touch_message = false;
    is_openmessage = false;
    def_pos = Vec3f(translate);
    tgt_pos = Vec3f(0,200,-100);
    defalt_size = Area(0,0,menu_WH,menu_WH);
    resize      = Area(m_message_pos.x,m_message_pos.y,
                       getWindowWidth()  + m_message_pos.x,getWindowHeight() * 0.5 + m_message_pos.y);
    
    
    int turn_amount = earth_rotate_ref/360;
   
    if(turn_amount  >= 50){max_message = 6;}
    else if(turn_amount  >= 40){max_message = 5;}
    else if(turn_amount  >= 30){max_message = 4;}
    else if(turn_amount  >= 20){max_message = 3;}
    else if(turn_amount  >= 10){max_message = 2;}
    else{ max_message = 1;}

   
    current_message_number = max_message;

    message_alpfa = 0;
}





void messageIcon::update(){
    effect_count += 0.1f;
    m_swiparrow->update(110);

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
        
        extern ci::fs::path getDocumentPath();
        ci::fs::path Path = getDocumentPath();
        JsonTree ex_json;
        
        if(ci::fs::is_regular_file(Path / "Message.json")){
            ex_json = ci::JsonTree::makeObject(("Message"));
            ex_json.addChild(JsonTree("unread",false));
            ex_json.write(Path / "Message.json",JsonTree::WriteOptions().createDocument(true));
        }

      message_alpfa += (1 - message_alpfa) * 0.08f;
      //massageのベースを表示.
      gl::color(ColorA(1,1,1,0.9));
      gl::draw(resourceManage::getinstace().getsprite(m_message_id[0]),
               defalt_size,resize);
      
      gl::color(ColorA(1,1,1,message_alpfa));
      gl::draw(resourceManage::getinstace().getsprite(m_message_id[current_message_number]),
               defalt_size,resize);
    
      m_swiparrow->draw();

    }else{
        message_alpfa = 0;
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
        if(TouchPos.y < m_message_pos.y + getWindowHeight() * 0.5 &&
           TouchPos.y > m_message_pos.y){
            if(!is_touchmove){
                //右にフリック
                if(m_starting_touch_pos.x > TouchPos.x + 10){
                
                    current_message_number++;
                    if(current_message_number > max_message){
                        current_message_number = 1;
                    }
                    is_touchmove = true;
                    message_alpfa = 0;
                }
                //左にフリック
                if(m_starting_touch_pos.x < TouchPos.x - 10){
                    current_message_number--;
                    if(current_message_number < 1){
                        current_message_number = max_message;
                    }
                    is_touchmove = true;
                    message_alpfa = 0;

                }
            }
        }
        
        }
    
}

void messageIcon::touchesEnded(TouchEvent event){
    is_touchmove = false;
    
}
