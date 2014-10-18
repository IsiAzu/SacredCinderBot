//
//  star.cpp
//  SacredCinderBot
//
//  Created by Isi on 10/17/14.
//
//

#include "cinder/app/AppBasic.h"
#include <stdio.h>
#include <math.h>
#include "cinder/Vector.h"
#include "star.h"

using namespace ci;
using namespace ci::app;
using namespace std;

Star::Star(){
    
}

Star::Star( ci::vec2 Pos, ci::vec2 Center, float Rad, ci::vec2 WinSize, float SideNumb, ci::vec2 Window ){
    
    mPos      = Pos;
    mRad      = Rad;
    mWinSize  = WinSize;
    mSideNumb = SideNumb;
    mCenter   = Center;
    mTheta    = -M_PI_2;
    mWindow   = Window;
    
}

void Star::addPoints(){
    
    for ( int i = 0; i < Star::mSideNumb; i++){
        mPositions.push_back(mPos);
    }
    
}

void Star::draw(){
   
        //Translate to center of the window:
    gl::translate(mWindow.x/2, mWindow.y/2);
    
        //Find the angle between each point:
    float deltaTheta = (M_PI * 2.0) / mSideNumb;
    
        //Iterate over each point, color and
        //place circle at that point:
    for (int i = 0; i < Star::mSideNumb; i++){
        
        mPositions[i].x = mRad * cos(i * deltaTheta + mTheta);
        mPositions[i].y = mRad * sin(i * deltaTheta + mTheta);
        gl::color( 1, 0, 0 );
        gl::drawSolidCircle(mPositions[i], 2);

    }
}

