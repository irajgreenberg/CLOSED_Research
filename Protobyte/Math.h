/* 
 * File:   Math.h
 * Author: 33993405
 *
 * Created on March 16, 2013, 2:17 PM
 */

#ifndef MATH_H
#define	MATH_H

#include <ctime>

namespace proto {

    class Math {
        
    private:
        // disallow instantiation/assignment
        Math() {}

    public:
        
        // all static functions
        
        // from http://stackoverflow.com/a/686373
        static float random(float max = 1.0) {
            return (float)rand()/((float)RAND_MAX/max);
        }

        // from http://stackoverflow.com/a/686373
        static float random(float min, float max) {
            return min + (float)rand()/((float)RAND_MAX/(max-min));

        }
    };
}

#endif	/* MATH_H */

