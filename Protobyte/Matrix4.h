//
//  Matrix4.h
//  Protobyte Libraryass

//  Created by Ira on 10/26/12.
//
//

#ifndef Protobyte_iig001_Matrix4_h
#define Protobyte_iig001_Matrix4_h

#include "Vector3.h"
#include <SFML/OpenGL.hpp>


// non member function
void transpose(float m4[16]);

class Matrix4 {
    
public:
    Matrix4();
    Matrix4(float mat4[16]);
    void rotate(float theta, const Vector3& axis, Vector3& v);
    Vector3 getRotate(float theta, const Vector3& axis, const Vector3& vec);
    void transpose();
    void determinent();
    void mult(const Matrix4& m);
    Vector3 mult(const Vector3& vec);
    void add();
    void identity();

private:
    float mat4[16];
};


#endif
