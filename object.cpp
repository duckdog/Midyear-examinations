
#include "object.h"

std::list<object*>object::m_objects;
object::object(){}


void object::exUpdate(){
    std::list<object*>::iterator it = m_objects.begin();
    
    while(it != m_objects.end()){
        //update 実行.
        (*it)->update();
        //次のオブジェクト.
        it++;
    }
}

void object::exDraw(){
    
    std::list<object*>::iterator it = m_objects.begin();
    
    while(it != m_objects.end()){
        //draw実行.
        (*it)->draw();
        //次のオブジェクトへ.
        it++;
    }
    
}

void object::exTouchesBegan(TouchEvent event){
    
    std::list<object*>::iterator it = m_objects.end();
    
    while(it != m_objects.end()){
        //draw実行.
        (*it)->touchesBegan(event);
        //次のオブジェクトへ.
        it++;
    }
    
}

void object::exToucehesMoved(TouchEvent event){
    
    std::list<object*>::iterator it = m_objects.end();
    
    while(it != m_objects.end()){
        //touchevent実行.
        (*it)->touchesBegan(event);
        //次のオブジェクトへ.
        it++;
    }
    
}


//一応用意。つかわないかも？
void object::destroy(){
    std::list<object*>::iterator it = m_objects.begin();
    while(it != m_objects.end()){
        delete(*it);
        it++;
    }
    m_objects.clear();
}



