#include "touchPaticle.h"



touchParticle::touchParticle():
light(std::unique_ptr<gl::Light>(new gl::Light(gl::Light::DIRECTIONAL,0))){
    
    console() << "touch Particle のコンストラクタを起動" << std::endl;
  /*  Vec3f vertices[] ={
        
        {-1,-1,-1},{1,1,-1},{1,-1,-1},
        
    };
    mesh.appendVertices(&vertices[0], sizeof(vertices)/sizeof(vertices[0]));
    
    Color colors[] ={
        {1,1,1},{1,1,1},{0,1,1},
    };
    mesh.appendColorsRgb(&colors[0],sizeof(colors)/sizeof(colors[0]));
    
    uint32_t indices[] = {
        0,1,2,
    };
    mesh.appendIndices(&indices[0],sizeof(indices)/sizeof(indices[0]));
    
    mesh.recalculateNormals();//頂点のほうせんをcinderが計算.
    
    light->setAmbient(Color(.0f,.0f,.0f));
    light->setDiffuse(Color(1.0f,1.0f,1.0f));
    light->setDirection(Vec3f(.0f,.0f,.0f));
   */
  
  
  
    rx = ry = rz = 0;

}

void touchParticle::update(){
    rz += 10;
   }

void touchParticle::draw(){
    gl::pushModelView();
    light->enable();
    gl::scale(Vec3f(3,3,3));
    gl::rotate(Vec3f(rx,ry,rz));
    gl::translate(Vec3f(0,0,0));
    gl::draw(mesh);
    light->disable();
    gl::popModelView();
    
    gl::disable(GL_LIGHTING);
  }





void touchParticle::touchesBegan(TouchEvent event){
    
}

void touchParticle::touchesMoved(TouchEvent event){
  
}

void touchParticle::touchesEnded(TouchEvent event){
    
}