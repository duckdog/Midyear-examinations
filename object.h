#pragma once
#include "common.h"

class object{
    
public:
    virtual void update() = 0;
    virtual void draw() = 0;
protected:
     std::shared_ptr<object> m_obj;
    object();
};