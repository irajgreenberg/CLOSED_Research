
/*!  \brief  ProtoVertex.cpp: Base vertex implementation (xyz,rgba,uv)
 ProtoVertex.cpp
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

#include "ProtoVertex.h"

namespace ijg {

    std::ostream& operator<<(std::ostream& output, const ProtoVertex& vertex) {
        output << "vertex.pos: " << vertex.pos << ", vertex.col4: " <<
                vertex.col4 << ", vertex.norm: " << vertex.norm;
        return output;
    }

}

using namespace ijg;

ProtoVertex::ProtoVertex() {
    pos = ProtoVector3(0, 0, 0);
    col4 = ProtoColor4f(1, 1, 1, 1);
    uv = ProtoTuple2f(0,0);
}

ProtoVertex::ProtoVertex(const ProtoVector3& pos, const ProtoColor4<float>& col4) :
pos(pos), col4(col4) {
    uv = ProtoTuple2f(0,0);
}

ProtoVertex::ProtoVertex(const ProtoVector3& pos, const ProtoColor4f& col4, const ProtoTuple2f& uv) :
pos(pos), col4(col4), uv(uv) {
}

ProtoVertex::ProtoVertex(const ProtoVector3& pos) :
pos(pos) {
    col4 = ProtoColor4f(1, 1, 1, 1);
    uv = ProtoTuple2f(0,0);
}

