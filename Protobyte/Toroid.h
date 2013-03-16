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

    explicit Toroid(const Vector3& pos = Vector3(0,0,0), const Vector3& rot = Vector3(0,0,0), const Dimension3<float>& size = Dimension3<float>(1, 1, 1),
            const Color4<float>& col4 = Color4<float>(1, 1, 1, 1), int ringCount = 12, int ringDetail = 12, float ringRadius = .5, float ringThickness = .1);

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
inline void Toroid::setRingThickness(float ringThickness) {
    this->ringThickness = ringThickness;
}

inline float Toroid::getRingThickness() const {
    return ringThickness;
}

inline void Toroid::setRingRadius(float ringRadius) {
    this->ringRadius = ringRadius;
}

inline float Toroid::getRingRadius() const {
    return ringRadius;
}

inline void Toroid::setRingDetail(int ringDetail) {
    this->ringDetail = ringDetail;
}

inline int Toroid::getRingDetail() const {
    return ringDetail;
}

inline void Toroid::setRingCount(int ringCount) {
    this->ringCount = ringCount;
}

inline int Toroid::getRingCount() const {
    return ringCount;
}


#endif	/* TOROID_H */

