#include "kobito_00.h"
#include "cinder/Rand.h"
#include <vector>
kobito_00::kobito_00() :
m_id(SpriteID::kobito_s00),m_pass(("kobito_s00.png")){
  
}

kobito_00SP kobito_00::create(){
    
    kobito_00SP obj = kobito_00SP(new kobito_00());
    obj->m_animationframe = 0;
    obj->m_pos = Vec2f(.0f,getWindowHeight()/2 - (kobito_sResize * 3));
    resourceManage::getinstace().add(obj->m_id,obj->m_pass);
    obj->m_resize = Area(obj->m_pos.x,obj->m_pos.y,
                         kobito_sResize + obj->m_pos.x,kobito_sResize + obj->m_pos.y);
    
    
    object::m_objects.push_back(obj);
    return obj;

}


void kobito_00::update(){
    
    //小人画像のアニメーション
    m_animationframe++;
    if((m_animationframe / 30) % 2 == 0){
        m_default_size = Area(0 + kobito_sW,0,kobito_sW * 2,kobito_sH);
    }
    else{
        m_default_size = Area(0,0,kobito_sW,kobito_sH);
       
    }
    //アニメーションようなので、増えすぎるを防止。（気づかない程度に.）
    if(m_animationframe > 60){ m_animationframe = 0;}
    //
    console() << m_animationframe << std::endl;
    
    if(  m_pos.y > 0){
        m_pos.y--;
    }
    
    
}

void kobito_00::draw(){
    m_resize = Area(m_pos.x,m_pos.y,kobito_sResize + m_pos.x,kobito_sResize + m_pos.y);
    gl::color(Color(1,1,1));
    gl::draw(resourceManage::getinstace().getsprite(m_id),
            m_default_size,m_resize);

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
        
        
        console() << "mouse_PosX :" << TouchPos.x << std::endl;
        console() << "mouse_PosY :" << TouchPos.y << std::endl;

        //取得したタッチ位置とオブジェクトの位置の当たり判定,
        //オブジェクトの領域にはいっていればremove.
        if(TouchPos.x > m_pos.x && TouchPos.x < m_pos.x + kobito_sResize &&
               TouchPos.y > m_pos.y && TouchPos.y < m_pos.y + kobito_sResize){
            
              //エラーでう
              //  m_objects.erase(( kobito_00SP (kobito_00SP(this));
            
            }
         }

    
}

void kobito_00::touchesMoved(TouchEvent event){
    for(std::vector<TouchEvent::Touch>::const_iterator touchIter = event.getTouches().begin();
        touchIter != event.getTouches().end();
        touchIter++){
        
    }
}
