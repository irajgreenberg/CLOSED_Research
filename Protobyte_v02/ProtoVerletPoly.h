/*! \
 * File:   VerletPoly.h
 * Author: Ira Greenberg
 *
 * Created on June 14, 2013, 7:17 PM
 * Copyright (c) 2013 Ira Greenberg. All rights reserved.
 */

#ifndef VERLETPOLY_H
#define	VERLETPOLY_H

#include  "GraphicsCore.h"
#include "VerletBall.h"
#include "VerletStick.h"

namespace proto {

    class VerletPoly {
    public:
        /*!
         * Default Constructor */
        VerletPoly();
        
        VerletPoly(int sides, float radius);
  
        void display();
        
        void run();

    private:
        int sides;
        float radius;
        std::vector<VerletBall*> balls;
        std::vector<VerletStick> sticks;
    };

}

#endif	/* VERLETPOLY_H */

