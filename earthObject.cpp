#include "earthObject.h"


earth::earth():
m_id(SpriteID::tikyu),
m_pass("tikyu.png"){
}

earthSP earth::create(){

  earthSP obj = earthSP(new earth());
  /*obj->rx = 20;
  obj->ry = 0;
  obj->rz = 0;
  obj->scal  = Vec3f(50,50,50);
  obj->trans = Vec3f(0,-getWindowHeight() * 0.5,700);
  obj->rote  = Vec3f(obj->rx,obj->ry,obj->rz);
  
    obj->earthobj.push_back({ { -1, -1, -1 }, {  1,  1, -1 }, {  1, -1, -1 }, { 0, 1, 0.2 } });
    obj->earthobj.push_back({ { -1, -1, -1 }, { -1,  1, -1 }, {  1,  1, -1 }, { 0, 1, 0.2 } });

    obj->earthobj.push_back({ { -1,  1, -1 }, { -1,  1,  1 }, {  1,  1,  1 }, { 0, 1, 0.2 } });
    obj->earthobj.push_back({ { -1,  1, -1 }, {  1,  1,  1 }, {  1,  1, -1 }, { 0, 0, 1 } });
    
    obj->earthobj.push_back({ {  1, -1, -1 }, {  1,  1, -1 }, {  1,  1,  1 }, { 0, 0, 1 } });
    obj->earthobj.push_back({ {  1, -1, -1 }, {  1,  1,  1 }, {  1, -1,  1 }, { 0, 0.2, 1 } });
    
    obj->earthobj.push_back({ { -1, -1, -1 }, { -1, -1,  1 }, { -1,  1,  1 }, { 0, 0.2, 1 } });
    obj->earthobj.push_back({ { -1, -1, -1 }, { -1,  1,  1 }, { -1,  1, -1 }, { 0, 0, 1 } });
    
    obj->earthobj.push_back({ { -1, -1, -1 }, {  1, -1, 1 }, { -1, -1,  1 }, { 0, 1, 0.2 } });
    obj->earthobj.push_back({ { -1, -1, -1 }, {  1, -1, -1 }, {  1, -1,  1 }, { 0, 1, 0.2 } });
    
    obj->earthobj.push_back({ {  1,  1,  1 }, { -1,  1,  1 }, { -1, -1,  1 }, { 0, 1, 0.2 } });
    obj->earthobj.push_back({ {  1,  1,  1 }, { -1, -1,  1 }, {  1, -1,  1 }, { 0, 0.1, 1 } });
    */
  obj->rotation = 0;
  obj->is_move = false;
  resourceManage::getinstace().add(obj->m_id,obj->m_pass);
  object::m_objects.push_back(obj);//push_back(obj);

    return obj;
}

void earth::update(){
    //オブジェクトが持つm_rote_powerの分だけ地球を回す。
    std::list<objectSP>::iterator it = m_objects.begin();
    while(it != m_objects.end()){
      rotation += (*it)->m_rote_power;
      console()  << "m_rote_power :"<< rotation << std::endl;
        it++;
    }
  

}



void earth::draw(){
    
  
  gl::pushModelView();
  gl::enableDepthWrite();
  gl::enableDepthRead();

 
  Vec3f translate = Vec3f(0,-3.3,0);
  Vec3f cube_translate = Vec3f(0.2,0.2,0.2);
  
  gl::scale(Vec3f(40,40,40));
  gl::rotate(Vec3f(0,-rotation * 200,1));
  gl::translate(translate);
  
  
  resourceManage::getinstace().getsprite(m_id).bind();
  
  //地球
  gl::drawSphere(Vec3f(0,0,0),1);
  resourceManage::getinstace().getsprite(m_id).unbind();

  //なんかぐるぐるまわるドーナツ。
  gl::color(Color(1,1,0));
  gl::rotate(Vec3f(100,rotation * 200,0));
  gl::drawTorus(1.1f,0.05f);
  
  gl::drawCube(Vec3f( 1.2, 0.0,  0.0),cube_translate);
  gl::drawCube(Vec3f(-1.2, 0.0,  0.0),cube_translate);
  gl::drawCube(Vec3f(  .0, 1.2, 0.0),cube_translate);
  gl::drawCube(Vec3f(  .0,-1.2, 0.0),cube_translate);
  
  gl::rotate(Vec3f(145,rotation * 200,0));
  gl::color(Color(1,1,1));
  gl::drawCube(Vec3f( 1.0, 1.0, 0.0),cube_translate * 0.5);
  gl::drawCube(Vec3f(-1.0,-1.0, 0.0),cube_translate * 0.5);
  
  //なんかぐるぐるまわるドーナツ2
  gl::color(Color(1,0,0));
  gl::rotate(Vec3f(0,rotation * 200,100));
  gl::drawTorus(1.2f,0.06f);
  
  gl::drawCube(Vec3f( 1.2, 0.0,  0.0),cube_translate);
  gl::drawCube(Vec3f(-1.2, 0.0,  0.0),cube_translate);
  gl::drawCube(Vec3f(  .0, 1.2, 0.0),cube_translate);
  gl::drawCube(Vec3f(  .0,-1.2, 0.0),cube_translate);
  
  gl::rotate(Vec3f(145,rotation * 200,100));
  gl::color(Color(1,1,0));
  gl::drawSphere(Vec3f( 1.0, 1.0, 0.0),0.1);
  gl::drawSphere(Vec3f(-1.0,-1.0, 0.0),0.1);

 
  gl::disableDepthRead();
  gl::disableDepthWrite();

  gl::popModelView();
  


}