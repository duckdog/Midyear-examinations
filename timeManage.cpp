#include <iostream>

#include "timeManage.h"
#include "common.h"

timeManage::timeManage(){
    time(&timeValue);
    time_object = localtime(&timeValue);
    
}

timeManage& timeManage::getInstance(){
    static timeManage timemgr;
    return timemgr;
}




//test
void timeManage::timeget(){
    cinder::app::console()<<
           //月は一月をゼロとするため、表示させる場合は１を加算
           //曜日は日曜日がゼロとなる。
            time_object->tm_year + 1900  <<
            time_object->tm_mon + 1 <<
            time_object->tm_mday <<
            time_object->tm_hour<<
            time_object->tm_min <<
            time_object->tm_sec << std::endl;
}

void timeManage::loadtime(){
    //読み込み
    
  /*  ci::JsonTree json = ci::JsonTree(cinder::app::loadAsset("test.json"));
    float year = json["test"]["year"].getValue<float>();
    cinder::app::console()<<"test get Value : " <<year << std::endl;
   */
    
    extern ci::fs::path getDocumentPath();
    Path = getDocumentPath();
    ci::JsonTree json_load = ci::JsonTree(loadFile(Path / "hoge.json"));
    float a = json_load["test"]["year"].getValue<float>();
    
    cinder::app::console()<<"test get Value : " << a << std::endl;
    

    
}

void timeManage::writetime(){
    //書き込み
    extern ci::fs::path getDocumentPath();
    Path = getDocumentPath();
    ci::JsonTree json_write = JsonTree::makeObject("test");
    json_write.addChild(JsonTree("year",time_object->tm_hour));
    json_write.write(Path / "hoge.json",JsonTree::WriteOptions().createDocument(true));
 
    
}