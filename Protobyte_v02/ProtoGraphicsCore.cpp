/*!  \brief  ProtoGraphicsCore.cpp: Abstact Base Graphics class
 ProtoGraphicsCore.cpp
 Protobyte Library v02
 
 Created by Ira on 7/23/13.
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



#include "ProtoGraphicsCore.h"

using namespace ijg;

/*!
 * Default Constructor */
ProtoGraphicsCore::ProtoGraphicsCore(){
}

/*!
 * Constructor */
ProtoGraphicsCore::ProtoGraphicsCore(const ProtoVector3& pos, const ProtoVector3& rot, const ProtoDimension3f& size,
        const ProtoColor4f& col4) : pos(pos), rot(rot), size(size), col4(col4){

}

/*!
 * Constructor */
ProtoGraphicsCore::ProtoGraphicsCore(const ProtoVector3& pos, const ProtoVector3& rot, const ProtoDimension3f& size,
        const std::vector< ProtoColor4f >& col4s) : pos(pos), rot(rot), size(size), col4s(col4s){

}

ProtoGraphicsCore::~ProtoGraphicsCore() {

}

