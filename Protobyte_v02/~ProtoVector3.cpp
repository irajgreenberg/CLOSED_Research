/*!  \brief  ProtoVector3.cpp: Base vector implementation
 ProtoVector3.cpp
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

#include "ProtoVector3.h"
#include <iostream>


namespace ijg {

    /*****************************************************/
    /*            Non-Member Ops & Functions             */
    /*****************************************************/
    ProtoVector3 operator+(const ProtoVector3& lhs, const ProtoVector3& rhs)
    // postcondition: returns lhs += rhs
    {
        return ProtoVector3(lhs) += rhs;
    }

    ProtoVector3 operator-(const ProtoVector3& rhs)
    // postcondition: returns lhs -= rhs
    {
        return ProtoVector3(-rhs.x, -rhs.y, -rhs.z);
    }

    ProtoVector3 operator-(const ProtoVector3& lhs, const ProtoVector3& rhs)
    // postcondition: returns lhs -= rhs
    {
        return ProtoVector3(lhs) -= rhs;
    }

    ProtoVector3 operator*(const ProtoVector3& lhs, double rhs)
    // postcondition: returns lhs *= rhs
    {
        return ProtoVector3(lhs) *= rhs;
    }

    ProtoVector3 operator*(double lhs, const ProtoVector3& rhs) {
        return ProtoVector3(rhs) *= lhs;
    }

    ProtoVector3 operator*(const ProtoVector3& lhs, const ProtoVector3& rhs)
    // postcondition: returns lhs *= rhs
    {
        return ProtoVector3(lhs) *= rhs;
    }

    ProtoVector3 operator/(const ProtoVector3& lhs, const ProtoVector3& rhs)
    // postcondition: returns lhs /= rhs
    {
        return ProtoVector3(lhs) /= rhs;
    }

    ProtoVector3 cross(const ProtoVector3& lhs, const ProtoVector3& rhs) {
        ProtoVector3 cp;
        cp.x = lhs.y * rhs.z - lhs.z * rhs.y;
        cp.y = lhs.z * rhs.x - lhs.x * rhs.z;
        cp.z = lhs.x * rhs.y - lhs.y * rhs.x;
        return cp;
    }

    double mag(const ProtoVector3& v) {
        return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
    }

    double dot(const ProtoVector3& lhs, const ProtoVector3& rhs) {
        return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
    }

    ProtoVector3 rotate(double theta, const ProtoVector3& axis, const ProtoVector3& v) {
        ProtoVector3 rv;
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

    double angle(const ProtoVector3& lhs, const ProtoVector3& rhs) {
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

    std::ostream& operator<<(std::ostream& output, const ProtoVector3& vec) {
        output << "(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
        return output;
    }
}


/*****************************************************/
/************BEGIN MEMBER IMPLEMENTATION**************/
/*****************************************************/
using namespace ijg;

// initialize static counter
// keeps track of all the vectors created
int ProtoVector3::totolVector3Count = 0;


/*****************************************************/
/*                   Constructors                    */

/*****************************************************/
ProtoVector3::ProtoVector3() :
x(0.0), y(0.0), z(0.0) {
    x = 0;
    y = 0;
    z = 0;
}

ProtoVector3::ProtoVector3(double xyz) :
x(xyz), y(xyz), z(xyz) {
}

ProtoVector3::ProtoVector3(double x, double y, double z) :
x(x), y(y), z(z) {
}

//ProtoVector3::ProtoVector3(double x, double y, double z, float r, float g, float b, float a) :
//x(x), y(y), z(z), r(r), g(g), b(b), a(a) {
//    // increment static vector count
//    totolProtoVector3Count++;
//}

ProtoVector3::ProtoVector3(double xyz[3]) {
    x = xyz[0];
    y = xyz[1];
    z = xyz[2];
    r = g = b = a = 0;
    totolVector3Count++;
}

//ProtoVector3::ProtoVector3(double xyz[3], float rgba[4]) {
//    x = xyz[0];
//    y = xyz[1];
//    z = xyz[2];
//    r = rgba[0];
//    g = rgba[1];
//    b = rgba[2];
//    a = rgba[3];
//    totolProtoVector3Count++;
//}

/*****************************************************/
/*              Member Overloaded Ops                */

/*****************************************************/
ProtoVector3& ProtoVector3::operator+=(const ProtoVector3& v) {
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

ProtoVector3& ProtoVector3::operator+=(double f) {
    x += f;
    y += f;
    z += f;
    return *this;
}

ProtoVector3& ProtoVector3::operator-=(const ProtoVector3& v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}

ProtoVector3& ProtoVector3::operator-=(double f) {
    x -= f;
    y -= f;
    z -= f;
    return *this;
}

ProtoVector3& ProtoVector3::operator*=(const ProtoVector3& v) {
    x *= v.x;
    y *= v.y;
    z *= v.z;
    return *this;
}

ProtoVector3& ProtoVector3::operator*=(double f) {
    x *= f;
    y *= f;
    z *= f;
    return *this;
}

ProtoVector3& ProtoVector3::operator/=(const ProtoVector3& v) {
    x /= v.x;
    y /= v.y;
    z /= v.z;
    return *this;
}

ProtoVector3& ProtoVector3::operator/=(double f) {
    x /= f;
    y /= f;
    z /= f;
    return *this;
}

ProtoVector3& ProtoVector3::operator++() {
    x += 1;
    y += 1;
    z += 1;
    return *this;
}

ProtoVector3& ProtoVector3::operator--() {
    x -= 1;
    y -= 1;
    z -= 1;
    return *this;
}

double ProtoVector3::operator[](int index) {
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

bool ProtoVector3::operator==(const ProtoVector3& v) const {
    if (x == v.x && y == v.y && z == v.z) {
        return true;
    }
    return false;
}



/*****************************************************/
/*                 Member Functions                  */

/*****************************************************/
double ProtoVector3::mag() {
    /* if (x==0&&y==0&&z==0){
        return 1.0; 
     }*/
    double m = sqrt(x * x + y * y + z * z);
    //std::cout << "m = " << m << std::endl;
    return m;
}

void ProtoVector3::normalize() {
    double m = mag();
    // std::cout << "mag = " << m << std::endl;
    if (m != 0) {
        *this /= m;
    }
}

double ProtoVector3::angle(const ProtoVector3& v) {
    // ====================================
    // USE Equation: a•b = |a||b|cosθ
    // 1. Get dot product: a•b
    // 2. Get magnitudes: |a||b|
    // 3. solve for theta
    //   θ = acos(a•b/|a||b|)
    // ====================================

    double d = dot(v);
    double am = mag();
    ProtoVector3 b = v;
    double bm = b.mag();
    double ang = acos(d / (am * bm));

    return ang;
}

double ProtoVector3::dot(const ProtoVector3& v) {
    // copy vectors
    //ProtoVector3 a = *this;
    //ProtoVector3 b = v;

    //make unit vectors
    //a.normalize();
    //b.normalize();
    double d = x * v.x + y * v.y + z * v.z;
    return d;
}

ProtoVector3 ProtoVector3::cross(const ProtoVector3& v) {
    ProtoVector3 rhs;

    rhs.x = y * v.z - z * v.y;
    rhs.y = z * v.x - x * v.z;
    rhs.z = x * v.y - y * v.x;
    
//    if (rhs.x==0 && rhs.y==0 && rhs.z == 0){
//        rhs.x = 0;
//        rhs.y = 0;
//        rhs.z = -1;
//    }
    return rhs;
}

void ProtoVector3::crossThis(const ProtoVector3& v) {
    ProtoVector3 temp;
    temp.x = y * v.z - z * v.y;
    temp.y = z * v.x - x * v.z;
    temp.z = x * v.y - y * v.x;
    *this = temp;
}

double ProtoVector3::dist(const ProtoVector3& v) {
    double dx = x - v.x;
    double dy = y - v.y;
    double dz = z - v.z;

    return sqrt(dx * dx + dy * dy + dz * dz);
}

// inspired/ported from C4 Vector4D api

ProtoVector3& ProtoVector3::rotate(double theta, const ProtoVector3& axis) {
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




