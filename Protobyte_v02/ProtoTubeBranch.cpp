/*! File:   TubeBranch.cpp
 * Author: Ira Greenberg
 *
 * Created on May 6, 2013, 2:33 PM
 * Copyright (c) 2013 Ira Greenberg. All rights reserved.
 */

#include "TubeBranch.h"
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace proto;

/*!
 * Default Constructor */
TubeBranch::TubeBranch() {
}

/*!
 * Constructor */
TubeBranch::TubeBranch(int stemCount) :
GraphicsCore(Vector3(0, 0, 0), Vector3(0, 0, 0), Dimension3f(1, 1, 1), Color4f(.4, .3, .8, 1.0)), stemCount(stemCount), trunkRadius(.095), stemSizeRatio(Vector3(.05, .05, .05)), trunkControlPtCount(24), trunkInterpolatedPtDetail(20), trunkCrossSectionPointCount(4), stemCrossSectionPointCount(20) {
    init();
}

/*!
 * Constructor */
TubeBranch::TubeBranch(const Vector3& pos, const Vector3& rot, const Dimension3f& size,
        const Color4f& col4, int stemCount, float trunkRadius, Vector3 stemSizeRatio, int
        trunkControlPtCount, int trunkInterpolatedPtDetail,
        int trunkCrossSectionPointCount, int stemCrossSectionPointCount) :
GraphicsCore(pos, rot, size, col4), stemCount(stemCount), trunkRadius(trunkRadius), stemSizeRatio(stemSizeRatio),
trunkControlPtCount(trunkControlPtCount), trunkInterpolatedPtDetail(trunkInterpolatedPtDetail), trunkCrossSectionPointCount(trunkCrossSectionPointCount),
stemCrossSectionPointCount(stemCrossSectionPointCount) {
    init();
}

void TubeBranch::init() {
    float smoothness = .5;
    std::vector<Vector3> cps;
    cps.resize(trunkControlPtCount);
    float x = 0, y = 0, z = 0;
    float t = 0;
    float cpSegHt = 1.0 / (cps.size() - 1);
    for (int i = 0; i < trunkControlPtCount; i++) {
        x = Math::random(-3, 3);
        y = Math::random(-3, 3);
        z = Math::random(-3, 3);

        cps.at(i) = Vector3(x, y, z);
        // std::cout << "cps.at(i)= " << cps.at(i) << std::endl;
        t += Math::PI * 2 / (trunkControlPtCount);
    }



    //std::cout << "trunkInterpolatedPtDetail = " << trunkInterpolatedPtDetail << std::endl;
    trunkSpline = Spline3(cps, trunkInterpolatedPtDetail, true, smoothness);
    trunk = Tube(pos, rot, size, col4, trunkSpline, trunkRadius, trunkCrossSectionPointCount);

    stemSplines.resize(stemCount);
    stems.resize(stemCount);

    // even distribution with no randomization

    int stemStep = static_cast<int> (trunkSpline.getVertsLength() / stemCount);


    //std::cout << " trunkSpline.getVertsLength() = " << trunkSpline.getVertsLength() << std::endl;
    for (int i = 0, k = 0; i < stemCount; ++i) {
        Vector3 pt = trunkSpline.getVerts().at(stemStep * (i + 1));
       // std::cout << "i = " << i << ": vert = " << pt << std::endl;
        std::vector<Vector3> stemCps;
        stemCps.resize(4);
        // stem splines
        for (int j = 0; j < stemCps.size(); ++j) {
            //stemCps.at(j) = Vector3(Math::random(-.05, .05), Math::random(-.05, .05), Math::random(-.05, .05) );
            
            stemCps.at(j) = Vector3(0, j*.007, 0);
        }
         stemSplines.at(k) = Spline3(stemCps, 15, true, smoothness);
         stems.at(k++) = Tube(pt, Vector3(), Dimension3f(10, 10, 10), col4 /*Color4f(.2, .3, .9, 1.0)*/, stemSplines.at(k), .006, 6);
    }
    // random distribution
    // even distribution with randomization (need a Perlin noise et al randomization implementation


    trunk.exportSTL();

}

void TubeBranch::display(GeomBase::displayMode mode, GeomBase::renderMode render, float pointSize) {
    trunk.display(GeomBase::VERTEX_BUFFER_OBJECT, GeomBase::SURFACE, 3.2);
     for (int i = 0; i < stems.size(); ++i) {
         stems.at(i).display(GeomBase::VERTEX_BUFFER_OBJECT, GeomBase::SURFACE, 3.2);
     }
}