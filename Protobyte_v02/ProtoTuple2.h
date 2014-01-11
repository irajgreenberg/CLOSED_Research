/*!  \brief  ProtoTuple2.h: tuple class with elem0, elem1 fields
 ProtoTuple2.h
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

#ifndef PROTO_TUPLE2_H
#define PROTO_TUPLE2_H

#include "ProtoVector3.h"



namespace ijg {

    template <class T>
    class ProtoTuple2 {
    
    public:
        T elem0, elem1;
        T elems[2];

        ProtoTuple2();
        ProtoTuple2(T elem0, T elem1);


        template <typename U> // all instantiations of this template are my friends
        friend std::ostream& operator<<(std::ostream&, const ProtoTuple2<U>&);

    };

    template <class T>
    inline ProtoTuple2<T>::ProtoTuple2() {
    }

    template <class T>
    inline ProtoTuple2<T>::ProtoTuple2(T elem0, T elem1) :
    elem0(elem0), elem1(elem1) {
    }

    template<typename T>
    std::ostream& operator<<(std::ostream& out, const ProtoTuple2<T>& tuple2) {
        out << tuple2.elem0 << ", " << tuple2.elem1;
        return out;
    }


    // Type name convenience macros
    #define ProtoTuple2i ProtoTuple2<int>
    #define ProtoTuple2f ProtoTuple2<float>
    #define ProtoTuple2d ProtoTuple2<double>
    #define ProtoTuple2v3f ProtoTuple2<ProtoVector3f>
    #define ProtoTuple2b ProtoTuple2<unsigned char>

    #define Tup2i ProtoTuple2<int>
    #define Tup2f ProtoTuple2<float>
    #define Tup2d ProtoTuple2<double>

    #define Tup2v2f ProtoTuple2<Vec2f>
    #define Tup2v3f ProtoTuple2<Vec3f>

}
#endif // PROTO_TUPLE2_H
