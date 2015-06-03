
#include "drawNumber.h"
#include "object.h"


drawNumber::drawNumber() : PREMULT(true){

    
    
for( std::vector<std::string>::const_iterator fontName = Font::getNames().begin(); fontName != Font::getNames().end(); ++fontName );

#if defined( CINDER_COCOA_TOUCH )
std::string normalFont( "Arial" );
std::string boldFont( "Arial-BoldMT" );
std::string differentFont( "AmericanTypewriter" );
#else
std::string normalFont( "Arial" );
std::string boldFont( "Arial Bold" );
std::string differentFont( "Papyrus" );
#endif

m_pos = Vec2f( 50, -getWindowHeight()/2 +  10);
layout.setColor( Color( .0f, .0f, .0f ) );
layout.setFont( Font(differentFont, 20 ) );

}


drawNumberSP drawNumber::getinstance(){
    drawNumberSP obj = drawNumberSP( new drawNumber());
    return  obj;
}


void drawNumber::draw(){
    scorecount();
    
    
}

static int resize  = 1;
static int resize2 = 1;
void drawNumber::scorecount(){
    //m_rotation360で一周.1を表示.
    layout.addLine(toString(static_cast<int>((*object::earth_date())->m_rotation) / 360 ));
    if(static_cast<int>((*object::earth_date())->m_rotation) / 360 % (10 * resize2)  == 0){
        m_pos.x = 50 + (20 * resize);
        resize++;
        resize2 *= 10;
    }
    
    Surface8u rendered = layout.render( true, PREMULT );
    mTexture = gl::Texture( rendered );
    gl::enableAlphaBlending( PREMULT );
    gl::draw( mTexture,m_pos);

    
}