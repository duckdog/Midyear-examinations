
#include "drawNumber.h"
#include "object.h"



drawNumber::drawNumber(){

//#if defined( CINDER_COCOA_TOUCH )
  /*#else
std::string normalFont( "Arial" );
std::string boldFont( "Arial Bold" );
std::string differentFont( "Papyrus" );
#endif
 for( std::vector<std::string>::const_iterator fontName = Font::getNames().begin(); fontName != Font::getNames().end(); ++fontName )
 rote_layout.setFont( Font(differentFont, m_fontsize ));
 */

  normalFont     = ( "Arial" );
  boldFont       =( "Arial-BoldMT" );
  differentFont  = ( "AmericanTypewriter" );
    
  m_fontsize = 20;
  m_font = Font(boldFont, m_fontsize);
  m_pos =  Vec2f( 70 - ajust_pos, -getWindowHeight()/2 +  55);
  rote_count = ("null_string");
  is_carry = false;
}


drawNumberSP drawNumber::getinstance(){
    drawNumberSP obj = drawNumberSP( new drawNumber());
    
    return  obj;
 
}


void drawNumber::draw(){
    
    
    drawupdate(1,1);
    gl::pushModelView();
    gl::drawString(rote_count,m_pos,
                   ColorA(0,0,0,1),m_font);
//    gl::drawString(kobito_count,m_pos,
//                ColorA(0,1,1,1),m_font);
    gl::popModelView();
    /*gl::draw(rotate_count_texture ,m_pos);
    gl::draw(kobito_count_texture ,m_pos + Vec2f(0,-m_fontsize));
    
    gl::popModelView();*/
}

void drawNumber::drawupdate(int rotation,int survivor_amount){
    
    if((*object::earth_date())->m_rotation  >=  360  &&
       static_cast<int>((*object::earth_date())->m_rotation / 360) % ajustment == 0){
    
        is_carry = true;
        
    }
    //位が上がったら、左横にずらして調整.
    if(is_carry){
        m_pos.x -=  (m_fontsize/2);
        ajustment *= 10;
        leverage++;
        is_carry = false;
    }
    rote_count = toString( static_cast<int>((*object::earth_date())->m_rotation / 360));
    
    /*    //m_rotation360で一周.1を表示.
    if((*object::earth_date())->m_rotation  >=  360  &&
       static_cast<int>((*object::earth_date())->m_rotation / 360) % ajustment == 0){
        //位が上がったら、左横にずらして調整.
        ajust_pos = ((m_fontsize/2) * leverage) ;
        ajustment *= 10;
        leverage++;
    }
    
    m_pos = Vec2f( 70 - ajust_pos, -getWindowHeight()/2 +  40);
    
    rote_layout.setColor( Color( 1.0f, .0f, .0f ) );
    rote_layout.addLine(toString(static_cast<int>((*object::earth_date())->m_rotation) / 360 ));
    Surface8u rendered = rote_layout.render( true, PREMULT );
    rotate_count_texture = gl::Texture( rendered );
    
    kobito_layout.setColor( Color( 1.0f, .0f, .0f ) );
    kobito_layout.addLine(("/") + toString(rimit));
    rendered = kobito_layout.render(true,PREMULT);
    kobito_count_texture = gl::Texture( rendered );
*/

}












