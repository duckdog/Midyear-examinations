#include "common.h"
#include <chrono>
#include <ctime>



class timeManage {
public:
    timeManage();
    void timeget();

private:
    time_t timeValue;
    struct tm* time_object;
    
};