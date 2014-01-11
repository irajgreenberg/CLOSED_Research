/*!  \brief  ProtoMatrix2.h: Templated 2D Matrix class
 ProtoMatrix2.h
 Protobyte Library v02
 
 Created by Ira on 8/5/13.
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
 
 
 // Right-handed coordinate system (OpenGL)
 // rotations counterclockwise
 
 // Column major ordering
 // OpenGL - column major
 // D3D - romw major
 // stored as 1D array
 /*********
 |  0  2  |
 |  1  3  |
 *********/

// rotate
/*********************
 |  cos(t)  -sin(t)  |
 |  sin(t)   cos(t)  |
 ********************/

// Standard (a.k.a. natural, canonical) basis
// x-axis, y-axis, z-axis
/**********
 |  1  0  |
 |  0  1  |
 *********/


\ingroup common
This class is part of the group common (update)
\sa NO LINK
*/

#ifndef Matrox_tests_ProtoMatrix2_h
#define Matrox_tests_ProtoMatrix2_h

#include <iostream>

namespace ijg {
    
    // forward class declaration for non member functions
    template <class T> class ProtoMatrix2; // forward declare class for non-member prototypes
    
    // non member functions
    ProtoMatrix2<T> operator+(const Matrix<T>& lhs, const Matrix<T>& rhs);
    ProtoMatrix2<T> operator-(const Matrix<T>& lhs, const Matrix<T>& rhs);
    ProtoMatrix2<T> operator-(const Matrix<T>& lhs);
     ProtoMatrix2<T> operator*(const Matrix<T>& lhs, T s);
     ProtoMatrix2<T> operator/(const Matrix<T>& lhs, T s);
    ProtoMatrix2<T> operator*(const Matrix<T>& lhs, const Matrix<T>& rhs);
    ProtoMatrix2<T> operator/(const Matrix<T>& lhs, const Matrix<T>& rhs);
    
    template <class T>
    class ProtoMatrix2 {
        
    public:
        ProtoMatrix2() {}
        
        ProtoMatrix2(T m0, T m1, T m2, T m3):
        m[0]:m0, m[1]:m1, m[2]:m2, m[3]:m3
        {}
        
        ProtoMatrix2(T m[4]):
        m(m){}
        
        virtual ~ProtoMatrix2() {}
        
        void invert();
        void transpose();
        T determinate();
        void identity();
        
        // overloaded ops
        ProtoMatrix2<T>& operator+=(int s); // add sclr
        ProtoMatrix2<T>& operator+=(T m[4]); // add 2x2 Mat
        ProtoMatrix2<T>& operator-=(int s); // subtract sclr
        ProtoMatrix2<T>& operator-=(T m[4]); // subtract 2x2 Mat
        ProtoMatrix2<T>& operator*=(T s); // mult 2x2 M at
        ProtoMatrix2<T>& operator/=(T s); // div sclr
        ProtoMatrix2<T>& operator*=(T m[4]); // mult 2x2 M
        ProtoVector2<T> operator*=(ProtoVector2<T> v); // mult 2d Vec
        T operator()(int sub); // access through subscript
        T operator()(int r, int c); // access through row, col
        T operator[](int sub); // access through subscript
        
    private:
        T m[4];
        
    }; // End ProtoMatrix2 declaration
    
    // non member function implementation
    ProtoMatrix2<T> operator+(const Matrix<T>& lhs, const Matrix<T>& rhs){
        lhs+=rhs;
        return lhs;
    }
    
    ProtoMatrix2<T> operator-(const Matrix<T>& lhs, const Matrix<T>& rhs){
        lhs-=rhs;
        return lhs;
    }
    
    ProtoMatrix2<T> operator-(const Matrix<T>& lhs){
        lhs*=-1;
        return lhs;
    }
    
    ProtoMatrix2<T> operator*(const Matrix<T>& lhs, T s){
        lhs*=s;
        return lhs;
    }
    
    ProtoMatrix2<T> operator/(const Matrix<T>& lhs, T s){
        lhs/=s;
        return lhs;
    }
    
    ProtoMatrix2<T> operator*(const Matrix<T>& lhs, const Matrix<T>& rhs){
        T m0 = lhs.m[0]*lhs.m[0]
        return lhs;
    }
    
    
    // functions
    template <class T>
    void ProtoMatrix2<T>::invert(){
    }
    
    template <class T>
    void ProtoMatrix2<T>::transpose(){
    }
    
    template <class T>
    void ProtoMatrix2<T>::identity(){
    }
    
    
    template <class T>
    T ProtoMatrix2<T>::determinate(){
    }
    
    ProtoMatrix2<T> ProtoMatrix2<T>::operator+(const Matrix<T>& m) {
        Matrix<T> temp(*this); //copy constructor
        return (temp += m);
    }
    
    // member ops
    template <class T>
    ProtoMatrix2<T>& ProtoMatrix2<T>::operator+=(int s) {
        m[0] += s;
        m[1] += s;
        m[2] += s;
        m[3] += s;
        return *this;
    }
    
    template <class T>
    ProtoMatrix2<T>& ProtoMatrix2<T>::operator+=(T m[4]) {
        this->m[0] += m[0];
        this->m[1] += m[1];
        this->m[2] += m[2];
        this->m[3] += m[3];
        return *this;
    }
    
    template <class T>
    ProtoMatrix2<T>& ProtoMatrix2<T>::operator-=(int s) {
        m[0] -= s;
        m[1] -= s;
        m[2] -= s;
        m[3] -= s;
        return *this;
    }
    
    template <class T>
    ProtoMatrix2<T>& ProtoMatrix2<T>::operator-=(T m[4]) {
        this->m[0] -= m[0];
        this->m[1] -= m[1];
        this->m[2] -= m[2];
        this->m[3] -= m[3];
        return *this;
    }
    
    template <class T>
    ProtoMatrix2<T>& ProtoMatrix2<T>::operator*=(T m[4]) {
        
    }
    
    template <class T>
    ProtoMatrix2<T>& ProtoMatrix2<T>::operator/=(ProtoVector2 v) {
        
    }
    
    template <class T>
    T ProtoMatrix2<T>::operator()(int sub) {
        
    }
    
    template <class T>
    T ProtoMatrix2<T>::operator()(int r, int c) {
        
    }
    
    template <class T>
    T ProtoMatrix2<T>::operator[](int sub) {
        
    }
    
    
    
    
    
    }
    
#endif // Matrox_tests_ProtoMatrix2_h
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
