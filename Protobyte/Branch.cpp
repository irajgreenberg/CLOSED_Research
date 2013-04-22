/* 
 * File:   Branch.cpp
 * Author: ira
 * 
 * Created on April 5, 2013, 10:16 AM
 */

#include "Branch.h"

using namespace proto;

Branch::Branch() {
}

Branch::Branch(Vertex* terminals, int segs) :
terminals(terminals), segs(segs) {

}

Branch::Branch(Vertex terminalBegin, Vertex terminalEnd, int segs) :
terminalBegin(terminalBegin), terminalEnd(terminalEnd) {
}

Branch::Branch(Vertex terminals[2], int segs, float* radiiBegin, float* radiiEnd, float jitter) :
terminals(terminals), segs(segs), radiiBegin(radiiBegin), radiiEnd(radiiEnd), jitter(jitter) {

}

Branch::Branch(Vertex terminalBegin, Vertex terminalEnd, int segs, float* radiiBegin, float* radiiEnd, float jitter) :
terminalBegin(terminalBegin), terminalEnd(terminalEnd), segs(segs), radiiBegin(radiiBegin), radiiEnd(radiiEnd), jitter(jitter) {

}

Branch::Branch(Vertex terminals[2], int segs, float* radiiBegin, float* radiiEnd, float jitter, std::vector< Color4<float> > col4s) :
terminals(terminals), segs(segs), radiiBegin(radiiBegin), radiiEnd(radiiEnd), jitter(jitter) {
    this->col4s = col4s;
}

Branch::Branch(Vertex terminalBegin, Vertex terminalEnd, int segs, float* radiiBegin, float* radiiEnd, float jitter, std::vector< Color4<float> > col4s) :
terminalBegin(terminalBegin), terminalEnd(terminalEnd), segs(segs), radiiBegin(radiiBegin), radiiEnd(radiiEnd), jitter(jitter) {
    this->col4s = col4s;
}

// required overrides from base class

void Branch::calcVerts() {

}

void Branch::calcInds() {

}

