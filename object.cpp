
#include "object.h"

std::list<objectSP>object::m_objects;
object::object(): m_life(-1),m_rote_power(.0f),m_rotation(0){}


void object::exUpdate(){
    std::list<objectSP>::iterator it = m_objects.begin();
    
    
    while(it != m_objects.end()){
        //lifeが0のオブジェクトを消去。
        if(0 == (*it)->m_life){
            it = m_objects.erase(it);
            continue;
        }
        
        //update 実行.
        (*it)->update();
                it++;
    }
}

void object::exDraw(){
    
    std::list<objectSP>::iterator it = m_objects.begin();
    
    while(it != m_objects.end()){
        //draw実行.
        (*it)->draw();
        //次のオブジェクトへ.
        it++;
    }
    
}

void object::exTouchesBegan(TouchEvent event){
    
    std::list<objectSP>::iterator it = m_objects.begin();
    
    while(it != m_objects.end()){
        //touchesBegan実行.
        (*it)->touchesBegan(event);
        //次のオブジェクトへ.
        it++;
    }
    
}

void object::exTouchesMoved(TouchEvent event){
    
    std::list<objectSP>::iterator it = m_objects.begin();
    
    while(it != m_objects.end()){
        //touchevent実行.
        (*it)->touchesMoved(event);
        
        
        //次のオブジェクトへ.
        it++;
    }
    
}
void object::exTouchesEnded(TouchEvent event){
    
    std::list<objectSP>::iterator it = m_objects.begin();
    
    while(it != m_objects.end()){
        //touchevent実行.
        (*it)->touchesEnded(event);
        //次のオブジェクトへ.
        it++;
    }
    
}

//一応用意。つかわないかも？
void object::destroy(){
    std::list<objectSP>::iterator it = m_objects.begin();
    while(it != m_objects.end()){
                it++;
    }
    m_objects.clear();
}



