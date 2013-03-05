//
//  ProtoTube.h
//  Protobyte_iig001
//
//  Created by Ira on 10/17/12.
//
//

#ifndef Protobyte_iig001_ProtoTube_h
#define Protobyte_iig001_ProtoTube_h

#include <iostream>
#include "Spline3d.h"
#include "ProtoOrgBase.h"

namespace ijg {

    class ProtoTube: public ProtoOrgBase{
        
    public:
        
        friend std::ostream& operator<<(std::ostream& out, const ProtoTube& tube);
        ProtoTube();
        ProtoTube(const ofVec3f& loc, const Dimension3D& dim, const Spline3d& path, float radii[], int crossSectionDetail); // varied thickness
        ProtoTube(const ofVec3f& loc, const Dimension3D& dim, const Spline3d& path, float radius, int crossSectionDetail);
        
        // overrides base class
        void calcVerts();
        void calcInds();
        
        const Spline3d& getPath() const;

   
    private:
        Spline3d path;
        float radius;
        std::vector<float> radii;
        int crossSectionDetail;
    };
}


#endif
