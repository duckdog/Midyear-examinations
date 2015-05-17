#include <iostream>
#include "timeManage.h"


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