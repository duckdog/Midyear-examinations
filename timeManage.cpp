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
    
    if(!json_load.hasChildren()){
        
      json_load.JsonTree::makeObject("isFirst");  //ci::JsonTree(loadFile(Path / "Time.json"));
      json_load.addChild(JsonTree("already_play",true));
      json_load.write(Path / "First.json",JsonTree::WriteOptions().createDocument(false));
      return true;
    }
    else{
    
       
    return false;
    }

    
}

void timeManage::writetime(){
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
}



void timeManage::check_timelag(){
  /*  extern ci::fs::path getDocumentPath();
    Path = getDocumentPath();
    
    ci::JsonTree json_load = ci::JsonTree(loadFile(Path / "Time.json"));
    
    int year,month,day,hour,minute,scond;
    year =json_load["Time"]["year"].getValue<float>();
    year =json_load["Time"]["year"].getValue<float>();
    year =json_load["Time"]["year"].getValue<float>();
    year =json_load["Time"]["year"].getValue<float>();
    year =json_load["Time"]["year"].getValue<float>();
    year =json_load["Time"]["year"].getValue<float>();
    year =json_load["Time"]["year"].getValue<float>();
    
    */
    
    
}
















