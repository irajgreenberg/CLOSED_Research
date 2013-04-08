//
//  Matrix4.h
//  Protobyte Libraryass

//  Created by Ira on 10/26/12.
//
//

#ifndef Protobyte_iig001_Matrix4_h
#define Protobyte_iig001_Matrix4_h

#include "Vector3.h"

namespace proto {

    // non member function
    void transpose(float mat4[16]);

    class Matrix4 {
    public:
        Matrix4();
        Matrix4(float mat4[16]);
        void transpose();
        void determinent();
        void mult(const Matrix4& m);
        Vector3 mult(const Vector3& vec);
        void add();
        void identity();

    private:
        float mat4[16];
    };

}

#endif
