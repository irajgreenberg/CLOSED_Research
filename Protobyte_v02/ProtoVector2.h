/*!  \brief  ProtoVector2.h: Templated 2D vector class
 ProtoVector2.h
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

#ifndef PROTO_VECTOR2_H
#define PROTO_VECTOR2_H

#include <string.h>
#include <iostream>
#include <vector>
#include "ProtoMath.h"
#include <cmath>
#include <cassert>
#include "ProtoPoint2.h"


namespace ijg {
    
    // forward declaration for non-member ops
    template <class T> class ProtoVector2;
    
    /*****************************************************/
    /*            Non-Member Ops & Functions             */
    /*****************************************************/
    template <typename T>
    ProtoVector2<T> operator+(const ProtoVector2<T>& lhs, const ProtoVector2<T>& rhs); // add vecs
    
    template <typename T>
    ProtoVector2<T> operator-(const ProtoVector2<T>& lhs, const ProtoVector2<T>& rhs); // sub vecs
    
    template <typename T>
    ProtoVector2<T> operator*(const ProtoVector2<T>& lhs, const ProtoVector2<T>& rhs); // mult by vec
    
    template <typename T>
    ProtoVector2<T> operator/(const ProtoVector2<T>& lhs, const ProtoVector2<T>& rhs); // div by vec
    
    template <typename T>
    ProtoVector2<T> operator+(const ProtoVector2<T>& lhs, T s); // add by sclr (rhs)
    
    template <typename T>
    ProtoVector2<T> operator+(T s, const ProtoVector2<T>& rhs); // add by sclr (lhs)
    
    template <typename T>
    ProtoVector2<T> operator-(const ProtoVector2<T>& lhs, T s); // sub by sclr (rhs)
    
    template <typename T>
    ProtoVector2<T> operator-(T s, const ProtoVector2<T>& rhs); // sub by sclr (lhs)
    
    template <typename T>
    ProtoVector2<T> operator*(const ProtoVector2<T>& lhs, T s); // mult by sclr (rhs)
    
    template <typename T>
    ProtoVector2<T> operator*(T s, const ProtoVector2<T>& rhs); // mult by sclr (lhs)
    
    template <typename T>
    ProtoVector2<T> operator/(const ProtoVector2<T>& lhs, T s); // div by sclr (rhs)
    
    template <typename T>
    ProtoVector2<T> operator/(T s, const ProtoVector2<T>& rhs); // div by sclr (lhs)
    
    template <typename T>
    ProtoVector2<T> operator-(const ProtoVector2<T>& rhs); // negate vec
    
    template <typename T>
    T mag(const ProtoVector2<T>& v); // vec length
    
    template <typename T>
    T angleBetween(const ProtoVector2<T>& lhs, const ProtoVector2<T>& rhs); // angle between vecs
    
    template <typename T>
    T dot(const ProtoVector2<T>& lhs, const ProtoVector2<T>& rhs); // dot product
    
    
    // class declaration
    template <class T>
    class ProtoVector2 {
        
    public:
        
        // randomization
        enum RandFlag{
            EXPLICIT, // use arg as explicit value
            RANDOMIZED // use arg as random max value
        };
    
        
        // overloaded << operator declared as friend function for access to private data
        template <typename U>
        friend std::ostream& operator<<(std::ostream& output, const ProtoVector2<U>& v);
        
        // fields (public for major convenience)
        T x, y;
        
        /*****************************************************/
        /*                    Constructors                   */
        /*****************************************************/
        ProtoVector2(RandFlag randFlagVal=EXPLICIT);
        ProtoVector2(T xMax, T yMax, RandFlag randFlagVal=EXPLICIT);
        ProtoVector2(T xMin, T xMax, T yMin, T yMax);
        
        /*****************************************************/
        /*              Member Overloaded Ops                */
        /*****************************************************/
        ProtoVector2<T>& operator+=(const ProtoVector2<T>& v);
        ProtoVector2<T>& operator+=(T s);
        ProtoVector2<T>& operator-=(const ProtoVector2<T>& v);
        ProtoVector2<T>& operator-=(T s);
        ProtoVector2<T>& operator*=(const ProtoVector2<T>& v);
        ProtoVector2<T>& operator*=(T s);
        ProtoVector2<T>& operator/=(const ProtoVector2<T>& v);
        ProtoVector2<T>& operator/=(T s);
        ProtoVector2<T>& operator++();
        ProtoVector2<T>& operator++(int);
        ProtoVector2<T>& operator--();
        ProtoVector2<T>& operator--(int);
        ProtoVector2<T>& operator()(T xMax, T yMax, RandFlag randFlagVal=EXPLICIT);
        ProtoVector2<T>& operator()(T xyzMax, RandFlag randFlagVal=EXPLICIT);
        ProtoVector2<T>& operator()(T xMin, T xMax, T yMin, T yMax);
        
        T operator[](unsigned index);
        const T operator[](unsigned index) const;
        bool operator==(const ProtoVector2& v) const;
        bool operator!=(const ProtoVector2& v) const;
        
        /*****************************************************/
        /*                 Member Functions                  */
        /*****************************************************/
        T mag() const;
        T magSqr() const;
        void normalize();
        bool isNormalized() const;
        T angle() const;
        T angleBetween(const ProtoVector2<T>& v) const;
        T dot(const ProtoVector2<T>& v) const;
        ProtoVector2<T>& rotate(T theta);
        ProtoVector2<T>& reflect(const ProtoVector2<T>& axis);
        // containers passed in below
        void lerp (const ProtoVector2<T>& v, unsigned steps,  std::vector<ProtoPoint2<T>>& ptsContainer) const;
        void lerpVecs (const ProtoVector2<T>& v, unsigned steps,  std::vector<ProtoVector2<T>>& vecsContainer) const;
        
        
    private:
        // nada here for now
        
    }; // END ProtoVector2 class declaration
    
    
    /*****************************************************/
    /*                    Constructors                   */
    /*****************************************************/
    // optional randomization
    template <class T>
    inline ProtoVector2<T>::ProtoVector2(RandFlag randFlagVal) {
        if(randFlagVal == RANDOMIZED){
            x = ProtoMath::random();
            y = ProtoMath::random();
        } else {
            x = 0;
            y = 0;
        }
    }
    
    // optional randomization
    template <class T>
    inline ProtoVector2<T>::ProtoVector2(T xMax, T yMax, RandFlag randFlagVal){
        if(randFlagVal == RANDOMIZED){
            x = ProtoMath::random(xMax);
            y = ProtoMath::random(yMax);
        } else {
            x = xMax;
            y = yMax;
        }
    }
    
    // randomized
    template <class T>
    inline ProtoVector2<T>::ProtoVector2(T xMin, T xMax, T yMin, T yMax){
        x = ProtoMath::random(xMin, xMax);
        y = ProtoMath::random(yMin, yMax);
    }
    
    
    /*****************************************************/
    /*              Member Overloaded Ops                */
    /*****************************************************/
    template <class T>
    inline ProtoVector2<T>& ProtoVector2<T>::operator+=(const ProtoVector2<T>& v){
        x+=v.x;
        y+=v.y;
        return *this;
    }
    
    template <class T>
    inline ProtoVector2<T>& ProtoVector2<T>::operator+=(T s){
        x+=s;
        y+=s;
        return *this;
    }
    
    template <class T>
    inline ProtoVector2<T>& ProtoVector2<T>::operator-=(const ProtoVector2<T>& v){
        x-=v.x;
        y-=v.y;
        return *this;
    }
    
    template <class T>
    inline ProtoVector2<T>& ProtoVector2<T>::operator-=(T s){
        x-=s;
        y-=s;
        return *this;
    }
    
    template <class T>
    inline ProtoVector2<T>& ProtoVector2<T>::operator*=(const ProtoVector2<T>& v){
        x*=v.x;
        y*=v.y;
        return *this;
    }
    
    template <class T>
    inline ProtoVector2<T>& ProtoVector2<T>::operator*=(T s){
        x*=s;
        y*=s;
        return *this;
    }
    
    template <class T>
    inline ProtoVector2<T>& ProtoVector2<T>::operator/=(const ProtoVector2<T>& v){
        x/=v.x;
        y/=v.y;
        return *this;
    }
    
    template <class T>
    inline ProtoVector2<T>& ProtoVector2<T>::operator/=(T s){
        x/=s;
        y/=s;
        return *this;
    }
    
    template <class T>
    inline ProtoVector2<T>& ProtoVector2<T>::operator++(){
        x++;
        y++;
        return *this;
    }
    
    
    template <class T>
    inline ProtoVector2<T>& ProtoVector2<T>::operator++(int){
        ++x;
        ++y;
        return *this;
    }
    
    
    template <class T>
    inline ProtoVector2<T>& ProtoVector2<T>::operator--(){
        x--;
        y--;
        return *this;
    }
    
    template <class T>
    inline ProtoVector2<T>& ProtoVector2<T>::operator--(int){
        --x;
        --y;
        return *this;
    }
    
    template <class T>
    inline ProtoVector2<T>& ProtoVector2<T>::operator()(T xMax, T yMax, RandFlag randFlagVal) {
        if(randFlagVal == RANDOMIZED){
            x = ProtoMath::random(xMax);
            y = ProtoMath::random(yMax);
        } else {
            x = xMax;
            y = yMax;
        }
        return *this;
    }
    
    template <class T>
    inline ProtoVector2<T>& ProtoVector2<T>::operator()(T xyMax, RandFlag randFlagVal) {
        if(randFlagVal == RANDOMIZED){
            x = ProtoMath::random(xyMax);
            y = ProtoMath::random(xyMax);
        } else {
            x = xyMax;
            y = xyMax;
        }
        return *this;
    }
    
    template <class T>
    inline ProtoVector2<T>& ProtoVector2<T>::operator()(T xMin, T xMax, T yMin, T yMax) {
        x = ProtoMath::random(xMin, xMax);
        y = ProtoMath::random(yMin, yMax);
        return *this;
    }
    
    template <class T>
    inline T ProtoVector2<T>::operator[](unsigned index){
        assert( index >= 0 && index <= 1 );
        return *(&x+index);
    }
    
    template <class T>
    inline const T ProtoVector2<T>::operator[](unsigned index) const{
        assert( index >= 0 && index <= 1 );
        return *(&x+index);
    }
    
    
    template <class T>
    inline bool ProtoVector2<T>::operator==(const ProtoVector2<T>& v) const{
        return (x==v.x && y==v.y);
    }
    
    template <class T>
    inline bool ProtoVector2<T>::operator!=(const ProtoVector2<T>& v) const{
        return (x!=v.x || y!=v.y);
    }
    
    /*****************************************************/
    /*                 Member Functions                  */
    /*****************************************************/
    template <class T>
    inline T ProtoVector2<T>::mag() const{
        return sqrt(x*x + y*y);
    }
    
    template <class T>
    inline T ProtoVector2<T>::magSqr() const{
        return x*x + y*y;
    }
    
    template <class T>
    inline void ProtoVector2<T>::normalize(){
        T m = mag();
        x/=m;
        y/=m;
    }
    
    template <class T>
    inline bool ProtoVector2<T>::isNormalized() const{
        return (mag() > .99 && mag() < 1.1);
    }
    
    template <class T>
    inline T ProtoVector2<T>::angle() const{
        return atan2(y,x);
    }
    
 template <class T>
    inline T ProtoVector2<T>::angleBetween(const ProtoVector2<T>& v) const{
        //return atan2(v.y,v.x) - atan2(y,x);
        return acos( (*this).dot(v) / (mag()*v.mag()) );
    }
    
    template <class T>
    inline T ProtoVector2<T>::dot(const ProtoVector2<T>& v) const{
        return x*v.x + y*v.y;
    }
    
    template <class T>
    inline ProtoVector2<T>& ProtoVector2<T>::rotate(T theta){
        T tempX = cos(theta)*x - sin(theta)*y;
        T tempY = sin(theta)*x + cos(theta)*y;
        x = tempX;
        y = tempY;
        return *this;
    }
    
    template <class T>
    inline ProtoVector2<T>& ProtoVector2<T>::reflect(const ProtoVector2<T>& axis){
        axis.normalize();
        return -(*this) + 2*axis * ((*this).dot(axis));
    }
    
    // fills passed in container
    template <class T>
    inline void ProtoVector2<T>::lerp(const ProtoVector2<T>& v, unsigned steps, std::vector<ProtoPoint2<T>>& ptsContainer) const{
        T stepVal = 1.0/steps;
        for (int i=1; i<steps; ++i) {
            T x = x*(1-stepVal*i)+v.x*stepVal*i;
            T y = y*(1-stepVal*i)+v.y*stepVal*i;
            ptsContainer.push_back(ProtoPoint2<T>(x, y)); // record only new (non-terminal) points
        }
    }
    
     // fills passed in container
    template <class T>
    inline void ProtoVector2<T>::lerpVecs(const ProtoVector2<T>& v, unsigned steps, std::vector<ProtoVector2<T>>& vecsContainer) const{
        T stepVal = 1.0/steps;
        for (int i=1; i<steps; ++i) {
            T x = x*(1-stepVal*i)+v.x*stepVal*i;
            T y = y*(1-stepVal*i)+v.y*stepVal*i;
            vecsContainer.push_back(ProtoVector2<T>(x, y)); // record only new (non-terminal) vecs
        }
    }
    
    
    /*****************************************************/
    /*         Non-Member Function implementation        */
    /*****************************************************/
    
    // add vecs
    template <typename T>
    inline ProtoVector2<T> operator+(const ProtoVector2<T>& lhs, const ProtoVector2<T>& rhs){
        return ProtoVector2<T>(lhs)+=rhs;
    }
    
    // subtract vecs
    template <typename T>
    inline ProtoVector2<T> operator-(const ProtoVector2<T>& lhs, const ProtoVector2<T>& rhs){
        return ProtoVector2<T>(lhs)-=rhs;
    }
    
    // mult vecs
    template <typename T>
    inline ProtoVector2<T> operator*(const ProtoVector2<T>& lhs, const ProtoVector2<T>& rhs) {
        return ProtoVector2<T>(lhs)*=rhs;
    }
    
    // div vecs
    template <typename T>
    inline ProtoVector2<T> operator/(const ProtoVector2<T>& lhs, const ProtoVector2<T>& rhs){
        return ProtoVector2<T>(lhs)/=rhs;
    }
    
    // add lhs by sclr
    template <typename T>
    inline ProtoVector2<T> operator+(const ProtoVector2<T>& lhs, T s){
        return ProtoVector2<T>(lhs)+=s;
    }
    
    // add rhs by sclr
    template <typename T>
    inline ProtoVector2<T> operator+(T s, const ProtoVector2<T>& rhs) {
        return ProtoVector2<T>(rhs)+=s;
    }
    
    // sub lhs by sclr
    template <typename T>
    inline ProtoVector2<T> operator-(const ProtoVector2<T>& lhs, T s){
        return ProtoVector2<T>(lhs)-=s;    }
    
    // sub rhs by sclr
    template <typename T>
    inline ProtoVector2<T> operator-(T s, const ProtoVector2<T>& rhs) {
        return ProtoVector2<T>(rhs)-=s;
    }
    
    // mult lhs by sclr
    template <typename T>
    inline ProtoVector2<T> operator*(const ProtoVector2<T>& lhs, T s){
        return ProtoVector2<T>(lhs)*=s;    }
    
    // mult rhs by sclr
    template <typename T>
    inline ProtoVector2<T> operator*(T s, const ProtoVector2<T>& rhs) {
        return ProtoVector2<T>(rhs)*=s;
    }
    
    // div lhs by sclr
    template <typename T>
    inline ProtoVector2<T> operator/(const ProtoVector2<T>& lhs, T s){
        return ProtoVector2<T>(lhs)/=s;
    }
    
    // div rhs by sclr
    template <typename T>
    inline ProtoVector2<T> operator/(T s, const ProtoVector2<T>& rhs) {
        return ProtoVector2<T>(rhs)/=s;
    }
    
    // invert signs
    template <typename T>
    inline ProtoVector2<T> operator-(const ProtoVector2<T>& rhs){
        return ProtoVector2<T>(rhs)*=-1;
    }
    
    // vec magnitude
    template <typename T>
    inline T mag(const ProtoVector2<T>& v){
        return sqrt(v.x*v.x + v.y*v.y);
    }
    
    // angle between vecs
    template <typename T>
    inline T angleBetween(const ProtoVector2<T>& lhs, const ProtoVector2<T>& rhs){
        return atan2(rhs.y-lhs.y, rhs.x-lhs.x);
    }
    
    
    // vec dot product
    template <typename T>
    inline T dot(const ProtoVector2<T>& lhs, const ProtoVector2<T>& rhs){
        return lhs.x*rhs.x + lhs.y*rhs.y;
    }
    
    // outstream opp
    template <class T>
    inline std::ostream& operator<<(std::ostream& out, const ProtoVector2<T>& v){
        out << v.x << ", " << v.y;
        return out;
    }
    
    
    // Type name convenience macros
#define ProtoVector2f ProtoVector2<float>
#define ProtoVector2d ProtoVector2<double>
#define ProtoVec2f ProtoVector2<float>
#define ProtoVec2d ProtoVector2<double>
#define Vec2 ProtoVector2<float> // common use
#define Vec2f ProtoVector2<float>
#define Vec2d ProtoVector2<double>
    
    }  // END ijg namespace
    
#endif // PROTO_VECTOR2_H
