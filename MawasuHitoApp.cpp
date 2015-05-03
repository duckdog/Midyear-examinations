#include "common.h"
#include "sceneBase.hpp"
#include "titleScene.hpp"


class MawasuHitoApp : public AppNative {
    
public:
    void prepareSetting(Settings *settings);
    void setup();
    void mouseDown( MouseEvent event );
    void update();
    void draw();
    sceneBase* GameFrame;
};

void MawasuHitoApp::prepareSetting(Settings *settings)
{
    settings->setWindowSize( 1024,768);
    settings->setFrameRate(60.0f);
}


void MawasuHitoApp::setup()
{
    GameFrame = new titleScene();
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
