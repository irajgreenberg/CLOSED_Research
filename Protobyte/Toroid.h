/* 
 * File:   Toroid.h
 * Author: 33993405
 *
 * Created on February 18, 2013, 3:55 PM
 */

#ifndef TOROID_H
#define	TOROID_H

#include "GeomBase.h"

class Toroid : public GeomBase {

    public:
    //Toroid();
    Toroid(const Vector3& pos, const Vector3& rot, const Dimension3<float>& size, 
            const Color4<float>& col4, int ringCount, int ringDetail, float ringRadius);
    
private:
    int ringCount, ringDetail;
    float ringRadius;
    
    void calcVerts(); // overrides virtual method in base class
    void calcInds(); // overrides virtual method in base class
    

};

#endif	/* TOROID_H */

