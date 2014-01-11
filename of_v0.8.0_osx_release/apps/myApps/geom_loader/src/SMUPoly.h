//
//  SMUPoly.h
//  tut03_Particles_pointers
//
//  Created by Ira Greenberg on 2/23/12.
//  Copyright 2012 SMU. All rights reserved.
//

#ifndef tut03_Particles_pointers_SMUPoly_h
#define tut03_Particles_pointers_SMUPoly_h

#include "ofMain.h"

class SMUPoly {
    
    
public:
    
    // declare constructors
    SMUPoly();
    SMUPoly(int sides);
    SMUPoly(int sides, float radius);
    
    // declare destructor
    ~SMUPoly();
    
    // gen methods
    void init();
    void move();
    void display();
    
private:
    int sides;
    float radius;
    
    // array to hold vertices - need this to be dynamcially allocated
    ofVec2f* vecs;

};














#endif
