#include "common.h"
#include "sceneManage.h"
#include "titleScene.h"
#include "touchPaticle.h"
#include "object.h"
#include "timeManage.h"

class MawasuHitoApp : public AppNative {
    
public:
    void prepareSetting(Settings *settings);
    void setup();
    void mouseDown( MouseEvent event );
    void shutdown();

    void touchesBegan(TouchEvent event);
    void touchesMoved(TouchEvent event);
    void touchesEnded(TouchEvent event);

    void update();
    void draw();
 
private:
    std::shared_ptr<touchParticle> Particle;
    std::shared_ptr<sceneManage> Frame;
 };

void MawasuHitoApp::prepareSetting(Settings *settings){
    settings->enableMultiTouch();
    settings->setResizable( false );
    settings->setWindowSize(getWindowSize());// FIXME :オブジェクトが横の伸びる危険性。後で直す
    settings->setFrameRate(30.0f);
    }


void MawasuHitoApp::setup(){
        // テクスチャON
    gl::enable(GL_TEXTURE_2D);
    timeManage::getInstance().is_firstplay();
    gl::enableAlphaBlending();
    gl::enableDepthWrite();
    Frame = std::make_shared<sceneManage>();
    Particle = std::make_shared<touchParticle>();
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
void MawasuHitoApp::shutdown(){

    
}

void MawasuHitoApp::update()
{
    timeManage::getInstance().gameworld_time++;
    timeManage::getInstance().save_shutdown();
   // object::shutdown();
    Frame->update();
   
  
}
void MawasuHitoApp::draw()
{

    Particle->draw();
    gl::pushModelView();
    gl::translate(getWindowCenter());

    Frame->draw();

    gl::popModelView();
}

CINDER_APP_NATIVE( MawasuHitoApp, RendererGl )
