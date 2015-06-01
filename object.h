#pragma once
#include "common.h"
#include "timeManage.h"
#include "cinder/Json.h"
#include <list>
#include <memory>

enum ObjectID{
    Null_object,
    Earth,
    SummonsCircle,
    Kobito_s00,
    
    ALL_Object,
};

class object;
typedef std::shared_ptr<object> objectSP;
class object {
    
public:
    int m_condition;
    int m_life;
    float m_rotation;
    double m_rote_power;
    ObjectID m_object_id;
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
    static void destroy();
    static void survivor_kobitocreate();
    static void shutdown();

    
protected:
   
    static std::list<objectSP> m_objects;
  
    
};
