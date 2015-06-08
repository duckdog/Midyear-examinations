#pragma once

#include "common.h"
#include "resources.h"

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
    const SpriteID m_id;
    const std::vector<SpriteID> m_message_id;
    
    const std::string m_pass;
    const std::vector<std::string> m_message_pass;
    
    gl::Texture m_Texture;
    
    Vec3f translate;
    Vec3f scale;
    Area  defalt_size;
    Area  resize;
    
    float rx,ry,rz;
    Vec3f m_pos;
    float effect_count;
    
    bool is_touch_message;
    bool is_touchmove;
    bool is_openmessage;
    Vec3f tgt_pos;
    Vec3f def_pos;
    
    Vec2f m_starting_touch_pos;
};
