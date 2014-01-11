/*! \
 * File:   VerletBase.h
 * Author: Ira Greenberg
 *
 * Abstract Base class for Verlet System
 * Created on June 27, 2013, 5:29 PM
 * Copyright (c) 2013 Ira Greenberg. All rights reserved.
 */

#ifndef VERLETBASE_H
#define	VERLETBASE_H

#include "VerletBall.h"
#include "VerletStick.h"
#include "GraphicsCore.h"

namespace proto {

    class VerletBase : public GraphicsCore {
    public:

//        friend std::ostream& operator<<(std::ostream& out, const VerletBase& orig);

        /*!
         * Default Constructor */
        VerletBase();

        VerletBase(const Vector3& pos, const Vector3& rot, const Dimension3f& size, const Color4f& col4, int segments, int crossSectionDetail, float tension);

        // dstr
        virtual ~VerletBase();

        // copy cstr
        VerletBase(const VerletBase& orig);

        // assignment op
        VerletBase& operator=(const VerletBase& orig);


        void display();
        void run();

        std::vector<VerletStick> getSticks() const;
        void setBalls(std::vector<VerletBall*> balls);
        void setTension(float tension);
        float getTension() const;
        void setCrossSectionDetail(int crossSectionDetail);
        int getCrossSectionDetail() const;
        void setSegments(int segments);
        int getSegments() const;

    protected:
        int segments;
        int crossSectionDetail;
        float tension;
        std::vector<VerletBall*> balls;
        std::vector<VerletStick> sticks;

        // for anchored exoskeleton box
        std::vector<VerletBall*> exoBalls;

        // Pure Virtual - Must be overridden
        virtual void init() = 0;
        virtual void calcBalls() = 0;
        virtual void calcSticks() = 0;

        float theta;

    };

//    std::ostream& operator<<(std::ostream& out, const VerletBase& orig) {
//        out << orig.segments << ", " <<
//                orig.crossSectionDetail << ", " <<
//                orig.tension;
//
//        return out;
//    }


    // sets/gets

    inline std::vector<VerletStick> VerletBase::getSticks() const {
        return sticks;
    }

    inline void VerletBase::setBalls(std::vector<VerletBall*> balls) {
        this->balls = balls;
    }

    inline void VerletBase::setTension(float tension) {
        this->tension = tension;
    }

    inline float VerletBase::getTension() const {
        return tension;
    }

    inline void VerletBase::setCrossSectionDetail(int crossSectionDetail) {
        this->crossSectionDetail = crossSectionDetail;
    }

    inline int VerletBase::getCrossSectionDetail() const {
        return crossSectionDetail;
    }

    inline void VerletBase::setSegments(int segments) {
        this->segments = segments;
    }

    inline int VerletBase::getSegments() const {
        return segments;
    }

}

#endif	/* VERLETBASE_H */

