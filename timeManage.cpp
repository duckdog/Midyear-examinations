#include <iostream>

#include "timeManage.h"
#include "object.h"
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
    
    //セーブデータがあるかを判定.
    //続きからならロード、はじめからならセーブデータを書き込み.
    if(ci::fs::is_regular_file(Path / "First.json")) {
       
        check_timelag();
        return true;
    }
    else{
        json_load.write(Path / "First.json",JsonTree::WriteOptions().createDocument(true));
        return false;
    }
}
void timeManage::save_shutdown(){
    extern ci::fs::path getDocumentPath();
    Path = getDocumentPath();
    JsonTree ex_json;
    
    if(ci::fs::is_regular_file(Path / "Save.json")){
      
      JsonTree ex_json = JsonTree(loadFile(Path / "Save.json"));
      
      ex_json = ci::JsonTree::makeObject(("Time"));
      ex_json.addChild(JsonTree("year",time_object->tm_year));
      ex_json.addChild(JsonTree("month",time_object->tm_mon));
      ex_json.addChild(JsonTree("day",time_object->tm_mday));
      ex_json.addChild(JsonTree("hour",time_object->tm_hour));
      ex_json.addChild(JsonTree("minute",time_object->tm_min));
      ex_json.addChild(JsonTree("second",time_object->tm_sec));
    
      ex_json.write(Path / "Save.json",JsonTree::WriteOptions().createDocument(true));
        
    }
    else{
      ex_json = ci::JsonTree::makeObject(("Time"));
      ex_json.addChild(JsonTree("year",1));
      ex_json.addChild(JsonTree("month",time_object->tm_mon));
      ex_json.addChild(JsonTree("day",time_object->tm_mday));
      ex_json.addChild(JsonTree("hour",time_object->tm_hour));
      ex_json.addChild(JsonTree("minute",time_object->tm_min));
      ex_json.addChild(JsonTree("second",time_object->tm_sec));

      ex_json.write(Path / "Save.json",JsonTree::WriteOptions().createDocument(true));
    }
}

void timeManage::checking_lag(){
    //ゲーム内時間と、app起動時間の差を計算. 1秒以上のズレがあるかを判定.
    if(static_cast<int>(getElapsedSeconds()   - gameworld_time/ 60) > 1){
        //１秒以上のズレがある場合、ズレ秒数を取得.
        //ゲーム内時間と、起動時間のズレを修正.
        
        gaptime = (getElapsedSeconds()  - gameworld_time / 60);
        console() << "gap_time" << gaptime <<std::endl;
        gameworld_time = getElapsedSeconds() * 60;
    }
    else{
        gaptime= 0;
    }
    
}





void timeManage::check_timelag(){
    extern ci::fs::path getDocumentPath();
    Path = getDocumentPath();
    
 
    if(ci::fs::is_regular_file(Path / "Save.json")) {
    
    JsonTree ex_json(loadFile(Path / "Save.json"));
        
      int year,month,day,hour,minute,sec;
      year   = ex_json["Time"]["year"].getValue<float>();
      month  = ex_json["Time"]["month"].getValue<float>();
      day    = ex_json["Time"]["day"].getValue<int>();
      hour   = ex_json["Time"]["hour"].getValue<int>();
      minute = ex_json["Time"]["minute"].getValue<int>();
      sec    = ex_json["Time"]["second"].getValue<int>();
    
    
      long past_time =
      (year * 315360000) +
      (month  * 2592000) +
      (day * 86400) +
      (hour * 3600) +
      (minute * 60) +
      (sec);
   
      long current_time =
      (time_object->tm_year * 315360000) +
      (time_object->tm_mon  * 2592000) +
      (time_object->tm_mday * 86400) +
      (time_object->tm_hour * 3600) +
      (time_object->tm_min * 60)  +
      (time_object->tm_sec)* 60;
    
      long time_lag = current_time - past_time;
    
      if(time_lag >= 60 * 60 * 60 * 3){
          gaptime = 60*(60 * 60 * 60 * 3);
      }
      else{
          gaptime = static_cast<int>(time_lag) * 60;
      }
    }
    
    
   
}
















