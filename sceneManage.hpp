//
//  sceneManage.cpp
//  MawasuHito
//
//  Created by 佐藤 匠 on 2015/05/01.
//
//


#pragma once

#include "common.h"
#include "titleScene.hpp"


class sceneManage{
public:
    virtual void update() = 0;
    virtual void draw() = 0;
    virtual void MouseDown(MouseEvent event) = 0;
    
};
