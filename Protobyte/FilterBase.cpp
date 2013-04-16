/* 
 * File:   FilterBase.cpp
 * Author: Ira Greenberg
 * 
 * Created on April 11, 2013, 9:12 AM
 */

#include "FilterBase.h"

using namespace proto;

FilterBase::FilterBase() {
}

FilterBase::FilterBase(unsigned char*& data, int w, int h) :
data(data), w(w), h(h) {

}

FilterBase::FilterBase(unsigned char*& data, int w, int h, int filterType, int kernalDepth) :
data(data), w(w), h(h), filterType(filterType), kernalDepth(kernalDepth) {

}


FilterBase::FilterBase(unsigned char*& data, int w, int h, const std::vector<int>& kernal) :
data(data), w(w), h(h), kernal(kernal) {

}


FilterBase::~FilterBase() {
}

