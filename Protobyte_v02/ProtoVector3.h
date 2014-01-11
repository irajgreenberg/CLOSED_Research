// NOTE: something is screwy with my overloaded ops (Need to FIX)

/*!  \brief  ProtoVector3.h: Templated 3D vector class
 ProtoVector3.h
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
 
 This notice must be retained in any source distribution.
 
 \ingroup common
 This class is part of the group common (update)
 \sa NO LINK
 */

#ifndef PROTO_VECTOR3_H
#define PROTO_VECTOR3_H

#include <SFML/OpenGL.hpp>
#include <string.h>
#include <iostream>
#include <vector>
#include "ProtoMath.h"
#include <cmath>
#include <cassert>
#include "ProtoPoint3.h"


namespace ijg {
    
    // forward declaration for non-member ops
    template <class T> class ProtoVector3;
    
    /*****************************************************/
    /*            Non-Member Ops & Functions             */
    /*****************************************************/
    template <typename T>
    ProtoVector3<T> operator+(const ProtoVector3<T>& lhs, const ProtoVector3<T>& rhs); // add vecs
    
    template <typename T>
    ProtoVector3<T> operator-(const ProtoVector3<T>& lhs, const ProtoVector3<T>& rhs); // sub vecs
    
    template <typename T>
    ProtoVector3<T> operator*(const ProtoVector3<T>& lhs, const ProtoVector3<T>& rhs); // mult by vec
    
    template <typename T>
    ProtoVector3<T> operator/(const ProtoVector3<T>& lhs, const ProtoVector3<T>& rhs); // div by vec
    
    template <typename T>
    ProtoVector3<T> operator+(const ProtoVector3<T>& lhs, T s); // add by sclr (rhs)
    
    template <typename T>
    ProtoVector3<T> operator+(T s, const ProtoVector3<T>& rhs); // add by sclr (lhs)
    
    template <typename T>
    ProtoVector3<T> operator-(const ProtoVector3<T>& lhs, T s); // sub by sclr (rhs)
    
    template <typename T>
    ProtoVector3<T> operator-(T s, const ProtoVector3<T>& rhs); // sub by sclr (lhs)
    
    template <typename T>
    ProtoVector3<T> operator*(const ProtoVector3<T>& lhs, T s); // mult by sclr (rhs)
    
    template <typename T>
    ProtoVector3<T> operator*(T s, const ProtoVector3<T>& rhs); // mult by sclr (lhs)
    
    template <typename T>
    ProtoVector3<T> operator/(const ProtoVector3<T>& lhs, T s); // div by sclr (rhs)
    
    template <typename T>
    ProtoVector3<T> operator/(T s, const ProtoVector3<T>& rhs); // div by sclr (lhs)
    
    template <typename T>
    ProtoVector3<T> operator-(const ProtoVector3<T>& rhs); // negate vec
    
    template <typename T>
    T mag(const ProtoVector3<T>& v); // vec length
    
    template <typename T>
    T angleBetween(const ProtoVector3<T>& lhs, const ProtoVector3<T>& rhs); // angle between vecs
    
    template <typename T>
    T dot(const ProtoVector3<T>& lhs, const ProtoVector3<T>& rhs); // dot product
    
    template <typename T>
    ProtoVector3<T> cross(const ProtoVector3<T>& lhs, const ProtoVector3<T>& rhs); // cross product
    
    
    // class declaration
    template <class T>
    class ProtoVector3 {
        
    public:
        
        // randomization
        enum RandFlag {
            EXPLICIT, // use arg as explicit value
            RANDOMIZED // use arg as random max value
        };
        
        
        // overloaded << operator declared as friend function for access to private data
        template <typename U>
        friend std::ostream& operator<<(std::ostream& output, const ProtoVector3<U>& v);
        
        // fields (public for major convenience)
        T x, y, z;
        
        /*****************************************************/
        /*                    Constructors                   */
        /*****************************************************/
        ProtoVector3(RandFlag randFlagVal=EXPLICIT);
        ProtoVector3(T xMax, T yMax, T zMax, RandFlag randFlagVal=EXPLICIT);
        ProtoVector3(T xMin, T xMax, T yMin, T yMax, T zMin, T zMax);
        
