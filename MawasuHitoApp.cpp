#include "common.h"
#include "sceneManage.h"
#include "titleScene.h"
#include "touchPaticle.h"
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
    timeManage::getInstance();
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
    console()<< "check time :" << getElapsedSeconds() << std::endl;

}

void MawasuHitoApp::update()
{
    console() << "起動時間"<< static_cast<int>(getElapsedSeconds()) << std::endl;
    console() << "ゲーム内時間"<<timeManage::getInstance().gameworld_time / 60 << std::endl;
    timeManage::getInstance().gameworld_time++;
    timeManage::getInstance().check_lag();
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
