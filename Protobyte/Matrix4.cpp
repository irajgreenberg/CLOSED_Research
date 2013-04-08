//
//  Matrix4.cpp
//  Protobyte_iig001
//
//  Created by Ira on 10/26/12.
//
//

#include "Matrix4.h"

using namespace proto;

// non member function

void transpose(float mat4[16]) {
    float temp[16];
    // std::cout << "size of mat4 = " << sizeof (mat4) << std::endl; // this get smaller when passed 64 to 8 bytes
    // std::cout << "size of temp = " << sizeof (temp) << std::endl;
    for (int i = 0, k = 0; i < 4; i++) {
        for (int j = 0; j < 16; j += 4) {
            temp[k++] = mat4[i + j];
        }
    }

    // memcpy(mat4, temp, 16); doesn't work! sizes don't allign, grr!
    for (int i = 0; i < 16; i++) {
        mat4[i] = temp[i];
    }

}

// column 

Matrix4::Matrix4() {
   identity();
}

Matrix4::Matrix4(float mat4[16]) {
    for (int i = 0; i < 16; i++) {
        this->mat4, mat4;
    }
}

void Matrix4::transpose() {
    float temp[16];
    for (int i = 0; i < 4; i++) {
        for (int j = 0, k = 0; j < 16; j += 4) {
            temp[k++] = mat4[i + j];
        }
    }
    for (int i = 0; i < 16; i++) {
        mat4[i] = temp[i];
    }
}

void Matrix4::determinent() {

}

void Matrix4::identity() {
   // build identity
    for(int i=0; i<16; i++){
        mat4[i] = 0;
        
        if(i==0 || i==5 || i==10 || i==15)
           mat4[i] = 1; 
    }
}
