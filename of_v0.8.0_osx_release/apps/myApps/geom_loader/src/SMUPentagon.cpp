//
//  SMUPentagon.cpp
//  tut03
//
//  Created by Ira Greenberg on 2/9/12.
//  Copyright 2012 C3, SMU. All rights reserved.
//

#include <iostream>
#include <SMUPentagon.h>


SMUPentagon::SMUPentagon()
{
}

SMUPentagon::SMUPentagon(float radius)
{
    this->radius = radius;
    loc = ofVec2f(0, 0);
    spd = ofVec2f(0, 0);
    init();

}

// uses initialization list - better approach!!
SMUPentagon::SMUPentagon(float radius, ofVec2f loc):
radius(radius), loc(loc)
{
    spd = ofVec2f(0, 0); // default values
    init();
}


// uses initialization list - better approach!!
SMUPentagon::SMUPentagon(float radius, ofVec2f loc, ofVec2f spd):
radius(radius), loc(loc), spd(spd) 
{
    init();
}



void SMUPentagon::init() 
{
    float theta = 0.0;
    for(int i=0; i<5; i++){
        vecs[i] = ofVec2f(cos(theta)*radius, sin(theta)*radius);
        theta += TWO_PI/5;
    }
}

void SMUPentagon::display() 
{
    
    // fill shape
    ofSetColor(255, 100, 255);
    ofFill();
    
    ofSetPolyMode(OF_POLY_WINDING_ODD); // normal mode
    ofBeginShape();
    for(int i=0; i<5; i++){
        ofVertex(loc.x + vecs[i].x, loc.y + vecs[i].y);
    }
    ofEndShape(OF_CLOSE);
}

void SMUPentagon::move() 
{
    loc += spd;
}

