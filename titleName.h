#pragma once

#include "object.h"
#include "resources.h"

class titleName;
typedef std::shared_ptr<titleName> titleNameSP;

class titleName : public object  {
    
public:
    ~titleName(){}
    titleName();
    
    void update();
    void draw();
    static titleNameSP create();
  
    void touchesBegan(TouchEvent event){}
    void touchesMoved(TouchEvent event){}
    void touchesEnded(TouchEvent event){}
    
    const SpriteID m_id[6];
    const std::string m_pass[6];
    
    
private:
    
    bool is_move;
    
    Vec3f m_translate;
    Vec3f m_scale;
    float rx,ry,rz;
    gl::Texture m_texture[6];
    float animation_count = 0;
};