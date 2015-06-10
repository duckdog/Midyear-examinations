#include "summonsCircle.h"
#include "kobito_00.h"
#include "kobito_M00.h"
#include "kobito_L00.h"
#include <vector>
summonsCircle::summonsCircle():
m_id(SpriteID::summons_circle),m_pass("summons_circle.png"),
interval_count(0),
alpfa(1),
m_kobito_icon_ref(KobitoIconSP(new chooseKobitoIcon())){
   
    
}

summonsCircleSP summonsCircle::create(){
    
    summonsCircleSP obj = summonsCircleSP(new summonsCircle());
    obj->m_object_id = ObjectID::SummonsCircle;
    //画像の表示比率（倍率？）
    //位置
    //元画像の切り取り位置
    //切り取った画像をひょうじさせる、位置、サイズ
    float ratio =  0.4f;
    obj->m_pos = Vec2f(-(summons_W *  ratio) * 0.5,getWindowHeight() * 0.5 - (summons_H *  ratio) * 4);
    obj->m_default_size = Area(0,0,summons_W,summons_H);
    obj->m_resize = Area(obj->m_pos.x,obj->m_pos.y,
                         (summons_W *  ratio) + obj->m_pos.x,(summons_H *  ratio) + obj->m_pos.y);
    obj->is_create = false;
    resourceManage::getinstace().add(obj->m_id,obj->m_pass);

    object::m_objects.push_back(obj);

    return obj;
}

void summonsCircle::createinterval(){
   
    interval_count++;
    if(interval_count > 10){
        is_create = false;
        interval_count = 0;
    }
}

void summonsCircle::draw(){
    gl::color(ColorA(1,1,alpfa,alpfa));
    gl::draw(resourceManage::getinstace().getsprite(m_id),
             m_default_size,
             m_resize);
    
    gl::color(ColorA(1,1,1,1));
    m_kobito_icon_ref->draw();
}

void summonsCircle::update(){
    if(is_create) createinterval();
    m_kobito_icon_ref->update();
    if(alpfa <= 1)
        alpfa += 0.01f;
}


void summonsCircle::touchesBegan(TouchEvent event){
    m_kobito_icon_ref->touchesBegan(event);
    for(std::vector<TouchEvent::Touch>::const_iterator touchIter = event.getTouches().begin();
        touchIter != event.getTouches().end();
        touchIter++){
        //タッチの位置を取得。
        Vec2f Window   = Vec2f(getWindowWidth() * 0.5, getWindowHeight() * 0.5);
        Vec2f TouchPos = Vec2f(touchIter->getX() - Window.x,
                               touchIter->getY() - Window.y);
     
        if(TouchPos.x > m_pos.x && TouchPos.x < m_pos.x + summons_W * 0.4 &&
           TouchPos.y > m_pos.y && TouchPos.y < m_pos.y + summons_H * 0.4){
        /*
            if(interval_count == 0){
                
                if(m_kobito_icon_ref->gettypenumber() == 0){
                   kobito_00::create();
                }
                else if(m_kobito_icon_ref->gettypenumber() == 1){
                    kobito_M00::create();
                }
                else if(m_kobito_icon_ref->gettypenumber() == 2){
                    kobito_L00::create();
                }


              is_create = true;
              interval_count++;
            }*/
        }
    }
}

void summonsCircle::touchesMoved(TouchEvent event){
     m_kobito_icon_ref->touchesMoved(event);
    for(std::vector<TouchEvent::Touch>::const_iterator touchIter = event.getTouches().begin();
        touchIter != event.getTouches().end();
        touchIter++){
        //タッチの位置を取得。
        Vec2f Window   = Vec2f(getWindowWidth() * 0.5, getWindowHeight() * 0.5);
        Vec2f TouchPos = Vec2f(touchIter->getX() - Window.x,
                               touchIter->getY() - Window.y);
        
        if(TouchPos.x > m_pos.x && TouchPos.x < m_pos.x + summons_W * 0.4 &&
           TouchPos.y > m_pos.y && TouchPos.y < m_pos.y + summons_H * 0.4){
            
            if(interval_count == 0){
                
                if(m_kobito_icon_ref->gettypenumber() == 0){
                    kobito_00::create(TouchPos);
                    alpfa = 0.05f;
                }
                else if(m_kobito_icon_ref->gettypenumber() == 1){
                    kobito_M00::create(TouchPos);
                    alpfa = 0.05f;
                }
                else if(m_kobito_icon_ref->gettypenumber() == 2){
                    kobito_L00::create(TouchPos);
                    alpfa = 0.05f;
                }
                
                is_create = true;
                interval_count++;
            }
            
        }
    }

    
}



void summonsCircle::touchesEnded(TouchEvent event){
    m_kobito_icon_ref->touchesEnded(event);
    
}