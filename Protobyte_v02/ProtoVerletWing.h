/*! \
 * File:   VerletWing.h
 * Author: Ira Greenberg
 *
 * Created on June 27, 2013, 5:25 PM
 * Copyright (c) 2013 Ira Greenberg. All rights reserved.
 */

#ifndef VERLETWING_H
#define	VERLETWING_H

#include "VerletBase.h"
namespace proto {

    class VerletWing : public VerletBase {
    public:
//        std::ostream& operator<<(std::ostream& out, const VerletWing& orig);
        
        /*!
         * Default Constructor */
        VerletWing();

        VerletWing(const Vector3& pos, const Vector3& rot, const Dimension3f& size, const Color4f& col4, int segments, int crossSectionDetail, float tension);

        // copy cstr
        VerletWing(const VerletWing& orig);

        VerletWing& operator=(const VerletWing &orig);

        virtual ~VerletWing();

        // required overriddedn funds
        void init();
        void calcBalls();
        void calcSticks();

    private:
    };
    
//    std::ostream& operator<<(std::ostream& out, const VerletWing& orig){
//        out << pos << ", " << 
//                pos << ", " <<
//                pos << ", " <<
//                pos << ", " <<
//                pos << ", " <<
//        return out;
//    }

}

#endif	/* VERLETWING_H */

