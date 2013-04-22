//
//  Dimension3.h
//  SFML_simple_renderer_06
//
//  Created by Ira on 2/13/13.
//  Copyright (c) 2013 Ira Greenberg. All rights reserved.
//

#ifndef __SFML_simple_renderer_06__Dimension3__
#define __SFML_simple_renderer_06__Dimension3__

#include <iostream>

namespace proto {

    /*****************************************************/
    /*            Non-Member Overloaded Ops              */
    /*****************************************************/
    template <class T> class Dimension3; // forward declaration

    template <class T>
    Dimension3<T> operator+(const Dimension3<T>& lhs, const Dimension3<T>& rhs) {
        return Dimension3<T > (lhs.w + rhs.w, lhs.h + rhs.h, lhs.d + rhs.d);
    }

    template <class T>
    Dimension3<T> operator-(const Dimension3<T>& lhs, const Dimension3<T>& rhs) {
        return Dimension3<T > (lhs.w - rhs.w, lhs.h - rhs.h, lhs.d - rhs.d);
    }

    template <class T>
    Dimension3<T> operator*(const Dimension3<T>& lhs, const Dimension3<T>& rhs) {
        return Dimension3<T > (lhs.w * rhs.w, lhs.h * rhs.h, lhs.d * rhs.d);
    }

    template <class T>
    Dimension3<T> operator/(const Dimension3<T>& lhs, const Dimension3<T>& rhs) {
        return Dimension3<T > (lhs.w / rhs.w, lhs.h / rhs.h, lhs.d / rhs.d);
    }


    // templated Dimension class

    template <class T>
    class Dimension3 {
    private:
        //T w, h, d;

    public:

        T w, h, d;

        friend std::ostream& operator<<(std::ostream& output, const Dimension3<T>& dim) {
            output << "(" << dim.w << ", " << dim.h << ", " << dim.d << ")";
            return output;
        }

        explicit Dimension3(T w = 1, T h = 1, T d = 1) :
        w(w), h(h), d(d) {
        }

        void setW(T w) {
            this->w = w;
        }

        void setH(T h) {
            this->h = h;
        }

        void setD(T d) {
            this->d = d;
        }

        const T getW(T w) const {
            return w;
        }

        const T getH(T h) const {
            return h;
        }

        const T getD(T d) const {
            return d;
        }

        Dimension3<T>& operator+=(const Dimension3<T>& s) {
            w += s.w;
            h += s.h;
            d += s.d;
            return *this;
        }

        Dimension3<T>& operator+=(double f) {
            w += f;
            h += f;
            d += f;
            return *this;
        }

        Dimension3<T>& operator-=(const Dimension3<T>& s) {
            w -= s.w;
            h -= s.h;
            d -= s.d;
            return *this;
        }

        Dimension3<T>& operator-=(double f) {
            w -= f;
            h -= f;
            d -= f;
            return *this;
        }

        Dimension3<T>& operator*=(const Dimension3<T>& s) {
            w *= s.w;
            h *= s.h;
            d *= s.d;
            return *this;
        }

        Dimension3<T>& operator*=(double f) {
            w *= f;
            h *= f;
            d *= f;
            return *this;
        }

        Dimension3<T>& operator/=(const Dimension3<T>& s) {
            w /= s.w;
            h /= s.h;
            d /= s.d;
            return *this;
        }

        Dimension3<T>& operator/=(double f) {
            w /= f;
            h /= f;
            d /= f;
            return *this;
        }

        Dimension3<T>& operator++() {
            ++w;
            ++h;
            ++d;
            return *this;
        }

        Dimension3<T>& operator++(int) {
            w++;
            h++;
            d++;
            return *this;
        }

        Dimension3<T>& operator--() {
            --w;
            --h;
            --d;
            return *this;
        }

        Dimension3<T>& operator--(int) {
            w--;
            h--;
            d--;
            return *this;
        }

        double operator[](int index);
        bool operator==(const Dimension3<T>& v) const;

    };
    
    // most common usages
    #define Dimension3f Dimension3<float>
    #define Dimension3i Dimension3<int>

}
#endif /* defined(__SFML_simple_renderer_06__Dimension3__) */
