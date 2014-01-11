/*! \
 * File:   TubeBranch.h
 * Author: Ira Greenberg
 *
 * Created on May 6, 2013, 2:33 PM
 * Copyright (c) 2013 Ira Greenberg. All rights reserved.
 */

#ifndef TUBEBRANCH_H
#define	TUBEBRANCH_H

#include "GraphicsCore.h"
#include "GeomBase.h"
#include "Spline3.h"
#include "Tube.h"
#include "Math.h"

namespace proto {

    class TubeBranch : public GraphicsCore {
    public:

        /*!
         * Default Constructor */
        TubeBranch();

        /*!
         * Constructor */
        TubeBranch(int stemCount);

        /*!
         * Constructor */
        TubeBranch(const Vector3& pos, const Vector3& rot, const Dimension3f& size,
                const Color4f& col4, int stemCount, float trunkRadius, Vector3 stemSizeRatio, int
                trunkControlPtCount = 4, int trunkInterpolatedPtDetail = 2,
                int trunkCrossSectionPointCount = 12, int stemCrossSectionPointCount = 6);


        void display(GeomBase::displayMode mode = GeomBase::VERTEX_ARRAY,
                GeomBase::renderMode render = GeomBase::SURFACE, float pointSize = 3.5f);
        
        /*!
         * set | get prototypes */
        inline void setStems(const std::vector<Tube>& stems);
        inline std::vector<Tube> getStems() const;
        inline void setTrunkRadius(float trunkRadius);
        inline float getTrunkRadius() const;
        inline void setStemSplines(const std::vector<Spline3>& stemSplines);
        inline std::vector<Spline3> getStemSplines() const;
        inline void setTrunk(Tube trunk);
        inline Tube getTrunk() const;
        inline void setTrunkSpline(const Spline3& trunkSpline);
        inline Spline3 getTrunkSpline() const;
        inline void setAreStemsClosed(bool areStemsClosed);
        inline bool isAreStemsClosed() const;
        inline void setIsBranchClosed(bool isBranchClosed);
        inline bool getIsBranchClosed() const;
        inline void setBranchJitter(float branchJitter);
        inline float getBranchJitter() const;
        inline void setStemSplineJitter(const Vector3& stemSplineJitter);
        inline Vector3 getStemSplineJitter() const;
        inline void setTrunkSplineJitter(const Vector3& trunkSplineJitter);
        inline Vector3 getTrunkSplineJitter() const;
        inline void setStemCrossSectionPointCount(int stemCrossSectionPointCount);
        inline int getStemCrossSectionPointCount() const;
        inline void setTrunkCrossSectionPointCount(int trunkCrossSectionPointCount);
        inline int getTrunkCrossSectionPointCount() const;
        inline void setTrunkInterpolatedPtDetail(int trunkInterpolatedPtDetail);
        inline int getTrunkInterpolatedPtDetail() const;
        inline void setTrunkControlPtCount(int trunkControlPtCount);
        inline int getTrunkControlPtCount() const;
        inline void setStemSizeRatio(Vector3 stemSizeRatio);
        inline Vector3 getStemSizeRatio() const;
        inline void setStemCount(int stemCount);
        inline int getStemCount() const;




    private:

        // number of stems
        int stemCount;

        // radius of main trunk, independent of overall size.
        float trunkRadius;

        // Vector 3D quantity for ratio of stem size to branch size
        Vector3 stemSizeRatio;

        // number of control points in branch 
        // trunk (based on Catmull-Rom spline)
        int trunkControlPtCount;

        // number of interpolated points between 
        // control points in branch trunk
        int trunkInterpolatedPtDetail;

        // Number of points in branch trunk cross-section
        int trunkCrossSectionPointCount;

        // Number of points in branch stem cross-section
        int stemCrossSectionPointCount;

        // factor to randomly perturb branch trunk spline points
        Vector3 trunkSplineJitter;

        // factor to randomly perturb branch stems' spline points
        Vector3 stemSplineJitter;

        // factor to randomly perturb branch radii, 
        // implemented through smooth curves (e.g. cos/sine)
        float branchJitter;

        // flag to set branch tube closed
        bool isBranchClosed;

        // flag to set stem tubes closed
        bool areStemsClosed;

        // trunk guts
        Spline3 trunkSpline;
        Tube trunk;

