
#include "object.h"

std::list<objectSP>object::m_objects;
object::object(): m_life(-1){}


void object::exUpdate(){
    std::list<objectSP>::iterator it = m_objects.begin();
    
    while(it != m_objects.end()){
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
        console() << "tochesBegan　実行" << std::endl;
        (*it)->touchesBegan(event);
        //次のオブジェクトへ.
        it++;
    }
    
}

void object::exTouchesMoved(TouchEvent event){
    
    std::list<objectSP>::iterator it = m_objects.begin();
    
    while(it != m_objects.end()){
        //touchevent実行.
        console() << *it << std::endl;
        (*it)->touchesMoved(event);
        //次のオブジェクトへ.
        it++;
    }
    
}
void object::exTouchesEnded(TouchEvent event){
    
    std::list<objectSP>::iterator it = m_objects.begin();
    
    while(it != m_objects.end()){
        //touchevent実行.
        console() << *it << std::endl;
        (*it)->touchesEnded(event);
        //次のオブジェクトへ.
        it++;
    }
    
}

void object::remove(){
    std::list<objectSP>::iterator it = m_objects.begin();
    while(it != m_objects.end()){
        
        if(0 == (*it)->m_life){
            it = m_objects.erase(it);
            continue;
        }
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



