#include "MawasuhitoApp.hpp"


void MawasuHitoApp::prepareSetting(Settings *settings)
{
    settings->setWindowSize(1024,768);
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
}

void MawasuHitoApp::draw()
{
    gl::clear( Color( 0, 0, 0 ) );
}

CINDER_APP_NATIVE( MawasuHitoApp, RendererGl )
