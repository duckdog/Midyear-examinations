#include "common.h"
#include "sceneManage.hpp"
#include "sceneBase.hpp"


class MawasuHitoApp : public AppNative {
    
public:
    void prepareSetting(Settings *settings);
    void setup();
    void mouseDown( MouseEvent event );
    void update();
    void draw();

private:
    
    sceneManage Frame;
};

void MawasuHitoApp::prepareSetting(Settings *settings)
{
    settings->setWindowSize( 1024,768);
    settings->setFrameRate(60.0f);
}


void MawasuHitoApp::setup()
{
    
}

void MawasuHitoApp::mouseDown( MouseEvent event )
{
}

void MawasuHitoApp::update()
{
    Frame.update();
  
}
void MawasuHitoApp::draw()
{
    Frame.draw();
   
}

CINDER_APP_NATIVE( MawasuHitoApp, RendererGl )
