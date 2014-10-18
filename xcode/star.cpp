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

Star::Star( ci::vec2 Pos, float Rad, float SideNumb, ci::vec2 Window ){
    
    mPos      = Pos;
    mRad      = Rad;
    mSideNumb = SideNumb;
    mTheta    = -M_PI_2;
    mWindow   = Window;
    mRand     = randInt(mSideNumb/3, mSideNumb*2);
    
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
    for (int i = 0; i < mSideNumb; i++){
        
        mPositions[i].x = mRad * cos(i * deltaTheta + mTheta);
        mPositions[i].y = mRad * sin(i * deltaTheta + mTheta);
        gl::color( 1, 1, 0 );
        gl::drawStrokedCircle(mPositions[i], 100);

    }
}

void Star::dm(){
    for ( int i = 0; i < mSideNumb; i++){
         float deltaTheta = (M_PI * 2.0) / mSideNumb;
        gl::translate(mPositions[i].x, mPositions[i].y);
        
        mPositions[i]*(i * deltaTheta + mTheta);
        gl::color( 1, 0, 0 );
        
        gl::drawStrokedCircle(mPositions[i], 5);
        
    }
}

