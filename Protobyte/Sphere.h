
/* 
 * File:   Sphere.h
 * Author: 33993405
 *
 * Created on April 25, 2013, 1:47 PM
 */

#ifndef SPHERE_H
#define	SPHERE_H

#include "GeomBase.h"

namespace proto {

    class Sphere : public GeomBase {
    public:
        Sphere();
        Sphere(const Vector3& pos, const Vector3& rot, const Dimension3f size,
                const Color4f col4, int spines, int spineNodes);

        Sphere(const Vector3& pos, const Vector3& rot, const Dimension3f size,
                const Color4f col4, float textureScale, int spines, int spineNodes);

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

#endif	/* SPHERE_H */

