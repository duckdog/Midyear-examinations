#include "kobito_00.h"
#include "cinder/Rand.h"
#include "timeManage.h"

#include <vector>
kobito_00::kobito_00() :
m_id(SpriteID::kobito_s00),m_pass(("kobito_s00.png")){
  
}

kobito_00SP kobito_00::create(){
    
    
    if((object::m_objects.size() - 2) <= 50){
    kobito_00SP obj = kobito_00SP(new kobito_00());
      
    resourceManage::getinstace().add(obj->m_id,obj->m_pass);
    obj->m_object_id      = ObjectID::Kobito_s00;
    obj->m_rote_power     = 10.6f;
    obj->ry               = 0;
    obj->m_condition      = 60 * 10;
    obj->random_dir       = randBool();
    obj->obj_number       = 0 + (object::m_objects.size() - 2); //召喚円と地球分を引いた数。
    obj->m_color          = Color(randFloat(0.2,0.4),randFloat(0.8,1),randFloat(0.7,1));
    obj->m_animationframe = 0;
    obj->m_pos            = Vec2f(.0f,getWindowHeight()/2 - (kobito_sResize * 3));
    obj->m_resize         = Area(obj->m_pos.x,obj->m_pos.y,
                             kobito_sResize + obj->m_pos.x,kobito_sResize + obj->m_pos.y);
    obj->move_interval  = randInt(0,60);

   
    object::m_objects.push_back(obj);

    return obj;
    }
    
    return nullptr;

}
kobito_00SP kobito_00::create(Vec2f pos,int condition){
    
    kobito_00SP obj = kobito_00SP(new kobito_00());
    
    obj->m_object_id    = ObjectID::Kobito_s00;
    obj->m_rote_power   = 0.6f;
    obj->ry             = 0;
    obj->m_condition    = 60 * 10;
    obj->random_dir     = randBool();
    obj->obj_number     = 0 + (object::m_objects.size() - 2); //召喚円と地球分を引いた数。
    obj->m_color        = Color(randFloat(0.2,0.4),randFloat(0.8,1),randFloat(0.7,1));
    obj->m_animationframe = 0;
    obj->m_pos          = Vec2f(pos);
    resourceManage::getinstace().add(obj->m_id,obj->m_pass);
    obj->m_resize       = Area(obj->m_pos.x,obj->m_pos.y,
                               kobito_sResize + obj->m_pos.x,kobito_sResize + obj->m_pos.y);
    
    obj->move_interval  = randInt(0,60);
    object::m_objects.push_back(obj);
    
  
    return obj;
}


void kobito_00::update(){
    
//
//   animatons
//   移動、画像アニメーション等
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    
    for(int i = 0; i <= timeManage::getInstance().gaptime * 60; i++ ){
        
        m_condition--;
        
        //地球にrotation.
        std::list<objectSP>::iterator it = m_objects.begin();
        (*it)->m_rotation += m_rote_power;
    
        
        if(m_condition <= 0){
            m_condition  = 0;
            m_rote_power = 0;
            break;
        }
    }
     //移動設定
     if(  m_pos.y >= 0 + obj_number && m_condition != 0) m_pos.y--;
    // 画面内を左右に移動。
    if(m_pos.x >= -getWindowWidth() * 0.5 && m_pos.x <= getWindowWidth() * 0.5 - kobito_sResize
       && m_condition != 0){
       
        if(m_animationframe == 0){
            random_dir = randBool();
          move_interval = randInt(-20,60);
        }
        else if(m_animationframe < 30 + move_interval){
            if(random_dir) m_pos.x += 1;
            else m_pos.x -= 1;
        }
    }
    //画面外に出たら、画面内に強制的に戻す.
    if(m_pos.x < -getWindowWidth() * 0.5) m_pos.x =  -getWindowWidth() * 0.5;
    if(m_pos.x > getWindowWidth() * 0.5 - kobito_sResize) m_pos.x = getWindowWidth() * 0.5 - kobito_sResize;
        
    //小人画像のアニメーション
    m_animationframe++;

    if(random_dir && m_condition > 0){
        if((m_animationframe / 10) % 2 == 0){
            m_default_size = Area(0 + kobito_sW,0,kobito_sW * 2,kobito_sH);
        }
        else{
            m_default_size = Area(0,0,kobito_sW,kobito_sH);
        }
    }else if(!random_dir && m_condition > 0){
        if((m_animationframe / 10) % 2 == 0){
            m_default_size = Area(0 + kobito_sW,kobito_sH,kobito_sW * 2,kobito_sH * 2);
        }
        else{
            m_default_size = Area(0,kobito_sH,kobito_sW,kobito_sH * 2);
        }
    }else{
        if((m_animationframe / 30) % 2 == 0){
            m_default_size = Area(0 + kobito_sW,kobito_sH * 2,kobito_sW * 2,kobito_sH *  3);
        }
        else{
            m_default_size = Area(0,kobito_sH * 2,kobito_sW,kobito_sH * 3);
        }

    }
        
    //アニメーションカウントが増えすぎるを防止.
    if(m_animationframe > 60) m_animationframe = 0;
  
  
}

void kobito_00::draw(){
    gl::pushModelView();
    gl::color(m_color);
    m_resize = Area(m_pos.x,m_pos.y,kobito_sResize + m_pos.x,kobito_sResize + m_pos.y);
    gl::draw(resourceManage::getinstace().getsprite(m_id),
            m_default_size,m_resize);
    gl::popModelView();
}



void kobito_00::touchesBegan(TouchEvent event){
    //vector 型だったので、タッチイベントの要素（関数）を取り出すために　touchIter を作成。かな？
    for (std::vector<TouchEvent::Touch>::const_iterator touchIter = event.getTouches().begin();
         touchIter != event.getTouches().end();
         touchIter++) {
        
        //タッチの位置を取得。
        Vec2f Window   = Vec2f(getWindowWidth() * 0.5, getWindowHeight() * 0.5);
        Vec2f TouchPos = Vec2f(touchIter->getX() - Window.x,
                               touchIter->getY() - Window.y);
        
        //取得したタッチ位置とオブジェクトの位置の当たり判定,
        //オブジェクトの領域にはいっていればremove.
        if(TouchPos.x > m_pos.x && TouchPos.x < m_pos.x + kobito_sResize &&
           TouchPos.y > m_pos.y && TouchPos.y < m_pos.y + kobito_sResize){
           

            }
         }
  
  
}

void kobito_00::touchesMoved(TouchEvent event){
    for(std::vector<TouchEvent::Touch>::const_iterator touchIter = event.getTouches().begin();
        touchIter != event.getTouches().end();
        touchIter++){
        //タッチの位置を取得。
        Vec2f Window   = Vec2f(getWindowWidth() * 0.5, getWindowHeight() * 0.5);
        Vec2f TouchPos = Vec2f(touchIter->getX() - Window.x,
                               touchIter->getY() - Window.y);
        
        if(TouchPos.x > m_pos.x && TouchPos.x < m_pos.x + kobito_sResize &&
           TouchPos.y > m_pos.y && TouchPos.y < m_pos.y + kobito_sResize){
            
            if(m_condition == 0){
              m_life = 0;
            }
            
            // object::remove();
        }

        
    }
}
