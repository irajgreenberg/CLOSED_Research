/* 
 * File:   Tendril.h
 * Author: 33993405
 *
 * Created on March 20, 2013, 9:30 AM
 */

#ifndef TENDRIL_H
#define	TENDRIL_H

#include <vector>
#include "GeomBase.h"
#include "Tube.h"

namespace proto {

    class Tendril : public GeomBase {
    public:
        //Tube(const Vector3& pos, const Vector3& rot, const Dimension3<float> size, 
        //const std::vector< Color4<float> > col4s, const Spline3& path, 
        // std::vector<float> radii, int crossSectionDetail); // varied thickness & color

        Tendril(const Vector3& pos, const Vector3& rot, const Dimension3<float> size, const Color4<float> col4, int recursionLevel, int maxBranchingLevel);

        // overrides base class
        void calcVerts();
        void calcInds();

    private:
        int recursionLevel;
        int maxBranchingLevel;
        std::vector<Tube> stems;



    };

}

#endif	/* TENDRIL_H */

