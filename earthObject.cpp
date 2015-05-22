#include "earthObject.h"



earth::earth() :
rx(20),ry(0),rz(0),
scal(50,50,50),trans(Vec3f(0,-getWindowHeight()/2+ (scal.x * 3),700)),rote(Vec3f(rx,ry,rz)){
    
    }

earthSP earth::create(){
    
    earthSP obj = earthSP(new earth());
    
    // 地球（立方体）の面情報を生成
    obj->earthobj.push_back({ { -1, -1, -1 }, {  1,  1, -1 }, {  1, -1, -1 }, { 0, 1, 1 } });
    obj->earthobj.push_back({ { -1, -1, -1 }, { -1,  1, -1 }, {  1,  1, -1 }, { 0, 1, 1 } });
    
    obj->earthobj.push_back({ { -1,  1, -1 }, { -1,  1,  1 }, {  1,  1,  1 }, { 1, 0, 0 } });
    obj->earthobj.push_back({ { -1,  1, -1 }, {  1,  1,  1 }, {  1,  1, -1 }, { 1, 0, 0 } });
    
    obj->earthobj.push_back({ {  1, -1, -1 }, {  1,  1, -1 }, {  1,  1,  1 }, { 0, 1, 0 } });
    obj->earthobj.push_back({ {  1, -1, -1 }, {  1,  1,  1 }, {  1, -1,  1 }, { 0, 1, 0 } });
    
    obj->earthobj.push_back({ { -1, -1, -1 }, { -1, -1,  1 }, { -1,  1,  1 }, { 0, 0, 1 } });
    obj->earthobj.push_back({ { -1, -1, -1 }, { -1,  1,  1 }, { -1,  1, -1 }, { 0, 0, 1 } });
    
    obj->earthobj.push_back({ { -1, -1, -1 }, {  1, -1, 1 }, { -1, -1,  1 }, { 1, 1, 0 } });
    obj->earthobj.push_back({ { -1, -1, -1 }, {  1, -1, -1 }, {  1, -1,  1 }, { 1, 1, 0 } });
    
    obj->earthobj.push_back({ {  1,  1,  1 }, { -1,  1,  1 }, { -1, -1,  1 }, { 1, 0, 1 } });
    obj->earthobj.push_back({ {  1,  1,  1 }, { -1, -1,  1 }, {  1, -1,  1 }, { 1, 0, 1 } });
    
     m_objects.push_back(obj);

    return obj;
}

void earth::update(){
    rote.y += 0.1;
    
}

void earth::draw(){
   //回転用の行列を作成.
    console() << "地球描画なう" << std::endl;
    Matrix44f translate = Matrix44f::createTranslation(trans);
    Matrix44f scale     = Matrix44f::createScale(scal);
    Matrix44f rotate    = Matrix44f::createRotation(rote);
    
    
    Matrix44f transform_matrix = translate * rotate * scale;
    
    
    for(auto& earth : earthobj){
        // 頂点の座標を行列を使って変換
        auto v1 = transform_matrix * earth.v1;
        auto v2 = transform_matrix * earth.v2;
        auto v3 = transform_matrix * earth.v3;
        
        
        //Zで割る.
        auto t1 = Vec2f(v1.x,v1.y)/(v1.z * 0.003f);
        auto t2 = Vec2f(v2.x,v2.y)/(v2.z * 0.003f);
        auto t3 = Vec2f(v3.x,v3.y)/(v3.z * 0.003f);
        
        
        //表と裏の計算、二つのべくとるをもとめる
        //TIPS: 外積を使って判定できる.
        Vec2f a = t2 -t1;
        Vec2f b = t3 -t1;
        if(b.cross(a) < 0.0f) continue;
        
        gl::color(earth.color);
        gl::drawSolidTriangle(t1, t2, t3);

        
    }

}