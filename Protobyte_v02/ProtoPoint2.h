/*!  \brief  ProtoPoint2.h: Templated 2d point class
 ProtoPoint2.h
 Protobyte Library v02
 
 Created by Ira on 8/12/13.
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

#ifndef PROTO_POINT2_h
#define PROTO_POINT2_h

#include <iostream>
#include <cassert>

namespace ijg {
    
    // forward declaration for non-member ops
    template <class T> class ProtoPoint2;
    
    // class declaration
    template <class T>
    class ProtoPoint2 {
        
    public:
        
        // overloaded << operator declared as friend function for access to private data
        template <typename U>
        friend std::ostream& operator<<(std::ostream& output, const ProtoPoint2<U>& v);
        
        // fields (public for major convenience)
        T x, y;
        
        /*****************************************************/
        /*                    Constructors                  */
        /*****************************************************/
        ProtoPoint2(T x=0, T y=0);
        
        /*****************************************************/
        /*              Member Overloaded Ops                */
        /*****************************************************/
        ProtoPoint2<T>& operator()(T x, T y);
        T operator[](unsigned index);
        const T operator[](unsigned index) const;
        bool operator==(const ProtoPoint2<T>& p) const;
        bool operator!=(const ProtoPoint2<T>& p) const;
        
        
    }; // END ProtoPoint2 class declaration
    
    
    // cstr
    template <class T>
    inline ProtoPoint2<T>::ProtoPoint2(T x, T y):
    x(x), y(y){
    }
    
    
    // member overloaded ops
    template <class T>
    inline ProtoPoint2<T>& ProtoPoint2<T>::operator()(T x, T y) {
        this->x = x;
        this->y = y;
        return *this;
    }
    
    template <class T>
    inline T ProtoPoint2<T>::operator[](unsigned index){
        assert( index >= 0 && index <= 1 );
        return *(&x+index);
    }
    
    template <class T>
    inline const T ProtoPoint2<T>::operator[](unsigned index) const{
        assert( index >= 0 && index <= 1 );
        return *(&x+index);
    }
    
    
    template <class T>
    inline bool ProtoPoint2<T>::operator==(const ProtoPoint2<T>& v) const{
        return (x==v.x && y==v.y);
    }
    
    template <class T>
    inline bool ProtoPoint2<T>::operator!=(const ProtoPoint2<T>& v) const{
        return (x!=v.x || y!=v.y);
    }
    
    // outstream opp
    template <class T>
    inline std::ostream& operator<<(std::ostream& out, const ProtoPoint2<T>& v){
        out << v.x << ", " << v.y;
        return out;
    }
    
    
    // Type name convenience macros
#define ProtoPoint2f ProtoPoint2<float>
#define ProtoPoint2d ProtoPoint2<double>
#define ProtoPoint2f ProtoPoint2<float>
#define ProtoPoint2d ProtoPoint2<double>
#define Point2 ProtoPoint2<float> // common use
#define Point2f ProtoPoint2<float>
#define Point2d ProtoPoint2<double>
    
    }  // END ijg namespace
    
#endif // PROTO_POINT2_h
