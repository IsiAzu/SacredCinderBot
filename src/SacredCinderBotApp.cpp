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
    
    flOfLife mrou;
    flOfLife mtri;
};

void SacredCinderBotApp::setup()
{
    
    vec2 window = static_cast<vec2>( getWindowSize() );
    std::cout << window << std::endl;
    
    mrou = flOfLife( (window/2.0f), 100, 10, window );
    mtri = flOfLife( (window), 100, 10, window );
    
    mrou.addPoints();
    mtri.addPoints();
    
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
    mtri.drawTri();
//    gl::rotate(0.1);
    gl::popMatrices();
    
    gl::pushMatrices();
    mrou.drawRound();
    gl::popMatrices();
    
    
    

}

CINDER_APP_NATIVE( SacredCinderBotApp, RendererGl )
