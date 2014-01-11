/*!  \brief  ProtoShape3.cpp: Abstact Base 3D Shape class
 ProtoShape3.cpp
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



#include "ProtoShape3.h"



namespace ijg {
    
    std::ostream& operator<<(std::ostream& out, const ProtoShape3& shape){
        out << shape.pos << ", " <<
            shape.rot << ", " <<
            shape.size << ", " <<
            shape.col4;
            return out;
        
    }
}


using namespace ijg;

/*!
 * Default Constructor */
ProtoShape3::ProtoShape3(){
}

/*!
 * Constructor */
ProtoShape3::ProtoShape3(const Vec3f& pos, const Vec3f& rot, const Dim3f& size,
        const ProtoColor4f& col4) : pos(pos), rot(rot), size(size), col4(col4){

}

/*!
 * Constructor */
ProtoShape3::ProtoShape3(const Vec3f& pos, const Vec3f& rot, const Dim3f& size,
        const std::vector< ProtoColor4f >& col4s) : pos(pos), rot(rot), size(size), col4s(col4s){

}

ProtoShape3::~ProtoShape3() {

}



