
#include "shiningObj.h"




shiningObj::shiningObj(Vec2f Touchpos){
    

    is_touch = false;
    rx = ry = rz = 0;
    fade_count= 0;
    translates = Vec3f(Touchpos.x,Touchpos.y,0);
    scales = Vec3f(10,100,100);
    
}





void shiningObj::fadeout(){
    
    fade_count++;
    if(fade_count >= 30){
        is_touch = false;
        is_fadeout = false;
        fade_count = 0;
        
    }
    
}
void shiningObj::update(){
    animation += 0.1f;
    scales += std::sin(animation) * 3;
    ry++;
    rz++;
}

void shiningObj::draw(){
    
    if(is_touch){
    gl::enableDepthRead();
    gl::enableDepthWrite();
  //  gl::enable(GL_CULL_FACE);
    gl::pushModelView();
    
    
    gl::color(ColorA(1,1,1,0.5f));
    gl::translate(translates);
    gl::rotate(Vec3f(rx,ry,rz));
    gl::scale(scales);
    gl::drawSphere(Vec3f(0,0,0),1,10);
    
    gl::color(ColorA(1,0,0.8f,0.5f));
    gl::drawTorus(1.2f,0.06,10);

    gl::color(ColorA(1,1,0,0.5f));
    gl::rotate(Vec3f(rx + 100,ry * 3,rz));
    gl::drawTorus(1.2f,0.06,10);

    
    gl::color(ColorA(1,1,1,0.5f));
    gl::rotate(Vec3f(rx,ry * 2,rz + 100));
    gl::drawTorus(1.2f,0.06,10);

    gl::popModelView();
    
//    gl::disable(GL_CULL_FACE);

    gl::disableDepthRead();
    gl::disableDepthWrite();
  }
    
}





void shiningObj::touchesBegan(TouchEvent event){
    is_touch = true;
    fade_count = 0;
    is_fadeout = false;
    ry = 0;
    
    for(std::vector<TouchEvent::Touch>::const_iterator touchIter = event.getTouches().begin();
        touchIter != event.getTouches().end();
        touchIter++){
        //タッチの位置を取得。
        Vec2f Window   = Vec2f(getWindowWidth() * 0.5, getWindowHeight() * 0.5);
        Vec2f TouchPos = Vec2f(touchIter->getX() - Window.x,
                               touchIter->getY() - Window.y);
        
        translates = Vec3f(TouchPos.x,TouchPos.y,0);
        scales = Vec3f(10,10,10);

        // object::remove();
    }
}

void shiningObj::touchesMoved(TouchEvent event){
    for(std::vector<TouchEvent::Touch>::const_iterator touchIter = event.getTouches().begin();
        touchIter != event.getTouches().end();
        touchIter++){
        //タッチの位置を取得。
        Vec2f Window   = Vec2f(getWindowWidth() * 0.5, getWindowHeight() * 0.5);
        Vec2f TouchPos = Vec2f(touchIter->getX() - Window.x,
                               touchIter->getY() - Window.y);
        }
    is_move = true;
}

void shiningObj::touchesEnded(TouchEvent event){
    if(is_move){
        is_touch = false;
        is_move  = false;
    }
    else{
        is_fadeout = true;
    }
}








