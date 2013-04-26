/*!  \brief Tuple3: Templated Tuple
 Tuple3.h
 Protobyte_iig001
 
 
 Created by Ira on 9/5/12.
 Copyright (c) 2012 __MyCompanyName__. All rights reserved.
 
 \ingroup common
 This class is templated to allow for varied single collection types
 This class is part of the group common (update)
 \sa NO LINK
 */

#ifndef Protobyte_iig001_Tuple3_h
#define Protobyte_iig001_Tuple3_h

#include <iostream>

namespace proto {

    template <class T>
    class Tuple3 {
    public:
        T elem0, elem1, elem2;
        T elems[3];

        Tuple3(T elem0 = 0, T elem1 = 0, T elem2 = 0) :
        elem0(elem0), elem1(elem1), elem2(elem2) {

        }

       // std::ostream& operator<<(std::ostream& out, const Tuple3<T>& tuple3);

    };

#define Tuple3f Tuple3<float>
#define Tuple3i Tuple3<int>
#define Tuple3b Tuple3<unsigned char>

    template<typename T>
    std::ostream& operator<<(std::ostream& out, const Tuple3<T>& tuple3) {
        out << tuple3.elem0 << ", " << tuple3.elem1 << ", " << tuple3.elem2;
        return out;
    }


}

#endif
