//
//  Title.cpp
//  MawasuHito
//
//  Created by 佐藤 匠 on 2015/05/01.
//
//


#pragma once


#include "common.h"
#include "sceneBase.hpp"

class sceneBase;

class titleScene : public sceneBase{
       
public:
    void draw(){}
    void update(){
    gl::clear(Color(1,0,1));
    }
};

