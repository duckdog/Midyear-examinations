#include "chooceKobitoIcon.h"


chooseKobitoIcon::chooseKobitoIcon():
m_id(SpriteID::kobito_s00),
m_pass("null"){
    

    console() << "コンストラクタを起動" << std::endl;
    Vec3f vertices[] ={
        
        //矢印
        {-5,0,0},{-3,1,0},{-4,0,2},
        {-5,0,0},{-3,-1,0},{-4,0,2},
        {-3,1,0},{-3,-1,0},{-4,0,2},
        
        
    //右向き
        {5,0,0},{3, 1,0},{4,0,2},
        {5,0,0},{3,-1,0},{4,0,2},
        {3,1,0},{3,-1,0},{4,0,2},
        
        
    
        
    };
    mesh.appendVertices(&vertices[0], sizeof(vertices)/sizeof(vertices[0]));
    
    ColorA colors[] ={
        
        {0,0,1,0.5},{1,1,1,0.5},{1,1,1,0.5},
        {0,0,1,0.8},{0.4,0.4,1,0.95},{0.6,0.6,1,1},
        {0,0,0,1},{0,0,0,1},{0,0,0,1},
        
        {0,0,1,0.5},{1,1,1,0.5},{1,1,1,0.5},
        {0,0,1,0.8},{0.4,0.4,1,0.95},{0.6,0.6,1,1},
        {0,0,0,1},{0,0,0,1},{0,0,0,1},
        
        
       /* {1,1,1,1},{1,1,0,1},{1,1,0,1},
        {1,1,1,0.8},{1,1,0,0.95},{1,1,0.7,1},
        {1,1,1,0.8},{1,1,1,0.95},{1,1,0,1},
      */
        
        
    };
    mesh.appendColorsRgba(&colors[0],sizeof(colors)/sizeof(colors[0]));
    
    uint32_t indices[] = {
        0,1,2,
        3,4,5,
        6,7,8,
        
        9,10,11,
        12,13,14,
        15,16,17,
        
    };
    mesh.appendIndices(&indices[0],sizeof(indices)/sizeof(indices[0]));
    
    mesh.recalculateNormals();//頂点のほうせんをcinderが計算.
    

    for(int i = 0; i < 2; i++){
     scales[i]     = Vec3f({15,15,15});
     translates[i] = Vec3f(0,getWindowHeight()/2 - scales[i].y,0);
    }
    is_touch = false;
    rx = ry = rz = 0;
    fade_count = 0;
    move_count = 0;
    move_range = 6;
}





void chooseKobitoIcon::update(){
    move_count += 0.05f;
   // double radian = move_count * PI /180.0;
    translates[0] = Vec3f(std::abs(sin(move_count)) * move_range,
                          getWindowHeight()/2 - (scales[0].y * 2),
                          0);
    translates[1] = Vec3f(-std::abs(sin(move_count)) * move_range,
                          getWindowHeight()/2 - (scales[0].y * 2),
                          0);
  
    
}

void chooseKobitoIcon::draw(){
  
        gl::enableDepthRead();
        gl::enableDepthWrite();
        // gl::disable(GL_LIGHTING);
    for(int i = 0; i < 2; i++){
        gl::pushModelView();
        gl::translate(translates[i]);
        gl::rotate(Vec3f(rx,ry,rz));
        gl::scale(scales[i]);
        gl::draw(mesh);
        gl::popModelView();
    }
    
        gl::disableDepthRead();
        gl::disableDepthWrite();
        
        // gl::disable(GL_LIGHTING);
 
    

}





void chooseKobitoIcon::touchesBegan(TouchEvent event){
    
    for(std::vector<TouchEvent::Touch>::const_iterator touchIter = event.getTouches().begin();
        touchIter != event.getTouches().end();
        touchIter++){
        //タッチの位置を取得。
        Vec2f Window   = Vec2f(getWindowWidth() * 0.5, getWindowHeight() * 0.5);
        Vec2f TouchPos = Vec2f(touchIter->getX() - Window.x,
                               touchIter->getY() - Window.y);
      }
}

void chooseKobitoIcon::touchesMoved(TouchEvent event){
    for(std::vector<TouchEvent::Touch>::const_iterator touchIter = event.getTouches().begin();
        touchIter != event.getTouches().end();
        touchIter++){
        //タッチの位置を取得。
        Vec2f Window   = Vec2f(getWindowWidth() * 0.5, getWindowHeight() * 0.5);
        Vec2f TouchPos = Vec2f(touchIter->getX() - Window.x,
                               touchIter->getY() - Window.y);
         }
    
}

void chooseKobitoIcon::touchesEnded(TouchEvent event){
   }
