//
//  Dimension3D.h
//  Simple class for bounding box size of a 3D shape
//
//  Created by Ira Greenberg on 4/28/12.
//  Copyright 2012 SMU. All rights reserved.
//

#ifndef tut03_3d_ver02_Dimension3D_h
#define tut03_3d_ver02_Dimension3D_h

class Dimension3D {
    
public:
    float w, h, d;
    
    Dimension3D(float w=0, float h=0, float d=0);
    Dimension3D(float vals[3]);
    
    // overloaded << operator
    friend std::ostream& operator<<(std::ostream& output, const Dimension3D& dim);
};

#endif