        /*****************************************************/
        /*              Member Overloaded Ops                */
        /*****************************************************/
        ProtoVector3<T>& operator+=(const ProtoVector3<T>& v);
        ProtoVector3<T>& operator+=(T s);
        ProtoVector3<T>& operator-=(const ProtoVector3<T>& v);
        ProtoVector3<T>& operator-=(T s);
        ProtoVector3<T>& operator*=(const ProtoVector3<T>& v);
        ProtoVector3<T>& operator*=(T s);
        ProtoVector3<T>& operator/=(const ProtoVector3<T>& v);
        ProtoVector3<T>& operator/=(T s);
        ProtoVector3<T>& operator++();
        ProtoVector3<T>& operator++(int);
        ProtoVector3<T>& operator--();
        ProtoVector3<T>& operator--(int);
        ProtoVector3<T>& operator()(T xMax, T yMax, T zMax, RandFlag randFlagVal=EXPLICIT);
        ProtoVector3<T>& operator()(T xyzMax, RandFlag randFlagVal=EXPLICIT);
        ProtoVector3<T>& operator()(T xMin, T xMax, T yMin, T yMax, T zMin, T zMax);
        
        T operator[](unsigned index);
        const T operator[](unsigned index) const;
        bool operator==(const ProtoVector3<T>& v) const;
        bool operator!=(const ProtoVector3<T>& v) const;
        
        /*****************************************************/
        /*                 Member Functions                  */
        /*****************************************************/
        T mag() const;
        T magSqr() const;
        void normalize();
        bool isNormalized() const;
        T angleXAxis() const;
        T angleYAxis() const;
        T angleZAxis() const;
        T angleBetween(const ProtoVector3<T>& v) const;
        T dot(const ProtoVector3<T>& v) const;
        ProtoVector3<T>& cross(const ProtoVector3<T>& v);
        ProtoVector3<T>& rotateX(T theta);
        ProtoVector3<T>& rotateY(T theta);
        ProtoVector3<T>& rotateZ(T theta);
        ProtoVector3<T>& rotateAxis(const ProtoVector3<T>& axis, T theta);
        ProtoVector3<T>& reflect(const ProtoVector3<T>& axis);
        // require containers passed in
        void lerp (const ProtoVector3<T>& v, unsigned steps,  std::vector<ProtoPoint3<T>>& ptsContainer) const;
        void lerpVecs (const ProtoVector3<T>& v, unsigned steps,  std::vector<ProtoVector3<T>>& vecsContainer) const;
        
        
    private:
        // nada here for now
        
    }; // END ProtoVector3 class declaration
    
    
    /*****************************************************/
    /*                    Constructors                   */
    /*****************************************************/
    // optional randomization
    template <class T>
    inline ProtoVector3<T>::ProtoVector3(RandFlag randFlagVal) {
        if(randFlagVal == RANDOMIZED){
            x = ProtoMath::random();
            y = ProtoMath::random();
            z = ProtoMath::random();
        } else {
            x = 0;
            y = 0;
            z = 0;
        }
    }
    
    // optional randomization
    template <class T>
    inline ProtoVector3<T>::ProtoVector3(T xMax, T yMax, T zMax, RandFlag randFlagVal){
        if(randFlagVal == RANDOMIZED){
            x = ProtoMath::random(xMax);
            y = ProtoMath::random(yMax);
            z = ProtoMath::random(zMax);
        } else {
            x = xMax;
            y = yMax;
            z = zMax;
        }
    }
    
    // randomized
    template <class T>
    inline ProtoVector3<T>::ProtoVector3(T xMin, T xMax, T yMin, T yMax, T zMin, T zMax){
        x = ProtoMath::random(xMin, xMax);
        y = ProtoMath::random(yMin, yMax);
        z = ProtoMath::random(zMin, zMax);
    }
    
    
    /*****************************************************/
    /*              Member Overloaded Ops                */
    /*****************************************************/
    template <class T>
    inline ProtoVector3<T>& ProtoVector3<T>::operator+=(const ProtoVector3<T>& v){
        x+=v.x;
        y+=v.y;
        z+=v.z;
        return *this;
    }
    
    template <class T>
    inline ProtoVector3<T>& ProtoVector3<T>::operator+=(T s){
        x+=s;
        y+=s;
        z+=s;
        return *this;
    }
    
    template <class T>
    inline ProtoVector3<T>& ProtoVector3<T>::operator-=(const ProtoVector3<T>& v){
        x-=v.x;
        y-=v.y;
        z-=v.z;
        return *this;
    }
    
    template <class T>
    inline ProtoVector3<T>& ProtoVector3<T>::operator-=(T s){
        x-=s;
        y-=s;
        z-=s;
        return *this;
    }
    
