
#include "kobito_M00.h"
#include "cinder/Rand.h"
#include "timeManage.h"

#include <vector>
kobito_M00::kobito_M00() :
m_id(SpriteID::kobito_m00),m_pass(("kobito_M00.png"))
{
    
}

kobito_M00SP kobito_M00::create(){
    
    
    if((object::m_objects.size() - 2) < 50){
        kobito_M00SP obj = kobito_M00SP(new kobito_M00());
        
        resourceManage::getinstace().add(obj->m_id,obj->m_pass);
        obj->m_object_id      = ObjectID::Kobito_m00;
        obj->m_rote_power     = 0.6f;
        obj->ry               = 0;
        obj->m_condition      = 60 * 10;
        obj->m_animationframe = 0;
        obj->random_dir       = randBool();
        obj->obj_number       = 0 + (object::m_objects.size() - 2); //召喚円と地球分を引いた数。
        obj->m_color          = Color(1,1,1);
        obj->m_pos            = Vec2f(.0f,getWindowHeight()/2 - (kobito_M00Resize * 3));
        obj->m_resize         = Area(obj->m_pos.x,obj->m_pos.y,
                                     kobito_M00Resize + obj->m_pos.x,kobito_M00Resize + obj->m_pos.y);
        obj->move_interval  = randInt(0,60);
        
        
        object::m_objects.push_back(obj);
        
        return obj;
    }
    
    return nullptr;
    
}
kobito_M00SP kobito_M00::create(Vec2f pos,int condition){
    
    kobito_M00SP obj = kobito_M00SP(new kobito_M00());
    
    obj->m_object_id    = ObjectID::Kobito_m00;
    obj->m_rote_power   = 0.6f;
    obj->ry             = 0;
    obj->m_condition    = 60 * 10;
    obj->random_dir     = randBool();
    obj->obj_number     = 0 + (object::m_objects.size() - 2); //召喚円と地球分を引いた数。
    obj->m_color        = Color(1,1,1);
    obj->m_animationframe = 0;
    obj->m_pos          = Vec2f(pos);
    resourceManage::getinstace().add(obj->m_id,obj->m_pass);
    obj->m_resize       = Area(obj->m_pos.x,obj->m_pos.y,
                               kobito_M00Resize + obj->m_pos.x,kobito_M00Resize + obj->m_pos.y);
    
    obj->move_interval  = randInt(0,60);
    object::m_objects.push_back(obj);
    
    
    return obj;
}


void kobito_M00::update(){
    
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
    if(m_pos.x >= -getWindowWidth() * 0.5 && m_pos.x <= getWindowWidth() * 0.5 - kobito_M00Resize
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
    if(m_pos.x > getWindowWidth() * 0.5 - kobito_M00Resize) m_pos.x = getWindowWidth() * 0.5 - kobito_M00Resize;
    
    //小人画像のアニメーション
    m_animationframe += 1;
    
    if(random_dir && m_condition > 0){
        if((m_animationframe / 20) % 2 == 0){
            m_default_size = Area(0 + kobito_M00W,0,kobito_M00W * 2,kobito_M00H);
        }
        else{
            m_default_size = Area(0,0,kobito_M00W,kobito_M00H);
        }
    }else if(!random_dir && m_condition > 0){
        if((m_animationframe / 20) % 2 == 0){
            m_default_size = Area(0 + kobito_M00W,kobito_M00H,kobito_M00W * 2,kobito_M00H * 2);
        }
        else{
            m_default_size = Area(0,kobito_M00H,kobito_M00W,kobito_M00H * 2);
        }
    }else{
        if((m_animationframe / 20) % 2 == 0){
            m_default_size = Area(0 + kobito_M00W,kobito_M00H * 2,kobito_M00W * 2,kobito_M00H *  3);
        }
        else{
            m_default_size = Area(0,kobito_M00H * 2,kobito_M00W,kobito_M00H * 3);
        }
        
    }
    
    //アニメーションカウントが増えすぎるを防止.
    if(m_animationframe > 120) m_animationframe = 0;
    
    
}

void kobito_M00::draw(){
    gl::pushModelView();
    gl::color(m_color);
    m_resize = Area(m_pos.x,m_pos.y,kobito_M00Resize + m_pos.x,kobito_M00Resize + m_pos.y);
    gl::draw(resourceManage::getinstace().getsprite(m_id),m_default_size,m_resize);
    
    gl::popModelView();
}



void kobito_M00::touchesBegan(TouchEvent event){
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
        if(TouchPos.x > m_pos.x && TouchPos.x < m_pos.x + kobito_M00Resize &&
           TouchPos.y > m_pos.y && TouchPos.y < m_pos.y + kobito_M00Resize){
            
            
        }
    }
    
    
}

void kobito_M00::touchesMoved(TouchEvent event){
    for(std::vector<TouchEvent::Touch>::const_iterator touchIter = event.getTouches().begin();
        touchIter != event.getTouches().end();
        touchIter++){
        //タッチの位置を取得。
        Vec2f Window   = Vec2f(getWindowWidth() * 0.5, getWindowHeight() * 0.5);
        Vec2f TouchPos = Vec2f(touchIter->getX() - Window.x,
                               touchIter->getY() - Window.y);
        
        if(TouchPos.x > m_pos.x && TouchPos.x < m_pos.x + kobito_M00Resize &&
           TouchPos.y > m_pos.y && TouchPos.y < m_pos.y + kobito_M00Resize){
            
            if(m_condition == 0){
                m_life = 0;
            }
            
            // object::remove();
        }
        
        
    }
}
