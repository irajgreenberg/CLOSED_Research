/*!  \brief  ProtoToroid.h: Toroid implementation
 ProtoToroid.h
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

#ifndef PROTO_TOROID_H
#define	PROTO_TOROID_H

#include "ProtoGeom3.h"

namespace ijg {

    class ProtoToroid : public ProtoGeom3 {
    public:

        ProtoToroid();

        ProtoToroid(const Vec3f& pos, const Vec3f& rot, const ProtoDimension3<float>& size, const ProtoColor4<float>& col4,
                int ringCount, int ringDetail, float ringRadius, float ringThickness);


        // get/sets inlined below class
        void setRingThickness(float ringThickness);
        float getRingThickness() const;
        void setRingRadius(float ringRadius);
        float getRingRadius() const;
        void setRingDetail(int ringDetail);
        int getRingDetail() const;
        void setRingCount(int ringCount);
        int getRingCount() const;

    private:
        int ringCount, ringDetail;
        float ringRadius, ringThickness;

        void calcVerts(); // overrides virtual method in base class
        void calcInds(); // overrides virtual method in base class
    };


    //inlined gets/sets

    inline void ProtoToroid::setRingThickness(float ringThickness) {
        this->ringThickness = ringThickness;
    }

    inline float ProtoToroid::getRingThickness() const {
        return ringThickness;
    }

    inline void ProtoToroid::setRingRadius(float ringRadius) {
        this->ringRadius = ringRadius;
    }

    inline float ProtoToroid::getRingRadius() const {
        return ringRadius;
    }

    inline void ProtoToroid::setRingDetail(int ringDetail) {
        this->ringDetail = ringDetail;
    }

    inline int ProtoToroid::getRingDetail() const {
        return ringDetail;
    }

    inline void ProtoToroid::setRingCount(int ringCount) {
        this->ringCount = ringCount;
    }

    inline int ProtoToroid::getRingCount() const {
        return ringCount;
    }

}


#endif	// PROTO_TOROID_H

