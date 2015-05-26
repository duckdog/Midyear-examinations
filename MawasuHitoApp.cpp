#include "common.h"
#include "sceneManage.h"
#include "titleScene.h"

class MawasuHitoApp : public AppNative {
    
public:
    void prepareSetting(Settings *settings);
    void setup();
    void mouseDown( MouseEvent event );
    void touchesBegan(TouchEvent event);
    void touchesMoved(TouchEvent event);
    void touchesEnded(TouchEvent event);

    void update();
    void draw();
 
private:
   
    std::shared_ptr<sceneManage> Frame;
 };

void MawasuHitoApp::prepareSetting(Settings *settings){
    settings->enableMultiTouch();
    settings->setResizable( false );
    settings->setWindowSize(getWindowSize());// FIXME :オブジェクトが横の伸びる危険性。後で直す
    settings->setFrameRate(20.0f);
    
}


void MawasuHitoApp::setup(){
    resourceManage::getinstace();
    gl::enableAlphaBlending();
    gl::enableDepthWrite();
        Frame = std::make_shared<sceneManage>();
    Frame->changeScene(std::make_shared<titleScene>(Frame));
    
}

void MawasuHitoApp::mouseDown( MouseEvent event){
    Frame->mouseDown(event);
}

void MawasuHitoApp::touchesBegan(TouchEvent event){
    Frame->touchesBegan(event);
}
void MawasuHitoApp::touchesMoved(TouchEvent event){
    Frame->touchesMoved(event);
}
void MawasuHitoApp::touchesEnded(TouchEvent event){
    Frame->touchesEnded(event);
}

void MawasuHitoApp::update()
{
        Frame->update();

  
}
void MawasuHitoApp::draw()
{
    
    gl::pushModelView();
    
    gl::translate(getWindowCenter());

    Frame->draw();

    gl::popModelView();
}

CINDER_APP_NATIVE( MawasuHitoApp, RendererGl )
