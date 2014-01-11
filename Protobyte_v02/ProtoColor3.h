/*!  \brief  ProtoColor3.h: color class with r,g,b fields
 ProtoColor3.h
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

#ifndef PROTO_COLOR3_H
#define PROTO_COLOR3_H

#include <iostream>

namespace ijg {

    template <class T>
    class ProtoColor3 {
    private:
        T r, g, b;

    public:

        template <class U>
        friend std::ostream& operator<<(std::ostream& output, const ProtoColor3<U>& col3);

        ProtoColor3();
        ProtoColor3(T r, T g, T b);

        void setR(T r);
        void setG(T g);
        void setB(T b);

        T getR() const;
        T getG() const;
        T getB() const;

    };

    // constructors

    template <class T>
    inline ProtoColor3<T>::Color3() :
    r(0), g(0), b(0) {
    }

    template <class T>
    inline ProtoColor3<T>::ProtoColor3(T r, T g, T b) :
    r(r), g(g), b(b) {
    }

    // getters/setters

    template <class T>
    inline void ProtoColor3<T>::setR(T r) {
        this->r = r;
    }

    template <class T>
    inline void ProtoColor3<T>::setG(T g) {
        this->g = g;
    }

    template <class T>
    inline void ProtoColor3<T>::setB(T b) {
        this->b = b;
    }

    template <class T>
    inline T ProtoColor3<T>::getR() const {
        return r;
    }

    template <class T>
    inline T ProtoColor3<T>::getG() const {
        return g;
    }

    template <class T>
    inline T ProtoColor3<T>::getB() const {
        return b;
    }

    // overload

    template <class T>
    friend std::ostream& operator<<(std::ostream& output, const ProtoColor3<T>& col3) {
        output << "col3.r: " << col3.r << ", col3.g: " <<
                col3.g << ", col3.b: " << col3.b;
        return output;
    }


    // most common usages
    #define ProtoColor3f ProtoColor3<float>
    #define ProtoColor3b ProtoColor3<unsigned char>
    #define ProtoColor3i ProtoColor3<int>
            
    #define Col3f ProtoColor3<float>
    #define Col3b ProtoColor3<unsigned char>
    #define Col3i ProtoColor3<int>
}

#endif /* defined(PROTO_COLOR3_H) */

