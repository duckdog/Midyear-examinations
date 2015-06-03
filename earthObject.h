#pragma once

#include "object.h"
#include "resources.h"

class earth;
typedef std::shared_ptr<earth> earthSP;

class earth : public object  {
    
public:
    ~earth(){}
    earth();

    void update();
    void draw();
    static earthSP create();
    static earth& getInstance();
    
    const inline float& getrotation() const {return m_rotation;}//＆（アドレス）をつけて返すときは、値を書き換えてしまうので、constをつける.
    void touchesBegan(TouchEvent event){}
    void touchesMoved(TouchEvent event){}
    void touchesEnded(TouchEvent event){}
    void add_rotation(float);
    
    const SpriteID m_id;
    const std::string m_pass;
    

private:
    bool is_move;
 };