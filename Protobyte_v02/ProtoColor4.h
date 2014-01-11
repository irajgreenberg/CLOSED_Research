/*!  \brief  ProtoColor4.h: color class with r,g,b,a fields
 ProtoColor4.h
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

#ifndef PROTO_COLOR4_h
#define PROTO_COLOR4_h

#include <iostream>

namespace ijg {

    template <class T>
    class ProtoColor4 {
    private:
        T r, g, b, a;

    public:

        template <class U>
        friend std::ostream& operator<<(std::ostream& output, const ProtoColor4<U>& col4);

        ProtoColor4();
        ProtoColor4(T r, T g, T b, T a);

        void setR(T r);
        void setG(T g);
        void setB(T b);
        void setA(T a);

        T getR() const;
        T getG() const;
        T getB() const;
        T getA() const;
        

    };

    // constructors

    template <class T>
    inline ProtoColor4<T>::ProtoColor4() :
    r(0), g(0), b(0), a(1) {
    }

    template <class T>
    inline ProtoColor4<T>::ProtoColor4(T r, T g, T b, T a) :
    r(r), g(g), b(b), a(a) {
    }

    // getters/setters

    template <class T>
    inline void ProtoColor4<T>::setR(T r) {
        this->r = r;
    }

    template <class T>
    inline void ProtoColor4<T>::setG(T g) {
        this->g = g;
    }

    template <class T>
    inline void ProtoColor4<T>::setB(T b) {
        this->b = b;
    }
    
    template <class T>
    inline void ProtoColor4<T>::setA(T a) {
        this->a = a;
    }

    template <class T>
    inline T ProtoColor4<T>::getR() const {
        return r;
    }

    template <class T>
    inline T ProtoColor4<T>::getG() const {
        return g;
    }

    template <class T>
    inline T ProtoColor4<T>::getB() const {
        return b;
    }
    
     template <class T>
    inline T ProtoColor4<T>::getA() const {
        return a;
    }

    // overload

    template <class T>
    std::ostream& operator<<(std::ostream& output, const ProtoColor4<T>& col4) {
        output << "col4.r: " << col4.r << ", col4.g: " <<
                col4.g << ", col4.b: " << col4.b <<
                ", col4.a: " << col4.a;
        return output;
    }


    // most common usages
#define ProtoColor4f ProtoColor4<float>
#define ProtoColor4b ProtoColor4<unsigned char>
#define ProtoColor4i ProtoColor4<int>
        
#define Col4f ProtoColor4<float>
#define Col4b ProtoColor4<unsigned char>
#define Col4i ProtoColor4<int>
}
#endif /* defined(PROTO_COLOR4_h) */

