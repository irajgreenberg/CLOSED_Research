/*! \
 * File:   EllipticalWing.h
 * Author: Ira Greenberg
 *
 * Created on July 8, 2013, 11:28 AM
 * Copyright (c) 2013 Ira Greenberg. All rights reserved.
 */

#ifndef EllipticalWing_H
#define	EllipticalWing_H

#include "GeomBase.h"
#include "VerletBall.h"
#include "VerletStick.h"

namespace proto {

    class EllipticalWing : public GeomBase {
    public:
        friend std::ostream& operator<<(std::ostream& out, const EllipticalWing& wing);

        /*!
         * Default Constructor */
        EllipticalWing();

        /*!
         * Constructor */
        EllipticalWing(int edgePointCount, int ringCount, float coreRadiusRatio);

        /*!
         * Constructor */
        EllipticalWing(const Vector3& pos, const Vector3& rot, const Dimension3f& size, const Color4f& col4, int edgePointCount, int ringCount, float coreRadiusRatio);
        
        
        /*!
         * Constructor */
        EllipticalWing(int edgePointCount, int ringCount, float coreRadiusRatio, float startAnglele, float stopAnglele, bool isClosed = false);

        /*!
         * Constructor */
        EllipticalWing(const Vector3& pos, const Vector3& rot, const Dimension3f& size, const Color4f& col4, int edgePointCount, int ringCount, float coreRadiusRatio, float startAnglele, float stopAnglele, bool isClosed = false);


        /*! Required implementations in GeomBase derived classes
         */
        /*! overrides base class virtual functions
         */
        void calcVerts();

        /*! overrides base class virtual functions
         */
        void calcInds();


        /*! accessors/mutators declarations
         */
        void setEdgePointCount(int edgePointCount);
        int getEdgePointCount() const;

        void setCoreRadiusRatio(float coreRadiusRatio);
        float getCoreRadiusRatio() const;

        void setRingCount(int ringCount);
        int getRingCount() const;

        void setIsClosed(bool isClosed);
        bool isIsClosed() const;
        
        void setStopAngle(float stopAngle);
        float getStopAngle() const;
        
        void setStartAngle(float startAngle);
        float getStartAngle() const;

    private:
        int edgePointCount;
        int ringCount;
        float coreRadiusRatio;
        float startAngle, stopAngle;
        bool isClosed;

    };

    // inline accessors/mutators

    inline void EllipticalWing::setEdgePointCount(int edgePointCount) {
        this->edgePointCount = edgePointCount;
    }

    inline int EllipticalWing::getEdgePointCount() const {
        return edgePointCount;
    }

    inline void EllipticalWing::setRingCount(int ringCount) {
        this->ringCount = ringCount;
    }

    inline int EllipticalWing::getRingCount() const {
        return ringCount;
    }

    inline void EllipticalWing::setCoreRadiusRatio(float coreRadiusRatio) {
        this->coreRadiusRatio = coreRadiusRatio;
    }

    inline float EllipticalWing::getCoreRadiusRatio() const {
        return coreRadiusRatio;
    }

    inline void EllipticalWing::setIsClosed(bool isClosed) {
        this->isClosed = isClosed;
    }

    inline bool EllipticalWing::isIsClosed() const {
        return isClosed;
    }

    inline void EllipticalWing::setStopAngle(float stopAngle) {
        this->stopAngle = stopAngle;
    }

    inline float EllipticalWing::getStopAngle() const {
        return stopAngle;
    }

    inline void EllipticalWing::setStartAngle(float startAngle) {
        this->startAngle = startAngle;
    }

    inline float EllipticalWing::getStartAngle() const {
        return startAngle;
    }

}

#endif	/* WING_H */

