/*!  \brief  ProtoAnimator.cpp: Coordinates all motion within ProtoAnimator
 ProtoAnimator.cpp
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

#include "ProtoAnimator.h"

using namespace ijg;


ProtoAnimator* ProtoAnimator::singletonAnimator = 0;

ProtoAnimator& ProtoAnimator::operator=(const ProtoAnimator& animator) {
    return *this;
}


ProtoAnimator* ProtoAnimator::getInstance()
{
    
    // allocation hasn't happened yet, so do it
    if(singletonAnimator == 0)
    {
        std::cout<<"Singleton ProtoAnimator obj created"<<std::endl;
        singletonAnimator = new ProtoAnimator();
        return singletonAnimator;
    }
    // pointer to object already exists just return it
    else
    {
        std::cout<<"Pointer to existing Singleton ProtoAnimator obj returned"<<std::endl;
        return singletonAnimator;
    }
    
}

void ProtoAnimator::start(){

}


void ProtoAnimator::stop(){

}