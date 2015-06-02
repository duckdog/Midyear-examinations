#include "touchPaticle.h"



touchParticle::touchParticle():
light(std::unique_ptr<gl::Light>(new gl::Light(gl::Light::DIRECTIONAL,0))){
    
    console() << "touch Particle のコンストラクタを起動" << std::endl;
   Vec3f vertices[] ={
        
     {-1,0,0},{0,1,0},{0,0,1},
     { 1,0,0},{0,1,0},{0,0,1},
     {-1,0,0},{0,-1,0},{0,0,1},
     { 1,0,0},{0,-1,0},{0,0,1},
     
     {-1,0,0},{0,1,0}, {0,0,-1},
     { 1,0,0},{0,1,0}, {0,0,-1},
     {-1,0,0},{0,-1,0},{0,0,-1},
     { 1,0,0},{0,-1,0},{0,0,-1},
     
     
     
    };
    mesh.appendVertices(&vertices[0], sizeof(vertices)/sizeof(vertices[0]));
    
    ColorA colors[] ={
      {0,1,1,0.5},{0,0.8,0.8,0.5},{0,0.7,0.7,0.5},
      {0,1,1,0.5},{0,0.8,0.8,0.5},{0,0.7,0.7,0.5},
      {0,1,1,0.5},{0,0.8,0.8,0.5},{0,0.7,0.7,0.5},
      {0,1,1,0.5},{0,0.8,0.8,0.5},{0,0.7,0.7,0.5},
      
      {1,0,1,0.5},{0.8,1,0.8,0.5},{0.7,1,0.7,0.5},
      {1,0,1,0.5},{0.8,1,0.8,0.5},{0.7,1,0.7,0.5},
      {1,0,1,0.5},{0.8,1,0.8,0.5},{0.7,1,0.7,0.5},
      {1,0,1,0.5},{0.8,1,0.8,0.5},{0.7,1,0.7,0.5},
      
     /* {1,1,0,0.5},{0.8,0.8,1,1},{0.6,0.6,1,1},
      {1,1,0,0.5},{0.8,0.8,1,1},{0.6,0.6,1,1},
      
      {1,1,1,0.5},{1,1,1,1},{1,1,1,1},
      {1,1,1,0.5},{1,1,1,1},{1,1,1,1},
      {1,1,0,0.5},{0.8,0.8,1,1},{0.6,0.6,1,1},
      {1,1,0,0.5},{0.8,0.8,1,1},{0.6,0.6,1,1},*/
      


    };
    mesh.appendColorsRgba(&colors[0],sizeof(colors)/sizeof(colors[0]));
    
    uint32_t indices[] = {
        0,1,2,
        3,4,5,
        6,7,8,
        9,10,11,
      
        12,13,14,
        15,16,17,
        18,19,20,
        21,22,23
      
    };
    mesh.appendIndices(&indices[0],sizeof(indices)/sizeof(indices[0]));
    
    mesh.recalculateNormals();//頂点のほうせんをcinderが計算.
    
    light->setAmbient(Color(.0f,.0f,.0f));
    light->setDiffuse(Color(1.0f,1.0f,1.0f));
    light->setDirection(Vec3f(.0f,.0f,100.0f));
  
  for(int i = 0; i < 4;i++){
    scales.push_back({15,15,15});
    translates.push_back({0,0,0});
  }
    is_touch = false;
    rx = ry = rz = 0;
    fade_count= 0;

}




touchParticle& getInstance(){
  static touchParticle obj;
  return obj;
}

void touchParticle::fadeout(){
  
  fade_count++;
  if(fade_count >= 30){
    is_touch = false;
    is_fadeout = false;
    fade_count = 0;
    
  }
  
}
void touchParticle::update(){
  //rz += 10;
  if(is_fadeout && !is_move)fadeout();
  ry += 5.0f;
  if(!is_move){
  rz += 10;
    translates[0].y += std::sin((ry * 0.01));
    translates[1].y -= std::sin(ry * 0.01);
    translates[2].x += std::sin(ry * 0.01);
    translates[3].x -= std::sin(ry * 0.01);
  }
}

void touchParticle::draw(){
  if(is_touch){
     gl::enableDepthRead();
     gl::enableDepthWrite();
   // gl::disable(GL_LIGHTING);

       for(int i = 0;i < 4;i++){
     
      gl::pushModelView();
      light->enable();
      gl::translate(translates[i]);
      gl::rotate(Vec3f(rx,ry,rz));
      gl::scale(scales[i]);
      gl::draw(mesh);
      light->disable();
      gl::popModelView();
      
    }
    
    gl::disableDepthRead();
    gl::disableDepthWrite();
    
   // gl::disable(GL_LIGHTING);
   
    
  }
}





void touchParticle::touchesBegan(TouchEvent event){
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
    
    
    translates[0].x = TouchPos.x;
    translates[0].y = TouchPos.y + 25;
    
    translates[1].x = TouchPos.x;
    translates[1].y = TouchPos.y - 25;
 
    translates[2].x = TouchPos.x + 25;
    translates[2].y = TouchPos.y;
 
    translates[3].x = TouchPos.x - 25;
    translates[3].y = TouchPos.y;
    
      // object::remove();
    }
}

void touchParticle::touchesMoved(TouchEvent event){
  for(std::vector<TouchEvent::Touch>::const_iterator touchIter = event.getTouches().begin();
      touchIter != event.getTouches().end();
      touchIter++){
    //タッチの位置を取得。
    Vec2f Window   = Vec2f(getWindowWidth() * 0.5, getWindowHeight() * 0.5);
    Vec2f TouchPos = Vec2f(touchIter->getX() - Window.x,
                           touchIter->getY() - Window.y);
    for(int i = 0; i < 4; i++){
    translates[i].x +=  (TouchPos.x - translates[i].x) * 0.1;
    translates[i].y +=  (TouchPos.y - translates[i].y) * 0.1;
    // object::remove();
    }
  }
  is_move = true;
}

void touchParticle::touchesEnded(TouchEvent event){
  if(is_move){
    is_touch = false;
    is_move  = false;
  }
  else{
    is_fadeout = true;
  }
}







