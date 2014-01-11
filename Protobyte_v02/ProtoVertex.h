/*!  \brief  ProtoVertex.h: Base vertex implementation (xyz,rgba,uv)
 ProtoVertex.h
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

#ifndef PROTO_VERTEX_H
#define	PROTO_VERTEX_H

#include "ProtoVector3.h"
#include "ProtoColor4.h"
#include "ProtoTuple2.h"

namespace ijg {

    class ProtoVertex {
    public:
        friend std::ostream& operator<<(std::ostream& output, const ProtoVertex& vertex);

        ProtoVertex();
        ProtoVertex(const ProtoVector3& pos);
        ProtoVertex(const ProtoVector3& pos, const ProtoColor4<float>& col4);
        ProtoVertex(const ProtoVector3& pos, const ProtoColor4<float>& col4, const ProtoTuple2<float>& uv);

        ProtoVector3 pos;

        const ProtoVector3& getNormal() const;
        ProtoColor4<float> getColor() const;
        ProtoTuple2<float> getUV() const;

        void setNormal(const ProtoVector3& norm);
        void setColor(const ProtoColor4<float>& col4);
        void setUV(const ProtoTuple2<float>& uv);

    private:
        ProtoColor4<float> col4;
        ProtoVector3 norm;
        ProtoTuple2<float> uv;

        void init();
    };
    
    // inline getters/setters

    inline const ProtoVector3& ProtoVertex::getNormal() const {
        return norm;
    }

    inline void ProtoVertex::setNormal(const ProtoVector3& norm) {
        this->norm = norm;
    }

    inline ProtoColor4<float> ProtoVertex::getColor() const {
        return col4;
    }

    inline void ProtoVertex::setColor(const ProtoColor4<float>& col4) {
        this->col4 = col4;
    }
    
    inline ProtoTuple2<float> ProtoVertex::getUV() const {
        return uv;
    }
    
    inline void ProtoVertex::setUV(const ProtoTuple2<float>& uv){
        this->uv = uv;
    }


}
#endif	// PROTO_VERTEX_H

