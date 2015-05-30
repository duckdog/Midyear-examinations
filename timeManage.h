#pragma once

#include <chrono>
#include <ctime>
#include "cinder/Json.h"


class timeManage {
public:
    timeManage();
    
    bool is_firstplay();
    
    void check_timelag();
    void timeget();
    void check_lag();
    static timeManage& getInstance();
    int gameworld_time;
    
private:
    
    ci::fs::path Path;
    cinder::JsonTree json_load;
    cinder::JsonTree json_time;
    cinder::JsonTree json_object;
    time_t timeValue;
    struct tm* time_object;
    
    int gaptime;
    
    int m_year;
    int m_month;
    int m_day;
    int m_hour;
    int m_minute;
    int m_second;
    
    
};