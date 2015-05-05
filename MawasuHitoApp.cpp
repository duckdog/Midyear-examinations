#include "common.h"

class MawasuHitoApp : public AppNative {
    
public:
    void prepareSetting(Settings *settings);
    void setup();
    void mouseDown( MouseEvent event );
    void update();
    void draw();
    
    
    std::shared_ptr<sceneBase> GameFrame;
};

void MawasuHitoApp::prepareSetting(Settings *settings)
{
    settings->setWindowSize( 1024,768);
    settings->setFrameRate(60.0f);
}


void MawasuHitoApp::setup()
{
    GameFrame = std::make_shared<titleScene>();
}

void MawasuHitoApp::mouseDown( MouseEvent event )
{
}

void MawasuHitoApp::update()
{
  
}
void MawasuHitoApp::draw()
{
    GameFrame->draw();
   
}

CINDER_APP_NATIVE( MawasuHitoApp, RendererGl )
