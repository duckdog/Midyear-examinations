#include "common.h"
#include "player.h"


class objectManage{
  
public:
    objectManage();
    
    void update();
    void draw();
   
private:
    std::shared_ptr<object> objects;
};