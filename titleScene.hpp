//
//  Title.cpp
//  MawasuHito
//
//  Created by 佐藤 匠 on 2015/05/01.
//
//


#pragma once

#include "sceneManage.hpp"

class titleScene : public sceneManage{
    titleScene();
    
public:
    void draw();
};

titleScene::titleScene(){
    
}

void titleScene::draw(){
    gl::clear(Color(1,0,0));
}
