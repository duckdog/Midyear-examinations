#pragma once
#include "common.h"
#include <list>
#include <memory>

class object;
typedef std::shared_ptr<object> objectSP;
class object {
    
public:
    
    int m_life;
    
    object();
    virtual ~object(){}
    virtual void update() = 0;
    virtual void draw() = 0;
    virtual void touchesBegan(TouchEvent event) = 0;
    virtual void touchesMoved(TouchEvent event) = 0;
    virtual void touchesEnded(TouchEvent event) = 0;

    static void exUpdate();
    static void exDraw();
    static void exTouchesBegan(TouchEvent event);
    static void exTouchesMoved(TouchEvent event);
    static void exTouchesEnded(TouchEvent event);
    static void remove();
    static void destroy();
    
protected:
   
    static std::list<objectSP> m_objects;
    
};
