#include "summonsCircle.h"
#include "kobito_00.h"
#include <vector>
summonsCircle::summonsCircle():
m_id(SpriteID::summons_circle),m_pass("summons_circle.png"){
   
    
}

summonsCircleSP summonsCircle::create(){
    
    summonsCircleSP obj = summonsCircleSP(new summonsCircle());
    //画像の表示比率（倍率？）
    //位置
    //元画像の切り取り位置
    //切り取った画像をひょうじさせる、位置、サイズ
    float ratio =  0.4f;
    obj->m_pos = Vec2f(-(summons_W *  ratio) * 0.5,getWindowHeight() * 0.5 - (summons_H *  ratio) * 3);
    obj->m_default_size = Area(0,0,summons_W,summons_H);
    obj->m_resize = Area(obj->m_pos.x,obj->m_pos.y,
                         (summons_W *  ratio) + obj->m_pos.x,(summons_H *  ratio) + obj->m_pos.y);

    resourceManage::getinstace().add(obj->m_id,obj->m_pass);

    object::m_objects.push_back(obj);

    return obj;
}


void summonsCircle::draw(){
    gl::color(Color(1,1,1));
      gl::draw(resourceManage::getinstace().getsprite(m_id),
         m_default_size,
         m_resize);
}

void summonsCircle::update(){
    
}


void summonsCircle::touchesBegan(TouchEvent event){
    
    for(std::vector<TouchEvent::Touch>::const_iterator touchIter = event.getTouches().begin();
        touchIter != event.getTouches().end();
        touchIter++){
        //タッチの位置を取得。
        Vec2f Window   = Vec2f(getWindowWidth() * 0.5, getWindowHeight() * 0.5);
        Vec2f TouchPos = Vec2f(touchIter->getX() - Window.x,
                               touchIter->getY() - Window.y);
     
        if(TouchPos.x > m_pos.x && TouchPos.x < m_pos.x + summons_W * 0.4 &&
           TouchPos.y > m_pos.y && TouchPos.y < m_pos.y + summons_H * 0.4){
            
            kobito_00::create();
            
        }
    }
}

void summonsCircle::touchesMoved(TouchEvent event){
    for(std::vector<TouchEvent::Touch>::const_iterator touchIter = event.getTouches().begin();
        touchIter != event.getTouches().end();
        touchIter++){
        //タッチの位置を取得。
        Vec2f Window   = Vec2f(getWindowWidth() * 0.5, getWindowHeight() * 0.5);
        Vec2f TouchPos = Vec2f(touchIter->getX() - Window.x,
                               touchIter->getY() - Window.y);
        
        if(TouchPos.x > m_pos.x && TouchPos.x < m_pos.x + summons_W * 0.4 &&
           TouchPos.y > m_pos.y && TouchPos.y < m_pos.y + summons_H * 0.4){
            
            kobito_00::create();
            
        }
    }

    
}