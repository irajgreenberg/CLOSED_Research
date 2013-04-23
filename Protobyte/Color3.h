//
//  Color3.h
//  SFML_simple_renderer_06
//
//  Created by Ira on 2/13/13.
//  Copyright (c) 2013 Ira Greenberg. All rights reserved.
//

#ifndef SFML_simple_renderer_06_Color3_h
#define SFML_simple_renderer_06_Color3_h

#include <iostream>

namespace proto {

    template <class T>
    class Color3 {
    private:
        T r, g, b;

    public:

        friend std::ostream& operator<<(std::ostream& output, const Color3<T>& col3) {
            output << "col3.r: " << col3.r << ", col3.g: " <<
                    col3.g << ", col3.b: " << col3.b;
            return output;
        }

        explicit Color3(T r = 0, T g = 0, T b = 0) :
        r(r), g(g), b(b) {
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

        T getR() const {
            return r;
        }

        T getG() const {
            return g;
        }

        T getB() const {
            return b;
        }

    };
    
        // most common usages
    #define Color3f Color3<float>
    #define Color3b Color3<unsigned char>
    #define Color3i Color3<int>
}

#endif /* defined(__SFML_simple_renderer_06__Color3__) */

