#pragma once
#include "object.h"
#include "resources.h"

enum summonsSpriteInfo{
    summons_W = 416,
    summons_H = 68,
    
    
};

class summonsCircle;
typedef std::shared_ptr<summonsCircle> summonsCircleSP;

class summonsCircle : public object{
public:
   void update();
   void draw();
   static summonsCircleSP create();
   void touchesBegan(TouchEvent event);
   void touchesMoved(TouchEvent event);
    void touchesEnded(TouchEvent event){}
  //  void getPos(){}
private:
    const SpriteID m_id;
    const std::string m_pass;
    Vec2f m_pos;
    Area m_default_size; //使用する画像の切り取り
    Area m_resize;       //画像の位置、サイズ.
    summonsCircle();
    
};