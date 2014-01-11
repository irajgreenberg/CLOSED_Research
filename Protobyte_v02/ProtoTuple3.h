/*!  \brief  ProtoTuple3.h: tuple class with elem0, elem1, elem2 fields
 ProtoTuple3.h
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
 This class is templated to allow for varied single collection types
 This class is part of the group common (update)
 \sa NO LINK
 */

#ifndef PROTO_TUPLE3_H
#define PROTO_TUPLE3_H

#include <iostream>
#include "ProtoVector3.h"

namespace ijg {

    template <class T, class T2 = T, class T3 = T>
    class ProtoTuple3 {
    public:
        T elem0, elem1, elem2;
        // T elems[3];

        ProtoTuple3(T elem0 = 0, T elem1 = 0, T elem2 = 0) :
        elem0(elem0), elem1(elem1), elem2(elem2) {

        }

        // std::ostream& operator<<(std::ostream& out, const ProtoTuple3<T>& tuple3);

    };





    template<typename T>
    std::ostream& operator<<(std::ostream& out, const ProtoTuple3<T>& tuple3) {
        out << tuple3.elem0 << ", " << tuple3.elem1 << ", " << tuple3.elem2;
        return out;
    }
        
    // Type name convenience macros
    #define ProtoTuple3i ProtoTuple3<int>
    #define ProtoTuple3f ProtoTuple3<float>
    #define ProtoTuple3d ProtoTuple3<double>
    #define ProtoTuple3v3f ProtoTuple3<ProtoVector3f>
    #define ProtoTuple3b ProtoTuple3<unsigned char>
            
    #define Tup3i ProtoTuple3<int>
    #define Tup3f ProtoTuple3<float>
    #define Tup3d ProtoTuple3<double>
            
    #define Tup3v2f ProtoTuple3<Vec2f>
    #define Tup3v3f ProtoTuple3<Vec3f>


}

#endif // PROTO_TUPLE3_H
