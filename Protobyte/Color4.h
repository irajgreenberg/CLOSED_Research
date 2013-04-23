//
//  Color4.h
//  SFML_simple_renderer_06
//
//  Created by Ira on 2/13/13.
//  Copyright (c) 2013 Ira Greenberg. All rights reserved.
//

#ifndef SFML_simple_renderer_06_Color4_h
#define SFML_simple_renderer_06_Color4_h


#include <iostream>

namespace proto {

    template <class T>
    class Color4 {
    private:
        T r, g, b, a;

    public:

        friend std::ostream& operator<<(std::ostream& output, const Color4<T>& col4) {
            output << "col4.r: " << col4.r << ", col4.g: " <<
                    col4.g << ", col4.b: " << col4.b << ", col4.a: " << col4.a;
            return output;
        }

        explicit Color4(T r = 0, T g = 0, T b = 0, T a = 0) :
        r(r), g(g), b(b), a(a) {
        }

        void setR(T r) {
            this->r = r;
        }

        void setG(T g) {
            this->g = g;
        }

        void setB(T b) {
            this->b = b;
        }

        void setA(T a) {
            this->a = a;
        }

        T getR() const {
            return r;
        }

        T getG() const {
            return g;
        }

        T getB() const {
            return b;
        }

        T getA() const {
            return a;
        }


    };
    
    #define Color4f Color4<float>
    #define Color4b Color4<unsigned char>
    #define Color4i Color4<int>

}

#endif /* defined(__SFML_simple_renderer_06__Color4__) */

