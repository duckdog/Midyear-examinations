#include <iostream>

#include "timeManage.h"
#include "common.h"

timeManage::timeManage() :
gameworld_time(0){
    time(&timeValue);
    time_object = localtime(&timeValue);
    console() << time_object << std::endl;
    
}

timeManage& timeManage::getInstance(){
    static timeManage timemgr;
    return timemgr;
    
}




//test
void timeManage::timeget(){
    
    m_year = time_object->tm_year;
    m_month = time_object->tm_mon;
    m_day = time_object->tm_mday;
    m_hour = time_object->tm_hour;
    m_minute = time_object->tm_min;
    m_second = time_object->tm_sec;
}




bool timeManage::is_firstplay(){
    
    extern ci::fs::path getDocumentPath();
    Path = getDocumentPath();
    if(ci::fs::is_regular_file(Path / "First.json")) {
       
        json_load = ci::JsonTree(loadFile(Path / "First.json"));
        
        return true;
    }
    else{
        json_load.write(Path / "First.json",JsonTree::WriteOptions().createDocument(true));
        
        return false;
    }
}



void timeManage::check_lag(){
 
    /*
    JsonTree json_writetime;
 
    json_writetime = JsonTree::makeObject("Time");
    json_writetime.JsonTree::makeObject("Object");
    
    json_writetime.addChild(JsonTree("year",time_object->tm_year));
    json_writetime.addChild(JsonTree("month",time_object->tm_mon));
    json_writetime.addChild(JsonTree("day",time_object->tm_mday));
    json_writetime.addChild(JsonTree("hour",time_object->tm_hour));
    json_writetime.addChild(JsonTree("minute",time_object->tm_min));
    json_writetime.addChild(JsonTree("second",time_object->tm_sec));
    
    json_writetime.write(Path / "Time.json",JsonTree::WriteOptions().createDocument(true));
*/
    
    //ゲーム内時間と、app起動時間の差を計算. 1秒以上のズレがあるかを判定.
    if(static_cast<int>(getElapsedSeconds()  - gameworld_time * 2) >= 1){
        //１秒以上のズレがある場合、ズレ秒数を取得.
        //ゲーム内時間と、起動時間のズレを修正.
        gaptime = getElapsedSeconds()  - gameworld_time * 2;
        gameworld_time = getElapsedSeconds() * 0.5;
    }
    else{
        gaptime= 0;
    }
    
}



void timeManage::check_timelag(){
    extern ci::fs::path getDocumentPath();
    Path = getDocumentPath();
    
    ci::JsonTree json_load = ci::JsonTree(loadFile(Path / "Time.json"));
    
    int year,month,day,hour,minute,sec;
    year   =json_load["Time"]["year"].getValue<float>();
    month  =json_load["Time"]["month"].getValue<float>();
    day    =json_load["Time"]["day"].getValue<float>();
    hour   =json_load["Time"]["hour"].getValue<float>();
    minute =json_load["Time"]["minute"].getValue<float>();
    sec    =json_load["Time"]["second"].getValue<float>();
    
    
    
    year   = (json_load["Time"]["year"].getValue<float>()) - year;
    
    month   = (json_load["Time"]["year"].getValue<float>()) - month;
    day    = (json_load["Time"]["year"].getValue<float>())  - day;
    hour   = (json_load["Time"]["year"].getValue<float>())  - hour;
    minute = (json_load["Time"]["year"].getValue<float>())  - minute;
    sec    = (json_load["Time"]["year"].getValue<float>())  - sec;
    
    
   
}
















