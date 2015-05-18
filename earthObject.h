#include "object.h"
#include "common.h"


class earth : public object  {
    
public:
    earth();
    void update();
    void draw();
    
private:
    // 面情報を定義
    // 三角形の頂点と色
    struct earthObj{
        Vec3f v1,v2,v3;
        Color color;
    };
     std::vector<earthObj> earthobj;
    
    float rx;
    float ry;
    float rz;
    
    
    Vec3f trans;
    Vec3f rote;
    Vec3f scal;
};