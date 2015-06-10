#pragma once
#include "object.h"
#include "resources.h"
#include "chooceKobitoIcon.h"
enum summonsSpriteInfo{
    summons_W = 416,
    summons_H = 68,
    
    
};

class summonsCircle;
typedef std::shared_ptr<summonsCircle> summonsCircleSP;

class summonsCircle : public object{
public:
    
   static summonsCircleSP create();
   void createinterval();
   void update();
   void draw();
   void touchesBegan(TouchEvent event);
   void touchesMoved(TouchEvent event);
   void touchesEnded(TouchEvent event);
 
private:
    const SpriteID m_id;
    const std::string m_pass;
    Vec2f m_pos;
    Area m_default_size; //使用する画像の切り取り
    Area m_resize;       //画像の位置、サイズ.
    summonsCircle();
    bool is_create;
    int  interval_count;
    float alpfa;
    KobitoIconSP m_kobito_icon_ref;
};