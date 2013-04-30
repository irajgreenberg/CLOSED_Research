//
//  Vector3.cpp
//  Protobyte Library V01
//
//  Created by Ira Greenberg on 8/2/11.
//  Copyright 2011 SMU. All rights reserved.
//

#include "Vector3.h"
#include <iostream>


namespace proto {

    /*****************************************************/
    /*            Non-Member Ops & Functions             */

    /*****************************************************/
    Vector3 operator+(const Vector3& lhs, const Vector3& rhs)
    // postcondition: returns lhs += rhs
    {
        return Vector3(lhs) += rhs;
    }

    Vector3 operator-(const Vector3& rhs)
    // postcondition: returns lhs -= rhs
    {
        return Vector3(-rhs.x, -rhs.y, -rhs.z);
    }
    
    Vector3 operator-(const Vector3& lhs, const Vector3& rhs)
    // postcondition: returns lhs -= rhs
    {
        return Vector3(lhs) -= rhs;
    }

    Vector3 operator*(const Vector3& lhs, double rhs)
    // postcondition: returns lhs *= rhs
    {
        return Vector3(lhs) *= rhs;
    }
    
    Vector3 operator*(double lhs, const Vector3& rhs)
    {
        return Vector3(rhs) *= lhs;
    }

    Vector3 operator*(const Vector3& lhs, const Vector3& rhs)
    // postcondition: returns lhs *= rhs
    {
        return Vector3(lhs) *= rhs;
    }

    Vector3 operator/(const Vector3& lhs, const Vector3& rhs)
    // postcondition: returns lhs /= rhs
    {
        return Vector3(lhs) /= rhs;
    }

    Vector3 cross(const Vector3& lhs, const Vector3& rhs) {
        Vector3 cp;
        cp.x = lhs.y * rhs.z - lhs.z * rhs.y;
        cp.y = lhs.z * rhs.x - lhs.x * rhs.z;
        cp.z = lhs.x * rhs.y - lhs.y * rhs.x;
        return cp;
    }

    double mag(const Vector3& v) {
        return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
    }

    double dot(const Vector3& lhs, const Vector3& rhs) {
        return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
    }

    Vector3 rotate(double theta, const Vector3& axis, const Vector3& v) {
        Vector3 rv;
        double s = sin(theta);
        double c = cos(theta);
        double k = 1.0 - c;

        rv.x = v.x * (c + k * axis.x * axis.x) + v.y * (k * axis.x * axis.y - s * axis.z)
                + v.z * (k * axis.x * axis.z + s * axis.y);
        rv.y = v.x * (k * axis.x * axis.y + s * axis.z) + v.y * (c + k * axis.y * axis.y)
                + v.z * (k * axis.y * axis.z - s * axis.x);
        rv.z = v.x * (k * axis.x * axis.z - s * axis.y) + v.y * (k * axis.y * axis.z + s * axis.x)
                + v.z * (c + k * axis.z * axis.z);

        return rv;

    }

    double angle(const Vector3& lhs, const Vector3& rhs) {
        // ====================================
        // USE Equation: a•b = |a||b|cosθ
        // 1. Get dot product: a•b
        // 2. Get magnitudes: |a||b|
        // 3. solve for theta
        //   θ = acos(a•b/|a||b|)
        // ====================================

        double d = dot(lhs, rhs);
        double lm = mag(lhs);
        double rm = mag(rhs);
        double ang = acos(d / (lm * rm));

        return ang;
    }

    // overloaded << operator for outputting field values in objects
    std::ostream& operator<<(std::ostream& output, const Vector3& vec) {
        output << "(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
        return output;
    }
}


/*****************************************************/
/************BEGIN MEMBER IMPLEMENTATION**************/
/*****************************************************/
using namespace proto;

// initialize static counter
// keeps track of all the vectors created
int Vector3::totolVector3Count = 0;


/*****************************************************/
/*                   Constructors                    */

/*****************************************************/
Vector3::Vector3(double x, double y, double z, float r, float g, float b, float a) :
x(x), y(y), z(z), r(r), g(g), b(b), a(a) {
    // increment static vector count
    totolVector3Count++;
}

Vector3::Vector3(double xyz[3]) {
    x = xyz[0];
    y = xyz[1];
    z = xyz[2];
    r = g = b = a = 0;
    totolVector3Count++;
}

