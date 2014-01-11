/* 
 * File:   Tendril.cpp
 * Author: 33993405
 * 
 * Created on March 20, 2013, 9:30 AM
 */

#include "Tendril.h"

using namespace proto;


Tendril::Tendril(const Vector3& pos, const Vector3& rot, const Dimension3<float> size, const Color4<float> col4, int recursionLevel, int maxBranchingLevel) :
GeomBase(pos, rot, size, col4),recursionLevel(recursionLevel), maxBranchingLevel(maxBranchingLevel) {

}


// overrides base class

void Tendril::calcVerts() {

}

void Tendril::calcInds() {

}