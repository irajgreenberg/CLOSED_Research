/*!  \brief  ProtoMatrix4.cpp: 4D Matrix implementation
 ProtoMatrix4.cpp
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

#include "ProtoMatrix4.h"

using namespace ijg;

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

ProtoMatrix4::ProtoMatrix4() {
   identity();
}

ProtoMatrix4::ProtoMatrix4(float mat4[16]) {
    for (int i = 0; i < 16; i++) {
        this->mat4, mat4;
    }
}

void ProtoMatrix4::transpose() {
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

void ProtoMatrix4::determinent() {

}

void ProtoMatrix4::identity() {
   // build identity
    for(int i=0; i<16; i++){
        mat4[i] = 0;
        
        if(i==0 || i==5 || i==10 || i==15)
           mat4[i] = 1; 
    }
}
