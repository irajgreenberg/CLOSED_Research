/*! File:   EllipticalWing.cpp
 * Author: Ira Greenberg
 *
 * Created on July 8, 2013, 11:28 AM
 * Copyright (c) 2013 Ira Greenberg. All rights reserved.
 */
#include "EllipticalWing.h"

using namespace proto;

/*!
 * Default Constructor */
EllipticalWing::EllipticalWing() {

}

/*!
 * Constructor */
EllipticalWing::EllipticalWing(int edgePointCount, int ringCount, float coreRadius) :
GeomBase(Vector3(0, 0, 0), Vector3(0, 0, 0), Dimension3f(1, 1, 1), Color4f(.5, .5, .5, 1)), edgePointCount(edgePointCount), ringCount(ringCount), coreRadiusRatio(coreRadiusRatio) {

    // ensure odd
    if (edgePointCount % 2 == 0) {
        ++edgePointCount;
    }
    init();

}

/*!
 * Constructor */
EllipticalWing::EllipticalWing(const Vector3& pos, const Vector3& rot, const Dimension3f& size, const Color4f& col4, int edgePointCount, int ringCount, float coreRadius) :
GeomBase(pos, rot, size, col4), edgePointCount(edgePointCount), ringCount(ringCount), coreRadiusRatio(coreRadiusRatio) {

    // ensure odd
    if (edgePointCount % 2 == 0) {
        ++edgePointCount;
    }
    init();
}

/*!
 * Constructor */
EllipticalWing::EllipticalWing(int edgePointCount, int ringCount, float coreRadiusRatio, float startAngle, float stopAngle, bool isClosed) :
edgePointCount(edgePointCount), ringCount(ringCount), coreRadiusRatio(coreRadiusRatio), startAngle(startAngle), stopAngle(stopAngle), isClosed(isClosed) {
    // ensure odd
    if (edgePointCount % 2 == 0) {
        ++edgePointCount;
    }
    init();
}

/*!
 * Constructor */
EllipticalWing::EllipticalWing(const Vector3& pos, const Vector3& rot, const Dimension3f& size, const Color4f& col4, int edgePointCount, int ringCount, float coreRadiusRatio, float startAngle, float stopAngle, bool isClosed) :
GeomBase(pos, rot, size, col4), edgePointCount(edgePointCount), ringCount(ringCount), coreRadiusRatio(coreRadiusRatio), startAngle(startAngle), stopAngle(stopAngle), isClosed(isClosed) {
    // ensure odd
    if (edgePointCount % 2 == 0) {
        ++edgePointCount;
    }
    init();

}

/*! overrides base class virtual functions
 */
void EllipticalWing::calcVerts() {
    // calculate outer wing curve points - not currently treated as spline - ***eventually fix this
    float theta = -(startAngle);
    float phi = 0;
    float coreRadius = size.w*coreRadiusRatio;
    std::cout << "coreRadius = " << coreRadius << std::endl;
    std::cout << "size.w = " << size.w << std::endl;
    float stepW = (size.w - coreRadius) / (ringCount - 1);
    //std::cout << "stepW = " << stepW << std::endl;
    for (int i = 0; i < edgePointCount; ++i) {
        for (int j = 0; j < ringCount; ++j) {
            verts.push_back(Vertex(Vector3(cos(theta) * (size.w - stepW * j), sin(theta) * (size.w - stepW * j), Math::random(-.02, .02)), col4));
        }
        if (stopAngle >= Math::TWO_PI && isClosed) {
            theta += stopAngle / (edgePointCount);
        } else {
            theta += stopAngle / (edgePointCount - 1);
        }
    }
}

/*! overrides base class virtual functions
 */
void EllipticalWing::calcInds() {

    for (int i = 0; i < edgePointCount - 1; ++i) {
        for (int j = 0; j < ringCount - 1; ++j) {
            if (!isClosed) {
                inds.push_back(Tuple3i(i * ringCount + j, (i + 1) * ringCount + j, (i + 1) * ringCount + j + 1));
                inds.push_back(Tuple3i(i * ringCount + j, (i + 1) * ringCount + j + 1, i * ringCount + j + 1));
            } else {
                inds.push_back(Tuple3i(i * ringCount + j, (i + 1) * ringCount + j, (i + 1) * ringCount + j + 1));
                inds.push_back(Tuple3i(i * ringCount + j, (i + 1) * ringCount + j + 1, i * ringCount + j + 1));
                
                // close wing
                if (i == edgePointCount - 2) {
                    inds.push_back(Tuple3i((i+1) * ringCount + j, j, j + 1));
                    inds.push_back(Tuple3i((i+1) * ringCount + j, j + 1, (i+1) * ringCount + j + 1));
                }
            }
        }
    }


}