        // stem container guts
        std::vector<Spline3> stemSplines;
        std::vector<Tube> stems;

        void init();

    };

    inline void TubeBranch::setStems(const std::vector<Tube>& stems) {
        this->stems = stems;
        init();
    }

    inline std::vector<Tube> TubeBranch::getStems() const {
        return stems;
    }

    inline void TubeBranch::setTrunkRadius(float trunkRadius) {
        this->trunkRadius = trunkRadius;
        init();
    }

    inline float TubeBranch::getTrunkRadius() const {
        return trunkRadius;
    }

    inline void TubeBranch::setStemSplines(const std::vector<Spline3>& stemSplines) {
        this->stemSplines = stemSplines;
        init();
    }

    inline std::vector<Spline3> TubeBranch::getStemSplines() const {
        return stemSplines;
    }

    inline void TubeBranch::setTrunk(Tube trunk) {
        this->trunk = trunk;
        init();
    }

    inline Tube TubeBranch::getTrunk() const {
        return trunk;
    }

    inline void TubeBranch::setTrunkSpline(const Spline3& trunkSpline) {
        this->trunkSpline = trunkSpline;
        init();
    }

    inline Spline3 TubeBranch::getTrunkSpline() const {
        return trunkSpline;
    }

    inline void TubeBranch::setAreStemsClosed(bool areStemsClosed) {
        this->areStemsClosed = areStemsClosed;
        init();
    }

    inline bool TubeBranch::isAreStemsClosed() const {
        return areStemsClosed;
    }

    inline void TubeBranch::setIsBranchClosed(bool isBranchClosed) {
        this->isBranchClosed = isBranchClosed;
        init();
    }

    inline bool TubeBranch::getIsBranchClosed() const {
        return isBranchClosed;
    }

    inline void TubeBranch::setBranchJitter(float branchJitter) {
        this->branchJitter = branchJitter;
        init();
    }

    inline float TubeBranch::getBranchJitter() const {
        return branchJitter;
    }

    inline void TubeBranch::setStemSplineJitter(const Vector3& stemSplineJitter) {
        this->stemSplineJitter = stemSplineJitter;
        init();
    }

    inline Vector3 TubeBranch::getStemSplineJitter() const {
        return stemSplineJitter;
    }

    inline void TubeBranch::setTrunkSplineJitter(const Vector3& trunkSplineJitter) {
        this->trunkSplineJitter = trunkSplineJitter;
        init();
    }

    inline Vector3 TubeBranch::getTrunkSplineJitter() const {
        return trunkSplineJitter;
    }

    inline void TubeBranch::setStemCrossSectionPointCount(int stemCrossSectionPointCount) {
        this->stemCrossSectionPointCount = stemCrossSectionPointCount;
        init();
    }

    inline int TubeBranch::getStemCrossSectionPointCount() const {
        return stemCrossSectionPointCount;
    }

    inline void TubeBranch::setTrunkCrossSectionPointCount(int trunkCrossSectionPointCount) {
        this->trunkCrossSectionPointCount = trunkCrossSectionPointCount;
        init();
    }

    inline int TubeBranch::getTrunkCrossSectionPointCount() const {
        return trunkCrossSectionPointCount;
    }

    inline void TubeBranch::setTrunkInterpolatedPtDetail(int trunkInterpolatedPtDetail) {
        this->trunkInterpolatedPtDetail = trunkInterpolatedPtDetail;
        init();
    }

    inline int TubeBranch::getTrunkInterpolatedPtDetail() const {
        return trunkInterpolatedPtDetail;
    }

    inline void TubeBranch::setTrunkControlPtCount(int trunkControlPtCount) {
        this->trunkControlPtCount = trunkControlPtCount;
        init();
    }

    inline int TubeBranch::getTrunkControlPtCount() const {
        return trunkControlPtCount;
    }

    inline void TubeBranch::setStemSizeRatio(Vector3 stemSizeRatio) {
        this->stemSizeRatio = stemSizeRatio;
        init();
    }

    inline Vector3 TubeBranch::getStemSizeRatio() const {
        return stemSizeRatio;
    }

    inline void TubeBranch::setStemCount(int stemCount) {
        this->stemCount = stemCount;
        init();
    }

    inline int TubeBranch::getStemCount() const {
        return stemCount;
    }

}

#endif	/* TUBEBRANCH_H */

