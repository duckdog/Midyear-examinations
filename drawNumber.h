
#include "common.h"
#include "resources.h"
#include "cinder/Font.h"
#include "earthObject.h"

class drawNumber;
typedef std::unique_ptr<drawNumber> drawNumberSP;

class drawNumber{
public:
    drawNumber();
    void draw();
    void scorecount();
    void fontname();
    static drawNumberSP getinstance();
    
    
    
private:
    TextLayout layout;
   

    earthSP m_eath_ref;
    const bool PREMULT;
    gl::Texture	mTexture;
    Vec2f m_pos;
};