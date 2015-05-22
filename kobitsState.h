#pragma once
#include "player.h"


class kobitoLife : public object {
public:
    kobitoLife(object*);
    
    void update();
    void draw(){}
    void touchesBegan(TouchEvent event){}
    void touchesMoved(TouchEvent event){}

    
};