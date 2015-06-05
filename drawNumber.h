#pragma once
#include "common.h"
#include "resources.h"
#include "cinder/Font.h"
//#include "earthObject.h"

class drawNumber;
typedef std::unique_ptr<drawNumber> drawNumberSP;

class drawNumber{
public:
    drawNumber();
    void drawrotecount();
    void drawrimitcount();
    
    void drawroteupdate();
    void drawrimitupdate(int survivor_amount ,int amount_rimit);
    void fontname();
    static drawNumberSP getinstance();
    
    
    
private:
   
    std::string normalFont;
    std::string boldFont;
    std::string differentFont;
    
    std::string rote_count;
    std::string kobito_count;
    
    Vec2f m_rotepos;
    Vec2f m_rimitpos;
    Font m_font;
    int m_fontsize;
    bool is_carry;
    int ajust_pos = 0;
    int ajustment = 10;
    int leverage  = 1;
    
    bool is_rim_carry;
    int rim_ajust_pos = 0;
    int rim_ajustment = 10;
    int rim_leverage  = 1;
    
};