/*!  \brief  ProtoMatrix3.cpp: 3D Matrix implementation
 ProtoMatrix3f.cpp
 Protobyte Library v02
 
 Created by Ira on 7/23/13.
 Copyright (c) 2013 Ira Greenberg. All rights reserved.
 
 Library Usage:
 This work is licensed under the Creative Commons
 Attribution-NonCommercial-ShareAlike 3.0 Unported License.
 To view a copy of this license, visit
 http://creativecommons.org/licenses/by-nc-sa/3.0/
 or send a letter to Creative Commons,
 444 Castro Street, Suite 900,
 Mountain View, California, 94041, USA.
 
 This notice must be retained any source distribution.
 
 \ingroup common
 This class is part of the group common (update)
 \sa NO LINK
 */

#include "ProtoMatrix3.h"

using namespace ijg;


// column 

ProtoMatrix3::ProtoMatrix3() {
    identity();
}

ProtoMatrix3f::ProtoMatrix3f(float mat3[9]) {
    for (int i = 0; i < 9; i++) {
        this->mat3[i] = mat3[i];
    }
}

void ProtoMatrix3f::transpose() {
    float temp[9];
    for (int i = 0; i < 3; i++) {
        for (int j = 0, k = 0; j < 9; j += 3) {
            temp[k++] = mat3[i + j];
        }
    }
    for (int i = 0; i < 9; i++) {
        mat3[i] = temp[i];
    }
}

void ProtoMatrix3f::determinent() {

}

void ProtoMatrix3f::identity() {
    // build identity
    for (int i = 0; i < 9; i++) {
        mat3[i] = 0;

        if (i == 0 || i == 4 || i == 8)
            mat3[i] = 1;
    }
}

ProtoVector3 ProtoMatrix3f::getRotate(float theta, const ProtoVector3& axis, const ProtoVector3& vec) {
    //std::cout << "vec in getRotate = " << vec << std::endl;
    float c = cos(theta);
    float s = sin(theta);
    // row 1
    mat3[0] = c + (axis.x * axis.x) * (1 - c);
    mat3[1] = axis.x * axis.y * (1 - c) - s * axis.z;
    mat3[2] = axis.z * axis.x * (1 - c) + s * axis.y;
    //row 2
    mat3[3] = axis.x * axis.y * (1 - c) + s * axis.z;
    mat3[4] = c + (axis.y * axis.y) * (1 - c);
    mat3[5] = axis.z * axis.y * (1 - c) - s * axis.x;
    //row 3
    mat3[6] = axis.x * axis.z * (1 - c) - s * axis.y;
    mat3[7] = axis.y * axis.z * (1 - c) + s * axis.x;
    mat3[8] = c + (axis.z * axis.z) * (1 - c);

    ProtoVector3 temp;
    temp.x = vec.x * mat3[0] + vec.y * mat3[1] + vec.z * mat3[2];
    temp.y = vec.x * mat3[3] + vec.y * mat3[4] + vec.z * mat3[5];
    temp.z = vec.x * mat3[6] + vec.y * mat3[7] + vec.z * mat3[8];

    return temp;
}
