/*! \
 * File:   VerletCage.h
 * Author: Ira Greenberg
 *
 * Created on June 17, 2013, 3:01 PM
 * Copyright (c) 2013 Ira Greenberg. All rights reserved.
 */

#ifndef VERLETCAGE_H
#define	VERLETCAGE_H

#include "VerletBall.h"
#include "VerletStick.h"
#include "GraphicsCore.h"

namespace proto {

    class VerletCage : public GraphicsCore {
    public:
        /*!
         * Default Constructor */
        VerletCage();
        
        VerletCage(const Vector3& pos, const Vector3& rot, const Dimension3f& size, const Color4f& col4, int segments, int crossSectionDetail, float tension);

        // copy cstr
        VerletCage(const VerletCage& orig);

        // dstr
        virtual ~VerletCage();
        
        // assignment op
        VerletCage& operator=(const VerletCage& orig);
        
        void init();
        void display();
        void run();     
        

    private:

        int segments;
        int crossSectionDetail;
        float tension;
        std::vector<VerletBall*> balls;
        std::vector<Vector3> initBallPositions;
        std::vector<VerletStick> sticks;
        
        // for anchored exoskeleton box
        std::vector<VerletBall*> exoBalls;
        
        void calcBalls();
        void calcSticks();
        
        float theta;
    };

}

#endif	/* VERLETCAGE_H */