    template <class T>
    inline ProtoVector3<T>& ProtoVector3<T>::operator*=(const ProtoVector3<T>& v){
        x*=v.x;
        y*=v.y;
        z*=v.z;
        return *this;
    }
    
    template <class T>
    inline ProtoVector3<T>& ProtoVector3<T>::operator*=(T s){
        x*=s;
        y*=s;
        z*=s;
        return *this;
    }
    
    template <class T>
    inline ProtoVector3<T>& ProtoVector3<T>::operator/=(const ProtoVector3<T>& v){
        x/=v.x;
        y/=v.y;
        z/=v.z;
        return *this;
    }
    
    template <class T>
    inline ProtoVector3<T>& ProtoVector3<T>::operator/=(T s){
        x/=s;
        y/=s;
        z/=s;
        return *this;
    }
    
    template <class T>
    inline ProtoVector3<T>& ProtoVector3<T>::operator++(){
        x++;
        y++;
        z++;
        return *this;
    }
    
    
    template <class T>
    inline ProtoVector3<T>& ProtoVector3<T>::operator++(int){
        ++x;
        ++y;
        ++z;
        return *this;
    }
    
    
    template <class T>
    inline ProtoVector3<T>& ProtoVector3<T>::operator--(){
        x--;
        y--;
        z--;
        return *this;
    }
    
    template <class T>
    inline ProtoVector3<T>& ProtoVector3<T>::operator--(int){
        --x;
        --y;
        --z;
        return *this;
    }
    
    template <class T>
    inline ProtoVector3<T>& ProtoVector3<T>::operator()(T xMax, T yMax, T zMax, RandFlag randFlagVal) {
        if(randFlagVal == RANDOMIZED){
            x = ProtoMath::random(xMax);
            y = ProtoMath::random(yMax);
            z = ProtoMath::random(zMax);
        } else {
            x = xMax;
            y = yMax;
            z = zMax;
        }
        return *this;
    }
    
    template <class T>
    inline ProtoVector3<T>& ProtoVector3<T>::operator()(T xyzMax, RandFlag randFlagVal) {
        if(randFlagVal == RANDOMIZED){
            x = ProtoMath::random(xyzMax);
            y = ProtoMath::random(xyzMax);
            z = ProtoMath::random(xyzMax);
        } else {
            x = xyzMax;
            y = xyzMax;
            z = xyzMax;
        }
        return *this;
    }
    
    template <class T>
    inline ProtoVector3<T>& ProtoVector3<T>::operator()(T xMin, T xMax, T yMin, T yMax, T zMin, T zMax) {
        x = ProtoMath::random(xMin, xMax);
        y = ProtoMath::random(yMin, yMax);
        z = ProtoMath::random(zMin, zMax);
        return *this;
    }
    
    template <class T>
    inline T ProtoVector3<T>::operator[](unsigned index){
        assert( index >= 0 && index <= 2 );
        return *(&x+index);
    }
    
    template <class T>
    inline const T ProtoVector3<T>::operator[](unsigned index) const{
        assert( index >= 0 && index <= 2 );
        return *(&x+index);
    }
    
    
    template <class T>
    inline bool ProtoVector3<T>::operator==(const ProtoVector3<T>& v) const{
        return (x==v.x && y==v.y && z==v.z);
    }
    
    template <class T>
    inline bool ProtoVector3<T>::operator!=(const ProtoVector3<T>& v) const{
        return (x!=v.x || y!=v.y || z!=v.z);
    }
    
    /*****************************************************/
    /*                 Member Functions                  */
    /*****************************************************/
    template <class T>
    inline T ProtoVector3<T>::mag() const{
        return sqrt(x*x + y*y + z*z);
    }
    
    template <class T>
    inline T ProtoVector3<T>::magSqr() const{
        return x*x + y*y + z*z;
    }
    
    template <class T>
    inline void ProtoVector3<T>::normalize(){
        T m = mag();
        x/=m;
        y/=m;
        z/=m;
    }
    
    template <class T>
    inline bool ProtoVector3<T>::isNormalized() const{
        return (mag() > .99 && mag() < 1.1); // must be better way to check this
    }
    
    template <class T>
    inline T ProtoVector3<T>::angleXAxis() const{
        ProtoVector3<T> v(1.0, 0, 0);
        return acos( (*this).dot(v) / (mag()*v.mag()) );
    }
    
    template <class T>
    inline T ProtoVector3<T>::angleYAxis() const{
        ProtoVector3<T> v(0.0, 1.0, 0);
        return acos( (*this).dot(v) / (mag()*v.mag()) );
    }
    
