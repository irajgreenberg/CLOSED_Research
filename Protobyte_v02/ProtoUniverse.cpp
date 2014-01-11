/*!  \brief  ProtoUniverse.cpp: Top Level Master class
 ProtoUniverse.cpp
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

#include "ProtoUniverse.h"

using namespace ijg;

ProtoUniverse* ProtoUniverse::singletonUniverse = 0;

//private cstr called internally 
ProtoUniverse::ProtoUniverse() {
    init();
}

// dstr
ProtoUniverse::~ProtoUniverse() {
    
}

ProtoUniverse& ProtoUniverse::operator=(const ProtoUniverse& universe) {
    return *this;
}


ProtoUniverse* ProtoUniverse::getInstance()
{
    
    // allocation hasn't happened yet, so do it
    if(singletonUniverse == 0)
    {
        std::cout<<"Singleton ProtoUniverse obj created"<<std::endl;
        singletonUniverse = new ProtoUniverse();
        return singletonUniverse;
    }
    // pointer to object already exists just return it
    else
    {
        std::cout<<"Pointer to existing Singleton ProtoUniverse obj returned"<<std::endl;
        return singletonUniverse;
    }
}

void ProtoUniverse::init(){
    // enable renderer and animator
    renderer = ProtoRenderer::getInstance();
    animator = ProtoAnimator::getInstance();
}

void ProtoUniverse::add(ProtoGeomBase* geomObj){
    geomObjs.push_back(geomObj);
}

void ProtoUniverse::add(ProtoGeomComposite* geomObj){
    // TO DO
}

void ProtoUniverse::add(ProtoCamera* camera){
    cameras.push_back(camera);
    std::cout << "camera.getUniqueID() = " << int(camera->getUniqueID()) << std::endl;
    
}

void ProtoUniverse::remove(ProtoGeomBase* geomObj) {
}


void ProtoUniverse::remove(ProtoCamera* camera){
    if(cameras.size()>0){
        for(cameraObjsIter=cameras.begin(); cameraObjsIter < cameras.end(); ++cameraObjsIter){
            if( (*cameraObjsIter)->getUniqueID() == camera->getUniqueID()){
                cameras.erase(cameraObjsIter);
                
            }
        }
    }
    std::cout << "cameras.size() = " << cameras.size() << std::endl;
}


// run universe
void ProtoUniverse::run() {
    for(geomObjsIter=geomObjs.begin(); geomObjsIter < geomObjs.end(); ++geomObjsIter){
        if(*geomObjsIter != 0){
           // renderer->draw(*geomObjsIter);
            
        }
    }
}

// stop universe
void ProtoUniverse::stop(){
}


// set states
void setRenderState(ProtoRenderer::RenderModeEnum renderMode, float pointSize) {
   // this->renderMode = renderMode;
}


