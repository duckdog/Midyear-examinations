#include "earthObject.h"


earth::earth():
m_id(SpriteID::tikyu),
m_pass("tikyu.png"){
}

earthSP earth::create(){

  earthSP obj = earthSP(new earth());
  obj->m_object_id = ObjectID::Earth;

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
  obj->m_rotation = 0;
  obj->is_move = false;
  resourceManage::getinstace().add(obj->m_id,obj->m_pass);
  object::m_objects.push_front(obj);//push_back(obj);

    return obj;
  
  
}

earth& earth::getInstance(){
  static earth obj;

   return obj;
}

void earth::update(){
   //オブジェクトが持つm_rote_powerの分だけ地球を回す。
  
  
}


void earth::add_rotation(float add_power){
  m_rotation += add_power;
}
void earth::draw(){
    
  
  gl::pushModelView();
  gl::enableDepthWrite();
  gl::enableDepthRead();

 
  Vec3f translate = Vec3f(0,-180,-100);
  Vec3f cube_translate = Vec3f(0.2,0.2,0.2);
 
  gl::translate(translate);
  gl::scale(Vec3f(50,50,50));
  gl::rotate(Vec3f(0,-m_rotation * 200,1));
  
  
  resourceManage::getinstace().getsprite(m_id).bind();
  
  //地球
  gl::drawSphere(Vec3f(0,0,0),1);
  resourceManage::getinstace().getsprite(m_id).unbind();

  //なんかぐるぐるまわるドーナツ。
  gl::color(Color(1,1,0));
  gl::rotate(Vec3f(100,m_rotation * 200,0));
  gl::drawTorus(1.1f,0.05f);
  
  gl::drawCube(Vec3f( 1.2, 0.0,  0.0),cube_translate);
  gl::drawCube(Vec3f(-1.2, 0.0,  0.0),cube_translate);
  gl::drawCube(Vec3f(  .0, 1.2, 0.0),cube_translate);
  gl::drawCube(Vec3f(  .0,-1.2, 0.0),cube_translate);
  
  gl::rotate(Vec3f(145,m_rotation * 200,0));
  gl::color(Color(1,1,1));
  gl::drawCube(Vec3f( 1.0, 1.0, 0.0),cube_translate * 0.5);
  gl::drawCube(Vec3f(-1.0,-1.0, 0.0),cube_translate * 0.5);
  
  //なんかぐるぐるまわるドーナツ2
  gl::color(Color(1,0,0));
  gl::rotate(Vec3f(0,m_rotation * 200,100));
  gl::drawTorus(1.2f,0.06f);
  
  gl::drawCube(Vec3f( 1.2, 0.0,  0.0),cube_translate);
  gl::drawCube(Vec3f(-1.2, 0.0,  0.0),cube_translate);
  gl::drawCube(Vec3f(  .0, 1.2, 0.0),cube_translate);
  gl::drawCube(Vec3f(  .0,-1.2, 0.0),cube_translate);
  
  gl::rotate(Vec3f(145,m_rotation * 200,100));
  gl::color(Color(1,1,0));
  gl::drawSphere(Vec3f( 1.0, 1.0, 0.0),0.1);
  gl::drawSphere(Vec3f(-1.0,-1.0, 0.0),0.1);

 
  gl::disableDepthRead();
  gl::disableDepthWrite();

  gl::popModelView();
  


}