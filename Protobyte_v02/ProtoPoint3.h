/*!  \brief  ProtoPoint3.h: Templated 3d point class
 ProtoPoint3.h
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

#ifndef PROTO_POINT3_h
#define PROTO_POINT3_h

#include <iostream>
#include <cassert>

namespace ijg {
    
    // forward declaration for non-member ops
    template <class T> class ProtoPoint3;
    
    // class declaration
    template <class T>
    class ProtoPoint3 {
        
    public:
        
        // overloaded << operator declared as friend function for access to private data
        template <typename U>
        friend std::ostream& operator<<(std::ostream& output, const ProtoPoint3<U>& v);
        
        // fields (public for major convenience)
        T x, y, z;
        
        /*****************************************************/
        /*                    Constructors                  */
        /*****************************************************/
        ProtoPoint3(T x=0, T y=0, T z=0);
        
        /*****************************************************/
        /*              Member Overloaded Ops                */
        /*****************************************************/
        ProtoPoint3<T>& operator()(T x, T y, T z);
        T operator[](unsigned index);
        const T operator[](unsigned index) const;
        bool operator==(const ProtoPoint3<T>& p) const;
        bool operator!=(const ProtoPoint3<T>& p) const;
        
        
    }; // END ProtoPoint3 class declaration
    
    
    // cstr
    template <class T>
    inline ProtoPoint3<T>::ProtoPoint3(T x, T y, T z):
    x(x), y(y), z(z){
    }
    
    
    // member overloaded ops
    template <class T>
    inline ProtoPoint3<T>& ProtoPoint3<T>::operator()(T x, T y, T z) {
        this->x = x;
        this->y = y;
        this->z = z;
        return *this;
    }
    
    template <class T>
    inline T ProtoPoint3<T>::operator[](unsigned index){
        assert( index >= 0 && index <= 2 );
        return *(&x+index);
    }
    
    template <class T>
    inline const T ProtoPoint3<T>::operator[](unsigned index) const{
        assert( index >= 0 && index <= 2 );
        return *(&x+index);
    }
    
    
    template <class T>
    inline bool ProtoPoint3<T>::operator==(const ProtoPoint3<T>& v) const{
        return (x==v.x && y==v.y && z==v.z);
    }
    
    template <class T>
    inline bool ProtoPoint3<T>::operator!=(const ProtoPoint3<T>& v) const{
        return (x!=v.x || y!=v.y || z!=v.z);
    }
    
    // outstream opp
    template <class T>
    inline std::ostream& operator<<(std::ostream& out, const ProtoPoint3<T>& v){
        out << v.x << ", " << v.y << ", " << v.z;
        return out;
    }
    
    
    // Type name convenience macros
#define ProtoPoint3f ProtoPoint3<float>
#define ProtoPoint3d ProtoPoint3<double>
#define ProtoPoint3f ProtoPoint3<float>
#define ProtoPoint3d ProtoPoint3<double>
#define Point3 ProtoPoint3<float> // common use
#define Point3f ProtoPoint3<float>
#define Point3d ProtoPoint3<double>
    
    }  // END ijg namespace
    
#endif // PROTO_POINT3_h
