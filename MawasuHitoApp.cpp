#include "common.h"
#include "sceneManage.h"
#include "titleScene.h"

class MawasuHitoApp : public AppNative {
    
public:
    void prepareSetting(Settings *settings);
    void setup();
    void mouseDown( MouseEvent event );
    void update();
    void draw();

private:
    
    std::shared_ptr<sceneManage> Frame;
};

void MawasuHitoApp::prepareSetting(Settings *settings)
{
    settings->setWindowSize( 1024,768);
    settings->setFrameRate(60.0f);
}


void MawasuHitoApp::setup()
{
    Frame = std::make_shared<sceneManage>();
    Frame->changeScene(std::make_shared<titleScene>(Frame));
}

void MawasuHitoApp::mouseDown( MouseEvent event )
{
}

void MawasuHitoApp::update()
{
    Frame->update();
  
}
void MawasuHitoApp::draw()
{
    Frame->draw();
   
}

CINDER_APP_NATIVE( MawasuHitoApp, RendererGl )
