//
//  Tube.h
//  Protobyte_iig001
//
//  Created by Ira on 10/17/12.
//
//

#ifndef Protobyte_iig001_Tube_h
#define Protobyte_iig001_Tube_h

#include <iostream>
#include "GeomBase.h"
#include "Spline3.h"

namespace proto {

    class Tube : public GeomBase {
    public:

        friend std::ostream& operator<<(std::ostream& out, const Tube& tube);

        //const Vector3& pos, const Vector3& rot, const Dimension3<float> size, const Color4<float> col4
        Tube();
        Tube(const Vector3& pos, const Vector3& rot, const Dimension3<float> size, const Color4<float> col4, const Spline3& path, float radius, int crossSectionDetail);
        Tube(const Vector3& pos, const Vector3& rot, const Dimension3<float> size, const Color4<float> col4, const Spline3& path, std::vector<float> radii, int crossSectionDetail); // varied thickness
        Tube(const Vector3& pos, const Vector3& rot, const Dimension3<float> size, const std::vector< Color4<float> > col4s, const Spline3& path, float radius, int crossSectionDetail); // varied color 
        Tube(const Vector3& pos, const Vector3& rot, const Dimension3<float> size, const std::vector< Color4<float> > col4s, const Spline3& path, std::vector<float> radii, int crossSectionDetail); // varied thickness & color


        // overrides base class
        void calcVerts();
        void calcInds();

        const Spline3& getPath() const;


    private:
        Spline3 path;
        float radius;
        std::vector<float> radii;
        int crossSectionDetail;
    };


}


#endif
