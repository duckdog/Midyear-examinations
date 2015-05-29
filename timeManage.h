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
    void writetime();
    static timeManage& getInstance();
private:
    
    ci::fs::path Path;
    cinder::JsonTree json_load;
    time_t timeValue;
    struct tm* time_object;

    int m_year;
    int m_month;
    int m_day;
    int m_hour;
    int m_minute;
    int m_second;
    
};