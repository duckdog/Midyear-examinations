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
    
    static void exUpdate();
    static void exDraw();
    
    static void destroy();
protected:
   
    static std::list<object*> m_objects;
};