Vector3::Vector3(double xyz[3], float rgba[4]) {
    x = xyz[0];
    y = xyz[1];
    z = xyz[2];
    r = rgba[0];
    g = rgba[1];
    b = rgba[2];
    a = rgba[3];
    totolVector3Count++;
}

/*****************************************************/
/*              Member Overloaded Ops                */

/*****************************************************/
Vector3& Vector3::operator+=(const Vector3& v) {
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

Vector3& Vector3::operator+=(double f) {
    x += f;
    y += f;
    z += f;
    return *this;
}

Vector3& Vector3::operator-=(const Vector3& v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}

Vector3& Vector3::operator-=(double f) {
    x -= f;
    y -= f;
    z -= f;
    return *this;
}

Vector3& Vector3::operator*=(const Vector3& v) {
    x *= v.x;
    y *= v.y;
    z *= v.z;
    return *this;
}

Vector3& Vector3::operator*=(double f) {
    x *= f;
    y *= f;
    z *= f;
    return *this;
}

Vector3& Vector3::operator/=(const Vector3& v) {
    x /= v.x;
    y /= v.y;
    z /= v.z;
    return *this;
}

Vector3& Vector3::operator/=(double f) {
    x /= f;
    y /= f;
    z /= f;
    return *this;
}

Vector3& Vector3::operator++() {
    x += 1;
    y += 1;
    z += 1;
    return *this;
}

Vector3& Vector3::operator--() {
    x -= 1;
    y -= 1;
    z -= 1;
    return *this;
}

double Vector3::operator[](int index) {
    double val = 0.0;
    switch (index) {
        case 0:
            return x;
            break;
        case 1:
            return y;
            break;
        case 2:
            return z;
            break;
        default:
            std::cout << "Error: index value out of range";
            break;
    }
    return val;
}


// == operator for comparison of field data

bool Vector3::operator==(const Vector3& v) const {
    if (x == v.x && y == v.y && z == v.z) {
        return true;
    }
    return false;
}



/*****************************************************/
/*                 Member Functions                  */

/*****************************************************/
double Vector3::mag() {
    double m = sqrt(x * x + y * y + z * z);
    return m;
}

void Vector3::normalize() {
    double m = mag();
    *this /= m;
}

double Vector3::angle(const Vector3& v) {
    // ====================================
    // USE Equation: a•b = |a||b|cosθ
    // 1. Get dot product: a•b
    // 2. Get magnitudes: |a||b|
    // 3. solve for theta
    //   θ = acos(a•b/|a||b|)
    // ====================================

    double d = dot(v);
    double am = mag();
    Vector3 b = v;
    double bm = b.mag();
    double ang = acos(d / (am * bm));

    return ang;
}

double Vector3::dot(const Vector3& v) {
    // copy vectors
    //Vector3 a = *this;
    //Vector3 b = v;

    //make unit vectors
    //a.normalize();
    //b.normalize();
    double d = x * v.x + y * v.y + z * v.z;
    return d;
}

Vector3 Vector3::cross(const Vector3& v) {
    Vector3 rhs;
    rhs.x = y * v.z - z * v.y;
    rhs.y = z * v.x - x * v.z;
    rhs.z = x * v.y - y * v.x;
    return rhs;
}

void Vector3::crossThis(const Vector3& v) {
    Vector3 temp;
    temp.x = y * v.z - z * v.y;
    temp.y = z * v.x - x * v.z;
    temp.z = x * v.y - y * v.x;
    *this = temp;
}

double Vector3::dist(const Vector3& v) {
    double dx = x - v.x;
    double dy = y - v.y;
    double dz = z - v.z;

    return sqrt(dx * dx + dy * dy + dz * dz);
}

// inspired/ported from C4 Vector4D api

Vector3& Vector3::rotate(double theta, const Vector3& axis) {
    double s = sin(theta);
    double c = cos(theta);
    double k = 1.0 - c;

    double tempX = x * (c + k * axis.x * axis.x) + y * (k * axis.x * axis.y - s * axis.z)
            + z * (k * axis.x * axis.z + s * axis.y);
    double tempY = x * (k * axis.x * axis.y + s * axis.z) + y * (c + k * axis.y * axis.y)
            + z * (k * axis.y * axis.z - s * axis.x);
    double tempZ = x * (k * axis.x * axis.z - s * axis.y) + y * (k * axis.y * axis.z + s * axis.x)
            + z * (c + k * axis.z * axis.z);

    x = tempX;
    y = tempY;
    z = tempZ;

    return (*this);
}