    template <class T>
    inline T ProtoVector3<T>::angleZAxis() const{
        ProtoVector3<T> v(0.0, 0.0, -1.0);
        return acos( (*this).dot(v) / (mag()*v.mag()) );
    }
    
    template <class T>
    inline T ProtoVector3<T>::angleBetween(const ProtoVector3<T>& v) const{
        return acos( (*this).dot(v) / (mag()*v.mag()) );
    }
    
    template <class T>
    inline T ProtoVector3<T>::dot(const ProtoVector3<T>& v) const{
        return x*v.x + y*v.y + z*v.z;
    }
    
    template <class T>
    inline ProtoVector3<T>& ProtoVector3<T>::cross(const ProtoVector3<T>& v){
        T cx = y * v.z - z * v.y;
        T cy = z * v.x - x * v.z;
        T cz = x * v.y - y * v.x;
        
        return (*this)(cx, cy, cz);
    }
    
    template <class T>
    inline ProtoVector3<T>& ProtoVector3<T>::rotateX(T theta){
        T s = sin(theta);
        T c = cos(theta);
        T tempY = y*c - z*s;
        T tempZ = y*s + z*c;
        return (*this)(x, tempY, tempZ);
    }
    
    template <class T>
    inline ProtoVector3<T>& ProtoVector3<T>::rotateY(T theta){
        T s = sin(theta);
        T c = cos(theta);
        T tempZ = z*c - x*s;
        T tempX = z*s + x*c;
        return (*this)(tempX, y, tempZ);
    }
    
    template <class T>
    inline ProtoVector3<T>& ProtoVector3<T>::rotateZ(T theta){
        T s = sin(theta);
        T c = cos(theta);
        T tempX = x*c - y*s;
        T tempY = x*s + y*c;
        return (*this)(tempX, tempY, z);
    }
    
    template <class T>
    inline ProtoVector3<T>& ProtoVector3<T>::rotateAxis(const ProtoVector3<T>& axis, T theta){
        T s = sin(theta);
        T c = cos(theta);
        T k = 1.0 - c;
        
        T tempX = x*c - y*s;
        T tempY = x*s + y*c;
        T tempZ = x*s + y*c;
        
        tempX = x * (c + k * axis.x * axis.x) + y * (k * axis.x * axis.y - s * axis.z)
        + z * (k * axis.x * axis.z + s * axis.y);
        tempY = x * (k * axis.x * axis.y + s * axis.z) + y * (c + k * axis.y * axis.y)
        + z * (k * axis.y * axis.z - s * axis.x);
        tempZ = x * (k * axis.x * axis.z - s * axis.y) + y * (k * axis.y * axis.z + s * axis.x)
        + z * (c + k * axis.z * axis.z);
        return (*this)(tempX, tempY, tempZ);
    }
    
    template <class T>
    inline ProtoVector3<T>& ProtoVector3<T>::reflect(const ProtoVector3<T>& axis){
        axis.normalize();
        return -(*this) + 2*axis * ((*this).dot(axis));
    }
    
    // fills passed in container
    template <class T>
    inline void ProtoVector3<T>::lerp(const ProtoVector3<T>& v, unsigned steps, std::vector<ProtoPoint3<T>>& ptsContainer) const{
        T stepVal = 1.0/steps;
        for (int i=1; i<steps; ++i) {
            T x = x*(1-stepVal*i)+v.x.stepVal*i;
            T y = y*(1-stepVal*i)+v.y.stepVal*i;
            T z = z*(1-stepVal*i)+v.z.stepVal*i;
            ptsContainer.push_back(ProtoPoint3<T>(x, y, z)); // record only new (non-terminal) points
        }
    }
    
    // fills passed in container
    template <class T>
    inline void ProtoVector3<T>::lerpVecs(const ProtoVector3<T>& v, unsigned steps, std::vector<ProtoVector3<T>>& vecsContainer) const{
        T stepVal = 1.0/steps;
        for (int i=1; i<steps; ++i) {
            T x = x*(1-stepVal*i)+v.x*stepVal*i;
            T y = y*(1-stepVal*i)+v.y*stepVal*i;
            T z = z*(1-stepVal*i)+v.z*stepVal*i;
            vecsContainer.push_back(ProtoVector3<T>(x, y, z)); // record only new (non-terminal) vecs
        }
    }
    
    
    /*****************************************************/
    /*         Non-Member Function implementation        */
    /*****************************************************/
    
