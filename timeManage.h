#pragma once

#include <chrono>
#include <ctime>
#include "cinder/Json.h"


class timeManage {
public:
    timeManage();
    
    bool is_firstplay();
    void checking_lag();
    void check_timelag();
    void save_shutdown();
    
    
    
    void timeget();
    static timeManage& getInstance();
    int gameworld_time;
    int gaptime;

private:
    
    ci::fs::path Path;
    cinder::JsonTree json_load;
    cinder::JsonTree json_time;
    cinder::JsonTree json_object;
    time_t timeValue;
    struct tm* time_object;
    
    int m_year;
    int m_month;
    int m_day;
    int m_hour;
    int m_minute;
    int m_second;
    
    
};