//
//  MawasuhitoApp.hpp
//  MawasuHito
//
//  Created by 佐藤 匠 on 2015/05/01.
//
//

#pragma once

#include "common.h"
#include "sceneManage.hpp"



class MawasuHitoApp : public AppNative {
    
  
public:
    void prepareSetting(Settings *settings);
    void setup();
    void mouseDown( MouseEvent event );
    void update();
    void draw();
};