    // add vecs
    template <typename T>
    inline ProtoVector3<T> operator+(const ProtoVector3<T>& lhs, const ProtoVector3<T>& rhs){
        return ProtoVector3<T>(lhs)+=rhs;
    }
    
    // subtract vecs
    template <typename T>
    inline ProtoVector3<T> operator-(const ProtoVector3<T>& lhs, const ProtoVector3<T>& rhs){
        return ProtoVector3<T>(lhs)-=rhs;
    }
    
    // mult vecs
    template <typename T>
    inline ProtoVector3<T> operator*(const ProtoVector3<T>& lhs, const ProtoVector3<T>& rhs) {
        return ProtoVector3<T>(lhs)*=rhs;
    }
    
    // div vecs
    template <typename T>
    inline ProtoVector3<T> operator/(const ProtoVector3<T>& lhs, const ProtoVector3<T>& rhs){
        return ProtoVector3<T>(lhs)/=rhs;
    }
    
    // add lhs by sclr
    template <typename T>
    inline ProtoVector3<T> operator+(const ProtoVector3<T>& lhs, T s){
        return ProtoVector3<T>(lhs)+=s;
    }
    
    // add rhs by sclr
    template <typename T>
    inline ProtoVector3<T> operator+(T s, const ProtoVector3<T>& rhs) {
        return ProtoVector3<T>(rhs)+=s;
    }
    
    // sub lhs by sclr
    template <typename T>
    inline ProtoVector3<T> operator-(const ProtoVector3<T>& lhs, T s){
        return ProtoVector3<T>(lhs)-=s;
    }
    
    // sub rhs by sclr
    template <typename T>
    inline ProtoVector3<T> operator-(T s, const ProtoVector3<T>& rhs) {
        return ProtoVector3<T>(rhs)-=s;
    }
    
    // mult lhs by sclr
    template <typename T>
    inline ProtoVector3<T> operator*(const ProtoVector3<T>& lhs, T s){
        return ProtoVector3<T>(lhs)*=s;
    }
    
    // mult rhs by sclr
    template <typename T>
    inline ProtoVector3<T> operator*(T s, const ProtoVector3<T>& rhs) {
        return ProtoVector3<T>(rhs)*=s;
    }
    
    // div lhs by sclr
    template <typename T>
    inline ProtoVector3<T> operator/(const ProtoVector3<T>& lhs, T s){
        return ProtoVector3<T>(lhs)/=s;
    }
    
    // div rhs by sclr
    template <typename T>
    inline ProtoVector3<T> operator/(T s, const ProtoVector3<T>& rhs) {
        return ProtoVector3<T>(rhs)/=s;
    }
    
    // invert signs
    template <typename T>
    inline ProtoVector3<T> operator-(const ProtoVector3<T>& rhs){
        return ProtoVector3<T>(rhs) *= static_cast<T>(-1);
    }
    
    // vec magnitude
    template <typename T>
    inline T mag(const ProtoVector3<T>& v){
        return sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
    }
    
    // angle between vecs
    template <typename T>
    inline T angleBetween(const ProtoVector3<T>& lhs, const ProtoVector3<T>& rhs){
        return acos( lhs.dot(rhs) / (lhs.mag()*rhs.mag()) );
    }
    
    // dot product
    template <typename T>
    inline T dot(const ProtoVector3<T>& lhs, const ProtoVector3<T>& rhs){
        return lhs.x*rhs.x + lhs.y*rhs.y, + lhs.z*rhs.z;
    }
    
    // cross product
    template <typename T>
    inline ProtoVector3<T> cross(const ProtoVector3<T>& lhs, const ProtoVector3<T>& rhs){
        ProtoVector3<T> cp;
        cp.x = lhs.y * rhs.z - lhs.z * rhs.y;
        cp.y = lhs.z * rhs.x - lhs.x * rhs.z;
        cp.z = lhs.x * rhs.y - lhs.y * rhs.x;
        return cp;
    }
    
    // outstream opp
    template <class T>
    inline std::ostream& operator<<(std::ostream& out, const ProtoVector3<T>& v){
        out << v.x << ", " << v.y << ", " << v.z;
        return out;
    }
    
    
    // Type name convenience macros
#define ProtoVector3f ProtoVector3<float>
#define ProtoVector3d ProtoVector3<double>
#define ProtoVec3f ProtoVector3<float>
#define ProtoVec3d ProtoVector3<double>
#define Vec3 ProtoVector3<float> // common use
#define Vec3f ProtoVector3<float>
#define Vec3d ProtoVector3<double>
    
    }  // END ijg namespace
    
#endif // PROTO_VECTOR3_H
