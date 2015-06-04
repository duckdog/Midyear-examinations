
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
    void drawupdate(int rotation,int survivor_amount);
    void fontname();
    static drawNumberSP getinstance();
    
    
    
private:
   
    std::string normalFont;
    std::string boldFont;
    std::string differentFont;
    
    std::string rote_count;
    std::string kobito_count;
    
    Vec2f m_pos;
    Font m_font;
    int m_fontsize;
    bool is_carry;
    int ajust_pos = 0;
    int ajustment = 10;
    int leverage  = 1;
    
};