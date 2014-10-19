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
#include "cinder/Rand.h"

class sacGeom{
public:
                              // Constructor
    virtual void addPoints(); // init
    virtual void draw();      // Construct a variant of the flower of life
};

class flOfLife : public sacGeom{
public:
    
    flOfLife( ci::vec2 Pos, float Rad, float SideNumb, ci::vec2 Window);
    
    
    void addPoints();
    void draw();
    
//    ci::vec2    mPos;
    ci::vec2    mWindow;
    
    
    float       mRad;
    float       mSideNumb;
    float       mTheta;
    float       mRand;
    
    std::vector<ci::vec2> mPositions;
    
    float mPos      = Pos;
    float mRad      = Rad;
    float mSideNumb = SideNumb;
    mTheta    = -M_PI_2;
    mWindow   = Window;
    mRand     = randInt(mSideNumb/3, mSideNumb*2);
    
};