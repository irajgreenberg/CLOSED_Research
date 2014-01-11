/*!  \brief  ProtoDimension3.h: dimension class with w,h,d fields
 ProtoDimension3.h
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

#ifndef PROTO_DIMENSION3
#define PROTO_DIMENSION3

#include <iostream>

namespace ijg {

    /*****************************************************/
    /*            Non-Member Overloaded Ops              */
    /*****************************************************/
    template <class T> class ProtoDimension3; // forward declaration

    template <class T>
    ProtoDimension3<T> operator+(const ProtoDimension3<T>& lhs, const ProtoDimension3<T>& rhs) {
        return ProtoDimension3<T > (lhs.w + rhs.w, lhs.h + rhs.h, lhs.d + rhs.d);
    }

    template <class T>
    ProtoDimension3<T> operator-(const ProtoDimension3<T>& lhs, const ProtoDimension3<T>& rhs) {
        return ProtoDimension3<T > (lhs.w - rhs.w, lhs.h - rhs.h, lhs.d - rhs.d);
    }

    template <class T>
    ProtoDimension3<T> operator*(const ProtoDimension3<T>& lhs, const ProtoDimension3<T>& rhs) {
        return ProtoDimension3<T > (lhs.w * rhs.w, lhs.h * rhs.h, lhs.d * rhs.d);
    }

    template <class T>
    ProtoDimension3<T> operator/(const ProtoDimension3<T>& lhs, const ProtoDimension3<T>& rhs) {
        return ProtoDimension3<T > (lhs.w / rhs.w, lhs.h / rhs.h, lhs.d / rhs.d);
    }


    // templated Dimension class

    template <class T>
    class ProtoDimension3 {
    private:
        //T w, h, d;

    public:

        T w, h, d;

        template <class U>
        friend std::ostream& operator<<(std::ostream& output, const ProtoDimension3<U>& dim);

        ProtoDimension3();
        ProtoDimension3(T w, T h, T d);

        void setW(T w);
        void setH(T h);
        void setD(T d);
        T getW(T w) const;
        T getH(T h) const;
        T getD(T d) const;

        ProtoDimension3<T>& operator+=(const ProtoDimension3<T>& s);
        ProtoDimension3<T>& operator+=(double f);
        ProtoDimension3<T>& operator-=(const ProtoDimension3<T>& s);
        ProtoDimension3<T>& operator-=(double f);
        ProtoDimension3<T>& operator*=(const ProtoDimension3<T>& s);
        ProtoDimension3<T>& operator*=(double f);
        ProtoDimension3<T>& operator/=(const ProtoDimension3<T>& s);
        ProtoDimension3<T>& operator/=(double f);
        ProtoDimension3<T>& operator++();
        ProtoDimension3<T>& operator++(int);
        ProtoDimension3<T>& operator--();
        ProtoDimension3<T>& operator--(int);

        double operator[](int index);
        bool operator==(const ProtoDimension3<T>& v) const;

    };

    // constructors

    template <class T>
    inline ProtoDimension3<T>::ProtoDimension3() :
    w(1), h(1), d(1) {
    }

    template <class T>
    inline ProtoDimension3<T>::ProtoDimension3(T w, T h, T d) :
    w(w), h(h), d(d) {
    }

    // setters/getters

    template <class T>
    inline T ProtoDimension3<T>::getW(T w) const {
        return w;
    }

    template <class T>
    inline T ProtoDimension3<T>::getH(T h) const {
        return h;
    }

    template <class T>
    inline T ProtoDimension3<T>::getD(T d) const {
        return d;
    }

    template <class T>
    inline void ProtoDimension3<T>::setW(T w) {
        this->w = w;
    }

    template <class T>
    inline void ProtoDimension3<T>::setH(T h) {
        this->h = h;
    }

    template <class T>
    inline void ProtoDimension3<T>::setD(T d) {
        this->d = d;
    }

    // overloaded ops

    template <class T>
    inline ProtoDimension3<T>& ProtoDimension3<T>::operator+=(const ProtoDimension3<T>& s) {
        w += s.w;
        h += s.h;
        d += s.d;
        return *this;
    }

    template <class T>
    inline ProtoDimension3<T>& ProtoDimension3<T>::operator+=(double f) {
        w += f;
        h += f;
        d += f;
        return *this;
    }

    template <class T>
    inline ProtoDimension3<T>& ProtoDimension3<T>::operator-=(const ProtoDimension3<T>& s) {
        w -= s.w;
        h -= s.h;
        d -= s.d;
        return *this;
    }

    template <class T>
    inline ProtoDimension3<T>& ProtoDimension3<T>::operator-=(double f) {
        w -= f;
        h -= f;
        d -= f;
        return *this;
    }

    template <class T>
    inline ProtoDimension3<T>& ProtoDimension3<T>::operator*=(const ProtoDimension3<T>& s) {
        w *= s.w;
        h *= s.h;
        d *= s.d;
        return *this;
    }

    template <class T>
    inline ProtoDimension3<T>& ProtoDimension3<T>::operator*=(double f) {
        w *= f;
        h *= f;
        d *= f;
        return *this;
    }

    template <class T>
    inline ProtoDimension3<T>& ProtoDimension3<T>::operator/=(const ProtoDimension3<T>& s) {
        w /= s.w;
        h /= s.h;
        d /= s.d;
        return *this;
    }

    template <class T>
    inline ProtoDimension3<T>& ProtoDimension3<T>::operator/=(double f) {
        w /= f;
        h /= f;
        d /= f;
        return *this;
    }

    template <class T>
    ProtoDimension3<T>& ProtoDimension3<T>::operator++() {
        ++w;
        ++h;
        ++d;
        return *this;
    }

    template <class T>
    inline ProtoDimension3<T>& ProtoDimension3<T>::operator++(int) {
        w++;
        h++;
        d++;
        return *this;
    }

    template <class T>
    inline ProtoDimension3<T>& ProtoDimension3<T>::operator--() {
        --w;
        --h;
        --d;
        return *this;
    }

    template <class T>
    inline ProtoDimension3<T>& ProtoDimension3<T>::operator--(int) {
        w--;
        h--;
        d--;
        return *this;
    }

    template <class T>
    std::ostream& operator<<(std::ostream& output, const ProtoDimension3<T>& dim) {
        output << "(" << dim.w << ", " << dim.h << ", " << dim.d << ")";
        return output;
    }

    // most common usages
#define ProtoDimension3f ProtoDimension3<float>
#define ProtoDimension3d ProtoDimension3<double>
#define ProtoDimension3i ProtoDimension3<int>
    
#define Dim3f ProtoDimension3<float>
#define Dim3d ProtoDimension3<double>
#define Dim3i ProtoDimension3<int>

}
#endif /* defined(PROTO_DIMENSION3) */
