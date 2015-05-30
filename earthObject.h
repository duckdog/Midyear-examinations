#pragma once

#include "object.h"
#include "resources.h"

class earth;
typedef std::shared_ptr<earth> earthSP;

class earth : public object  {
    
public:
    ~earth(){}
    
    void update();
    void draw();
    static earthSP create();
    
    void touchesBegan(TouchEvent event){}
    void touchesMoved(TouchEvent event){}
    void touchesEnded(TouchEvent event){}
    void add_rotation(float);
    
    const SpriteID m_id;
    const std::string m_pass;
private:
    earth();
    float rotation;
    bool is_move;
 };