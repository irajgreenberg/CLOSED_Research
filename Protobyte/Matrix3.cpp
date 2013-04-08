//
//  Matrix3.cpp
//  Protobyte_iig001
//
//  Created by Ira on 10/26/12.
//
//

#include "Matrix3.h"

using namespace proto;


// column 

Matrix3::Matrix3() {
   identity();
}

Matrix3::Matrix3(float mat3[9]) {
    for (int i = 0; i < 9; i++) {
        this->mat3, mat3;
    }
}

void Matrix3::transpose() {
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

void Matrix3::determinent() {

}

void Matrix3::identity() {
   // build identity
    for(int i=0; i<9; i++){
        mat3[i] = 0;
        
        if(i==0 || i==4 || i==8)
           mat3[i] = 1; 
    }
}

Vector3 Matrix3::getRotate(float theta, const Vector3& axis, const Vector3& vec) 
{
    float c = cos(theta);
    float s = sin(theta);
    // row 1
    mat3[0] = c + (axis.x*axis.x) * (1-c);
    mat3[1] = axis.x*axis.y*(1-c)-s*axis.z;
    mat3[2] = axis.z*axis.x*(1-c)+s*axis.y;
    //row 2
    mat3[3] = axis.x*axis.y*(1-c) + s*axis.z;
    mat3[4] = c + (axis.y*axis.y) * (1-c);
    mat3[5] = axis.z*axis.y*(1-c)-s*axis.x;
    //row 3
    mat3[6] = axis.x*axis.z*(1-c)-s*axis.y;
    mat3[7] = axis.y*axis.z*(1-c)+s*axis.x;
    mat3[8] = c + (axis.z*axis.z) * (1-c);
    
    Vector3 temp;
    temp.x = vec.x*mat3[0] + vec.y*mat3[1] + vec.z*mat3[2];
    temp.y = vec.x*mat3[3] + vec.y*mat3[4] + vec.z*mat3[5];
    temp.z = vec.x*mat3[6] + vec.y*mat3[7] + vec.z*mat3[8];
    
    return temp;
}
