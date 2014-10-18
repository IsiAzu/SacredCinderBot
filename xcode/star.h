//
//  star.h
//  SacredCinderBot
//
//  Created by Isi on 10/17/14.
//
//

#pragma once
#include <iostream>
#include <stdio.h>
#include <math.h>
#include "cinder/gl/gl.h"
#include "cinder/Vector.h"



class Star{
public:
    Star();
    Star( ci::vec2 Pos, ci::vec2 Center, float Rad, ci::vec2, float SideNumb, ci::vec2 Window);
    
    
    void addPoints();
    void draw();
    
    ci::vec2    mPos;
    ci::vec2    mWinSize;
    ci::vec2    mCenter;
    ci::vec2    mWindow;
    
    float       mRad;
    float       mSideNumb;
    float       mTheta;
    
    std::vector<ci::vec2> mPositions;
    
};