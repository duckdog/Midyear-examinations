#pragma once

#include "common.h"
#include "resources.h"
#include "swipArrow.h"

enum menuiconSpriteInfo{
    menu_WH = 512,
    menu_risize = 300,
    
    
};


class messageIcon;
typedef  std::unique_ptr<messageIcon> messageIconSP;

class messageIcon{
public:
    messageIcon();
  

    ~messageIcon(){}
    
    void update();
    void draw();
    void touchesBegan(TouchEvent event);
    void touchesMoved(TouchEvent event);
    void touchesEnded(TouchEvent event);

private:
    
    swipArrowSP m_swiparrow;
    const SpriteID m_id;
    const std::vector<SpriteID> m_message_id;
    const std::string m_pass;
    const std::vector<std::string> m_message_pass;
    Area  defalt_size;
    Area  resize;
    gl::Texture m_Texture;
    float message_alpfa;
    Vec3f translate;
    Vec3f scale;
    float rx,ry,rz;
    Vec3f m_pos;
    Vec3f m_message_pos;
    float effect_count;
    bool is_touch_message;
    bool is_touchmove;
    bool is_openmessage;
    Vec3f tgt_pos;
    Vec3f def_pos;
    
    Vec2f m_starting_touch_pos;
    int current_message_number;
    int max_message;
    int earth_rotate_ref;
};
