/*!  \brief  ProtMath.h: Protobyte Library math constants and random functions
 - all static
 ProtoMath.h
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

#ifndef PROTO_MATH_H
#define	PROTO_MATH_H

#include <ctime>
#include <cstdlib>

namespace ijg {
    
    
    class ProtoMath {
    private:
        // disallow instantiation/assignment
        ProtoMath() {
        }
        
    public:
        
        // all static functions
        
        // from http://stackoverflow.com/a/686373
        
        // eventually replace these with Mersenne twister algorithm
        static float random(float max = 1.0);
        
        // from http://stackoverflow.com/a/686373
        static float random(float min, float max);
        
        // static fields - initialized in .cpp
        static const double PI;
        static const double HALF_PI;
        static const double H_PI; // alt name to HALF_PI
        static const double QUARTER_PI;
        static const double Q_PI; // alt name to QUARTER_PI
        static const double TWO_PI;
        static const double DOUBLE_PI; // alt name to TWO_PI
        static const double THREE_PI;
        static const double TRI_PI; // alt name to THREE_PI
    };
    
    inline float ProtoMath::random(float max) {
        return (float) rand() / ((float) RAND_MAX / max);
    }
    
    // from http://stackoverflow.com/a/686373
    
    inline float ProtoMath::random(float min, float max) {
        return min + (float) rand() / ((float) RAND_MAX / (max - min));
        
    }

}

#endif	// PROTO_MATH_H

