/*! File:   Nematode.cpp
 * Author: Ira Greenberg
 *
 * Created on July 18, 2013, 1:55 PM
 * Copyright (c) 2013 Ira Greenberg. All rights reserved.
 */

#include "Nematode.h"


using namespace proto;

/*!
 * Default Constructor */
Nematode::Nematode() {

}


Nematode::Nematode(const Vector3& pos, const Vector3& rot, const Dimension3f& size,
                const Color4f& col4, const Tube& tube):
                GraphicsCore(pos, rot, size, col4), tube(tube){
    
}

Nematode::~Nematode() {

}

void Nematode::init() {
    tube.getFrenetFrame()
    
}

