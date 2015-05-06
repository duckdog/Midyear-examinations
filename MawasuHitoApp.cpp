#include "common.h"
#include "titleScene.hpp"
class MawasuHitoApp : public AppNative {
    
public:
    void prepareSetting(Settings *settings);
    void setup();
    void mouseDown( MouseEvent event );
    void update();
    void draw();
    
    sceneManage Frame;
};

void MawasuHitoApp::prepareSetting(Settings *settings)
{
    settings->setWindowSize( 1024,768);
    settings->setFrameRate(60.0f);
}


void MawasuHitoApp::setup()
{
    Frame.changeScene(std::make_shared<titleScene>());

}

void MawasuHitoApp::mouseDown( MouseEvent event )
{
}

void MawasuHitoApp::update()
{
  
}
void MawasuHitoApp::draw()
{
    Frame.draw();
   
}

CINDER_APP_NATIVE( MawasuHitoApp, RendererGl )
