#pragma once
#include "common.h"
#include <list>
//#include "resources.h"


/*struct objectData{
    objectData(SpriteID,Vec2f,Vec2f);
    SpriteID m_id;
    
    Vec2f m_pos;
    Vec2f m_size;
};*/

class object {
    
public:
    object();
    ~object(){}
    virtual void update() = 0;
    virtual void draw() = 0;
    virtual void touchesBegan(TouchEvent event) = 0;
    virtual void touchesMoved(TouchEvent event) = 0;

    
    static void exUpdate();
    static void exDraw();
    static void exTouchesBegan(TouchEvent event);
    static void exToucehesMoved(TouchEvent event);

    
    static void destroy();
protected:
   
    static std::list<object*> m_objects;
};
