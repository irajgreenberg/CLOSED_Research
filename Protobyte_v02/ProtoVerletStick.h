/*! \
 * File:   VerletStick.h
 * Author: Ira Greenberg
 *
 * Created on June 5, 2013, 12:39 PM
 * Copyright (c) 2013 Ira Greenberg. All rights reserved.
 */

#ifndef VERLETSTICK_H
#define	VERLETSTICK_H

#include "VerletBall.h"
#include "GraphicsCore.h"
#include "Tuple2.h"

namespace proto {

    class VerletStick {
    private:
        VerletBall b1, b2;
        VerletBall* b1_ptr;
        VerletBall* b2_ptr;
        float tension;
        Vector3 vecOrig;
        float len;
        Tuple2f elasticity;

    public:

        // constructors
        VerletStick();
        VerletStick(VerletBall* b1_ptr, VerletBall* b2_ptr, float tension, Tuple2f elasticity = Tuple2f(.5, .5));
        VerletStick(VerletBall& b1, VerletBall& b2, float tension);

        // copy constructor
        //        VerletStick(const VerletStick& vs);

        void constrainLen();
        void printFields();
        VerletBall* getBall1() const;
        VerletBall* getBall2() const;


        void display();
    };

    inline VerletBall* VerletStick::getBall1() const {
        return b1_ptr;
    }

    inline VerletBall* VerletStick::getBall2() const {
        return b2_ptr;
    }


}

#endif	/* VERLETSTICK_H */

