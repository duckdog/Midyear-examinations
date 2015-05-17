
#include <chrono>
#include <ctime>


class timeManage {
public:
    timeManage();
    void timeget();
    static timeManage& getInstance();
private:
    time_t timeValue;
    struct tm* time_object;
    
};