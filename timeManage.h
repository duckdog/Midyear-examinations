#pragma once

#include <chrono>
#include <ctime>
#include "cinder/Json.h"

class timeManage {
public:
    timeManage();
    void timeget();
    void loadtime();
    void writetime();
    static timeManage& getInstance();
private:
    time_t timeValue;
    struct tm* time_object;

};