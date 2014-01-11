/*! \
 * File:   VerletBall.h
 * Author: Ira Greenberg
 *
 * Created on June 5, 2013, 12:39 PM
 * Copyright (c) 2013 Ira Greenberg. All rights reserved.
 */

#ifndef VERLETBALL_H
#define	VERLETBALL_H

#include "Vector3.h"
#include "Math.h"

namespace proto {

    // forward declaration
    class VerletBall;

    // overloaded non-member ops
    Vector3 operator+(const VerletBall& lhs, const VerletBall& rhs);
    Vector3 operator-(const VerletBall& lhs, const VerletBall& rhs);

    class VerletBall {
        //private:
    public:
        Vector3 pos, posOld;

        VerletBall();
        VerletBall(const Vector3& pos);

//        float dist(const VerletBall& b);

        void verlet();

        //getters / setters
        Vector3 getPos() const;
        void setPos(const Vector3& pos);

        // overloaded member ops
        VerletBall& operator+=(const VerletBall& vb);
        VerletBall& operator-=(const VerletBall& vb);


    };


    //getters / setters

    inline Vector3 VerletBall::getPos() const {
        return pos;
    }

    inline void VerletBall::setPos(const Vector3& pos) {
        this->pos = pos;
    }

    inline VerletBall& VerletBall::operator+=(const VerletBall& vb) {
        pos += vb.pos;
        return *this;
    }

    inline VerletBall& VerletBall::operator-=(const VerletBall& vb) {
        pos -= vb.pos;
        return *this;
    }

    // non member ops

    inline Vector3 operator+(const VerletBall& lhs, const VerletBall& rhs) {
        return lhs.getPos() + rhs.getPos();
    }

    inline Vector3 operator-(const VerletBall& lhs, const VerletBall& rhs) {
        return lhs.getPos() - rhs.getPos();
    }
}

#endif	/* VERLETBALL_H */

