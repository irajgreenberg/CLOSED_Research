//
//  Quaternion.cpp
//  Protobyte_iig001
//
//  Created by Ira on 10/14/12.
//
//

#include "Quaternion.h"
using namespace ijg;

Quaternion::Quaternion(const ofVec3f& axis, float theta):
axis(axis), theta(theta)
{
    
    if (this->axis.length()>1) {
        this->axis.normalize();
    }
    float s = sin(theta/2);
    x = this->axis.x*s;
    y = this->axis.y*s;
    z = this->axis.z*s;
    w = cos(theta/2);
}

Quaternion::Quaternion(float x, float y, float z, float w) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}

// implement as overloaded op
/*Quaternion::Quaternion mult(const Quaternion& q) {
    float qx = w*q.x + x*q.w + y*q.z - z*q.y;
    float qy = w*q.y - x*q.z + y*q.w + z*q.x;
    float qz = w*q.z + x*q.y - y*q.x + z*q.w;
    float qw = w*q.w - x*q.x - y*q.y - z*q.z;
    return new Quaternion(qx, qy, qz, qw);
}*/

/*void Quaternion::rotate(ofVec3f v) {
    float newX = v.x*(1-2*y*y-2*z*z) + v.y*(2*x*y-2*w*z) + v.z*(2*x*z+2*w*y);
    float newY = v.x*(2*x*y+2*w*z) + v.y*(1-2*x*x-2*z*z) + v.z*(2*y*z+2*w*x);
    float newZ = v.x*(2*x*z-2*w*y) + v.y*(2*y*z-2*w*x) + v.z*(1-2*x*x-2*y*y);
    v.x = newX;
    v.y = newY;
    v.z = newZ;
}*/

ofVec3f Quaternion::getRotate(const ofVec3f& v) {
    float newX = v.x*(1-2*y*y-2*z*z) + v.y*(2*x*y-2*w*z) + v.z*(2*x*z+2*w*y);
    float newY = v.x*(2*x*y+2*w*z) + v.y*(1-2*x*x-2*z*z) + v.z*(2*y*z+2*w*x);
    float newZ = v.x*(2*x*z-2*w*y) + v.y*(2*y*z-2*w*x) + v.z*(1-2*x*x-2*y*y);
    
    return ofVec3f(newX, newY, newZ);
}

void Quaternion::rotate(ofVec3f& v) {
    ofVec3f tempV = v;
    tempV.x = v.x*(1-2*y*y-2*z*z) + v.y*(2*x*y-2*w*z) + v.z*(2*x*z+2*w*y);
    tempV.y = v.x*(2*x*y+2*w*z) + v.y*(1-2*x*x-2*z*z) + v.z*(2*y*z+2*w*x);
    tempV.z = v.x*(2*x*z-2*w*y) + v.y*(2*y*z-2*w*x) + v.z*(1-2*x*x-2*y*y);
    
    v = tempV;
}

float Quaternion::mag() const{
    return sqrt(x*x + y*y + z*z + w*w);
}

void Quaternion::normalize() {
    float m = mag();
    // don't normalize if it's already a unit Quaternion
    if (m>1) {
        // implement overloaded op/
        x/=m;
        y/=m;
        z/=m;
        w/=m;
    }
}

void Quaternion::setAxis(const ofVec3f& axis)
{
    this->axis = axis;
}

const ofVec3f& Quaternion::getAxis() const
{
    return axis;
}

