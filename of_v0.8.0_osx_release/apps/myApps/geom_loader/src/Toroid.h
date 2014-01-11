//
//  Toroid.h
//  tut03_3d_ver02
//
//  Created by Ira Greenberg on 4/21/12.
//  Copyright 2012 SMU. All rights reserved.
//

#ifndef tut03_3d_ver02_Toroid_h
#define tut03_3d_ver02_Toroid_h

#include "ofMain.h"
#include "surf3D.h"

class Toroid {

private:
    ofVec3f loc;
    ofVec3f dim; // overall size of toroid
    int segs; // number of circular cross-sections
    float segRadius; // radius of cross-sections (tube thickness)
    int detail; // number of points around each cross-section
    
    ofVec3f** verts2D; // pointer to pointer used for dynamic 2d arrays
    Surf3D* surfs;
    
    int vertCount;
    int surfCount;
    
    void allocate();
    void init();
    
public:
    
    // constructors
    
    Toroid(ofVec3f loc = ofVec3f(0, 0, 0), ofVec3f dim = ofVec3f(1, 1, 1), int segs = 8, float segRadius = .2, int detail = 8);
    
    // destructor
    ~Toroid();
    
    // copy constructor
    Toroid(const Toroid& toroid_src);
    
    // overloaded assignemnt operator
    Toroid& operator= (const Toroid& toroid_src);
    
    
    void display();

};



#endif









