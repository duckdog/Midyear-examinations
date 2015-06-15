#include "common.h"
#include "sceneManage.h"
#include "titleScene.h"
#include "touchPaticle.h"
#include "menuScene.h"
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
    audio::BufferPlayerNodeRef mBufferPlayerNode[3];
    audio::GainNodeRef gain[3];
    bool is_play[2];
 };

void MawasuHitoApp::prepareSetting(Settings *settings){
    settings->enableMultiTouch();
    settings->setResizable( false );
    settings->setWindowSize(getWindowSize());// FIXME :オブジェクトが横の伸びる危険性。後で直す
    settings->setFrameRate(60.0f);
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
    
    
    // 出力デバイスをゲット
    auto ctx = audio::Context::master();
    
    // オーディオデータを読み込んで初期化
    audio::SourceFileRef sourceFile[3] =
    {audio::load(loadAsset("choin.wav")),audio::load(loadAsset("main.wav")),audio::load(loadAsset("clock.wav"))};
    audio::BufferRef buffer[3] =
    {sourceFile[0]->loadBuffer(),sourceFile[1]->loadBuffer(),sourceFile[2]->loadBuffer()};
    mBufferPlayerNode[0] = ctx->makeNode(new audio::BufferPlayerNode(buffer[0]));
    mBufferPlayerNode[1] = ctx->makeNode(new audio::BufferPlayerNode(buffer[1]));
    mBufferPlayerNode[2] = ctx->makeNode(new audio::BufferPlayerNode(buffer[2]));
    gain[0] = ctx->makeNode(new audio::GainNode(0.3f));
    gain[1] = ctx->makeNode(new audio::GainNode(0.4f));
    gain[2] = ctx->makeNode(new audio::GainNode(0.3f));
    // 読み込んだオーディオを出力デバイスに関連付けておく
    mBufferPlayerNode[0] >> gain[0] >> ctx->getOutput();
    mBufferPlayerNode[1] >> gain[1] >> ctx->getOutput();
    mBufferPlayerNode[2] >> gain[2] >> ctx->getOutput();
    //gain >> ctx->getOutput();
    //gain >> ctx->getOutput();
    
    is_play[0] = false;
    is_play[1] = false;
    // 出力デバイスを有効にする
    ctx->enable();
}

void MawasuHitoApp::mouseDown( MouseEvent event){
    Frame->mouseDown(event);
}

void MawasuHitoApp::touchesBegan(TouchEvent event){
    mBufferPlayerNode[0]->start();
    Particle->touchesBegan(event);
    Frame->touchesBegan(event);
  }
void MawasuHitoApp::touchesMoved(TouchEvent event){
    
  /*  if (!is_play[1]){
        mBufferPlayerNode[2]->start();
        is_play[1] = true;
    }
    if (mBufferPlayerNode[2]->isEof())
        is_play[1] = false;*/
    
    Particle->touchesMoved(event);
    Frame->touchesMoved(event);
}
void MawasuHitoApp::touchesEnded(TouchEvent event){
  /*  mBufferPlayerNode[2]->stop();
    is_play[1] = false;*/
    Particle->touchesEnded(event);
    Frame->touchesEnded(event);
}
void MawasuHitoApp::shutdown(){

    //  timeManage::getInstance().save_shutdown();
    // object::shutdown();
    object::shutdown();
    timeManage::getInstance().save_shutdown();
}

void MawasuHitoApp::update()
{
    
    if (!is_play[0]){
        mBufferPlayerNode[1]->start();
        is_play[0] = true;
    }
    if (mBufferPlayerNode[1]->isEof())
        is_play[0] = false;
   
    Particle->update();
    Frame->update();
    
}
void MawasuHitoApp::draw()
{

    
    gl::pushModelView();
    gl::translate(getWindowCenter());
    Frame->draw();
    Particle->draw();
    
    gl::popModelView();
}

CINDER_APP_NATIVE( MawasuHitoApp, RendererGl )
