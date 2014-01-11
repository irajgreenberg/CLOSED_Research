//
//  SMUPoly.cpp
//  tut03_Particles_pointers
//
//  Created by Ira Greenberg on 2/23/12.
//  Copyright 2012 SMU. All rights reserved.
//

#include <iostream>
#include "SMUPoly.h"

SMUPoly::SMUPoly()
{
}

SMUPoly::SMUPoly(int sides):
sides(sides)
{
    init();
}


SMUPoly::SMUPoly(int sides, float radius):
sides(sides), radius(radius)
{
    init();
}

// declare destructor
SMUPoly::~SMUPoly()
{
    delete [] vecs;
}


// gen methods
void SMUPoly::init() 
{
    vecs = new ofVec2f[sides];
    
    float theta = 0.0;
    for(int i=0; i<sides; i++){
        vecs[i] = ofVec2f(cos(theta)*radius, sin(theta)*radius);
        theta += TWO_PI/sides;
    }
    
}


void SMUPoly::move() 
{
    
}



void SMUPoly::display() 
{
    // fill shape
    ofSetColor(255, 100, 255);
    ofFill();
    
    ofSetPolyMode(OF_POLY_WINDING_ODD); // normal mode
    ofBeginShape();
    for(int i=0; i<sides; i++){
        ofVertex(vecs[i].x, vecs[i].y);
    }
    ofEndShape(OF_CLOSE);

}
































