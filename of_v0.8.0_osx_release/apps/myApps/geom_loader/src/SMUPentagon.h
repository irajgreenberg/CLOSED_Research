//
//  SMUPentagon.h
//  tut03
//
//  Created by Ira Greenberg on 2/9/12.
//  Copyright 2012 C3, SMU. All rights reserved.
//

#ifndef TUT03_PARTICLES_SMUPENTAGON_H
#define TUT03_PARTICLES_SMUPENTAGON_H

#include "ofMain.h"

class SMUPentagon {
    
private:
    float radius;
    ofVec2f loc;
    ofVec2f spd;
    ofVec2f vecs[5];
    
    void init();
    
public:
    
    //constructors
    SMUPentagon();
    SMUPentagon(float radius);
    SMUPentagon(float radius, ofVec2f loc);
    SMUPentagon(float radius, ofVec2f loc, ofVec2f spd);
    
   
    void move();
    void display();
    
    
    void setRadius(float radius);
    float getRadius();
    
};

#endif
