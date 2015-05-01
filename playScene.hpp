//
//  playScene.cpp
//  MawasuHito
//
//  Created by 佐藤 匠 on 2015/05/01.
//
//
#pragma once


#include "sceneManage.hpp"

class playScene : public sceneManage{
public:
       void draw();
private:
    playScene();
};


void playScene::draw(){
    gl::clear(Color(0,0,1));
}