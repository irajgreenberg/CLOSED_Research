/*!  \brief  ProtoSphere.h: sphere implementation
 ProtoSphere.h
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

#ifndef PROTO_SPHERE_H
#define	PROTO_SPHERE_H

#include "ProtoGeom3.h"

namespace ijg {

    class ProtoSphere : public ProtoGeom3 {
    public:
        ProtoSphere();
        ProtoSphere(const Vec3f& pos, const Vec3f& rot, const Dim3f size,
                const ProtoColor4f col4, int spines, int spineNodes);

        ProtoSphere(const Vec3f& pos, const Vec3f& rot, const Dim3f size,
                const ProtoColor4f col4, float textureScale, int spines, int spineNodes);

//        void init(); // temp override
        void calcVerts();
        void calcInds();
        
        // testing only 
        void calcVerts2();
        void calcInds2();

    private:
        int spines;
        int spineNodes;

    };
}

#endif	// PROTO_SPHERE_H

