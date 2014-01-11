/*!  \brief  ProtoRenderer.cpp: Coordinates all rendering in ProtoUniverse
 ProtoRenderer.cpp
 Protobyte Library v02
 
 Created by Ira on 7/25/13.
 Copyright (c) 2013 Ira Greenberg. All rights reserved.
 
 Library Usage:
 This work is licensed under the Creative Commons
 Attribution-NonCommercial-ShareAlike 3.0 Unported License.
 To view a copy of this license, visit
 http://creativecommons.org/licenses/by-nc-sa/3.0/
 or send a letter to Creative Commons,
 444 Castro Street, Suite 900,
 Mountain View, California, 94041, USA.
 
 This notice must be retained any source distribution.
 
 \ingroup common
 This class is part of the group common (update)
 \sa NO LINK
 */

#include "ProtoRenderer.h"

using namespace ijg;

ProtoRenderer* ProtoRenderer::singletonRenderer = 0;


ProtoRenderer& ProtoRenderer::operator=(const ProtoRenderer& renderer) {
    return *this;
}

// private default cstr to enforce singleton pattern
ProtoRenderer::ProtoRenderer(){
    init();
}

void ProtoRenderer::init(){
}

ProtoRenderer* ProtoRenderer::getInstance()
{
    
    // allocation hasn't happened yet, so do it
    if(singletonRenderer == 0)
    {
        std::cout<<"Singleton ProtoRenderer obj created"<<std::endl;
        singletonRenderer = new ProtoRenderer();
        return singletonRenderer;
    }
    // pointer to object already exists just return it
    else
    {
        std::cout<<"Pointer to existing Singleton ProtoRenderer obj returned"<<std::endl;
        return singletonRenderer;
    }
    
}


void ProtoRenderer::draw(const ProtoGeom3& geomObj, DisplayMode mode, RenderMode render, float pointSize) {
}

