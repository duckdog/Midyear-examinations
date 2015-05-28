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
    
    
    extern ci::fs::path getDocumentPath();
    Path = getDocumentPath();
    
    JsonTree json_writetime;
    json_writetime.write(Path / "Time.json",JsonTree::WriteOptions().createDocument(true));

    json_writetime = ci::JsonTree(loadFile(Path / "Time.json"));
    json_writetime = JsonTree::makeObject("Time");
    json_writetime.addChild(JsonTree("year",time_object->tm_year));
    json_writetime.addChild(JsonTree("month",time_object->tm_mon));
    json_writetime.addChild(JsonTree("day",time_object->tm_mday));
    json_writetime.addChild(JsonTree("minute",time_object->tm_hour));
    json_writetime.addChild(JsonTree("second",time_object->tm_sec));

    
}

void timeManage::loadtime(){
  
    
}

void timeManage::writetime(){
    
}