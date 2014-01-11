//
//  Dimension3D.cpp
//  tut03_3d_ver02
//
//  Created by Ira Greenberg on 4/28/12.
//  Copyright 2012 SMU. All rights reserved.
//

#include <iostream>
#include "Dimension3D.h"

Dimension3D::Dimension3D(float w, float h, float d):
w(w), h(h), d(d)
{
}

Dimension3D::Dimension3D(float vals[3]):
w(vals[0]), h(vals[1]), d(vals[2])
{
}

// overloaded << operator
std::ostream& operator<<(std::ostream& output, const Dimension3D& dim)
{
    output << "(" << dim.w << ", " << dim.h << ", " << dim.d << ")";
    return output;
}