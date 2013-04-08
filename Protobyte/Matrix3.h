/* 
 * File:   Matrix3.h
 * Author: ira
 *
 * Created on March 6, 2013, 3:45 PM
 */

#ifndef MATRIX3_H
#define	MATRIX3_H
#include "Vector3.h"


namespace proto {

    class Matrix3 {
    public:
        Matrix3();
        Matrix3(float mat3[9]);
        void rotate(float theta, const Vector3& axis, Vector3& v);
        Vector3 getRotate(float theta, const Vector3& axis, const Vector3& vec);
        void transpose();
        void determinent();
        void mult(const Matrix3& m);
        Vector3 mult(const Vector3& vec);
        void add();
        void identity();

    private:
        float mat3[9];

    };
}

#endif	/* MATRIX3_H */

