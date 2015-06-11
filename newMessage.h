#pragma once
#include "common.h"
#include "object.h"
#include "resources.h"

enum newMessageSpriteSize{
    newMessageW = 256,
    newMessageH = 128,
    newMessageResizeW = 120,
    newMessageResizeH = 60,
};
typedef std::shared_ptr<class newMessage> newMessageSP;
class newMessage : public object {
    
public:
    ~newMessage(){}
    newMessage();
    
    void update();
    void draw();
    void checkCreateMessage();
    void saveUnreadMessage();
    static newMessageSP create();
    
    void touchesBegan(TouchEvent event){}
    void touchesMoved(TouchEvent event){}
    void touchesEnded(TouchEvent event){}
    
    
    
private:
    const SpriteID m_id;
    const std::string m_pass;
    Area defalt_size;
    Area re_size;
    bool is_move;
    bool is_create_newmessage;
    
    Vec3f m_translate;
    Vec3f m_scale;
    float rx,ry,rz;
    float alpfa;
    gl::Texture m_texture;
    float animation_count = 0;
    
};