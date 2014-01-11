//
//  Surf3D.h
//  tut03_3d_ver01
//
//  Created by Ira Greenberg on 4/10/12.
//  Copyright 2012 SMU. All rights reserved.
//

#ifndef tut03_3d_ver01_Surf3D_h
#define tut03_3d_ver01_Surf3D_h

#include "ofMain.h"

class Surf3D {
    
private:
    ofVec3f vs[3];
    ofVec3f n;
    void calcNorm();
    
public:
    Surf3D(ofVec3f vs[3] = 0);
    Surf3D(const ofVec3f& v0, const ofVec3f& v1, const ofVec3f& v2);
    
    void display();
    ofVec3f* getNorm();
    void setVecs(ofVec3f vs[3]);
    void setVecs(const ofVec3f& v0, const ofVec3f& v1, const ofVec3f& v2);
};

#endif





















