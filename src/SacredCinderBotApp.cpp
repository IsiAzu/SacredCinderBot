#include "cinder/app/AppNative.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "star.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class SacredCinderBotApp : public AppNative {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
    vec2 window;
    Star mStar;
};

void SacredCinderBotApp::setup()
{
    window = getWindowSize();
    std::cout << window << std::endl;
    mStar = Star( window/2.0f, 100, 8, window );
    mStar.addPoints();
}

void SacredCinderBotApp::mouseDown( MouseEvent event )
{
    
}

void SacredCinderBotApp::update()
{
    
}

void SacredCinderBotApp::draw()
{
    //clear the screen
    gl::clear( Color( 0, 0, 0 ) );

    
    gl::pushMatrices();
    mStar.draw();
    gl::popMatrices();
    
    gl::pushMatrices();
    mStar.dm();
    gl::popMatrices();
}

CINDER_APP_NATIVE( SacredCinderBotApp, RendererGl )
