//
//  Box.h
//  tut03_3d_ver01
//
//  Created by Ira Greenberg on 4/10/12.
//  Copyright 2012 SMU. All rights reserved.
//

#ifndef tut03_3d_ver01_Box_h
#define tut03_3d_ver01_Box_h

#include <iostream>
#include "ofMain.h"


class Box {
    
    // overloaded << operator
    friend std::ostream& operator<<(std::ostream& output, const Box& box);
    
private:
    ofVec3f verts[8];
    ofVec3f norms[12];

    
public:
    Box();
    void display();
    
};


#endif
