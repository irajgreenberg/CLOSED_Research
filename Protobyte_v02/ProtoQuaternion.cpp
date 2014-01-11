/*!  \brief  ProtoQuaternion.cpp: quaternion implementation
 ProtoQuaternion.cpp
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

#include "ProtoQuaternion.h"

using namespace ijg;

ProtoQuaternion::ProtoQuaternion(const ProtoVector3& axis, float theta):
axis(axis), theta(theta)
{
    
    if (this->axis.mag()>1) {
        this->axis.normalize();
    }
    float s = sin(theta/2);
    x = this->axis.x*s;
    y = this->axis.y*s;
    z = this->axis.z*s;
    w = cos(theta/2);
}

ProtoQuaternion::ProtoQuaternion(float x, float y, float z, float w):
x(x), y(y), z(z), w(x){
}

// implement as overloaded op
/*ProtoQuaternion::ProtoQuaternion mult(const ProtoQuaternion& q) {
    float qx = w*q.x + x*q.w + y*q.z - z*q.y;
    float qy = w*q.y - x*q.z + y*q.w + z*q.x;
    float qz = w*q.z + x*q.y - y*q.x + z*q.w;
    float qw = w*q.w - x*q.x - y*q.y - z*q.z;
    return new ProtoQuaternion(qx, qy, qz, qw);
}*/

/*void ProtoQuaternion::rotate(ProtoVector3 v) {
    float newX = v.x*(1-2*y*y-2*z*z) + v.y*(2*x*y-2*w*z) + v.z*(2*x*z+2*w*y);
    float newY = v.x*(2*x*y+2*w*z) + v.y*(1-2*x*x-2*z*z) + v.z*(2*y*z+2*w*x);
    float newZ = v.x*(2*x*z-2*w*y) + v.y*(2*y*z-2*w*x) + v.z*(1-2*x*x-2*y*y);
    v.x = newX;
    v.y = newY;
    v.z = newZ;
}*/

ProtoVector3 ProtoQuaternion::getRotate(const ProtoVector3& v) {
    float newX = v.x*(1-2*y*y-2*z*z) + v.y*(2*x*y-2*w*z) + v.z*(2*x*z+2*w*y);
    float newY = v.x*(2*x*y+2*w*z) + v.y*(1-2*x*x-2*z*z) + v.z*(2*y*z+2*w*x);
    float newZ = v.x*(2*x*z-2*w*y) + v.y*(2*y*z-2*w*x) + v.z*(1-2*x*x-2*y*y);
    
    return ProtoVector3(newX, newY, newZ);
}

void ProtoQuaternion::rotate(ProtoVector3& v) {
    ProtoVector3 tempV = v;
    tempV.x = v.x*(1-2*y*y-2*z*z) + v.y*(2*x*y-2*w*z) + v.z*(2*x*z+2*w*y);
    tempV.y = v.x*(2*x*y+2*w*z) + v.y*(1-2*x*x-2*z*z) + v.z*(2*y*z+2*w*x);
    tempV.z = v.x*(2*x*z-2*w*y) + v.y*(2*y*z-2*w*x) + v.z*(1-2*x*x-2*y*y);
    
    v = tempV;
}

float ProtoQuaternion::mag() const{
    return sqrt(x*x + y*y + z*z + w*w);
}

void ProtoQuaternion::normalize() {
    float m = mag();
    // don't normalize if it's already a unit ProtoQuaternion
    if (m>1) {
        // implement overloaded op/
        x/=m;
        y/=m;
        z/=m;
        w/=m;
    }
}

void ProtoQuaternion::setAxis(const ProtoVector3& axis)
{
    this->axis = axis;
}

const ProtoVector3& ProtoQuaternion::getAxis() const
{
    return axis;
}

