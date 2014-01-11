/*! \File:   Block.h
 * L-System class  
 * Bracketed Tree
 * =============================
 * Rules:
 * f : Move forward pen UP
 * F : Move Forward pen DOWN 
 * + : Turn right 90 degs
 * - : Turn left 90 degs
 * 
 * Axiom F
 * initial angle 0 degs
 * initial string: F-F-F-F
 * Rule: F -> F+F-F-FF+F+F-F 
 * Lindenmayer.h
 * Author: ira
 *
 * Created on April 24, 2013, 2:52 PM
 */

#ifndef LINDENMAYER_H
#define	LINDENMAYER_H

#include <iostream>
#include "GeomBase.h"

namespace proto {

    class Lindenmayer : public GeomBase {
    public:

        friend std::ostream& operator<<(std::ostream& out, const Lindenmayer& l_system);


        Lindenmayer();
        Lindenmayer(const Vector3& pos, const Vector3& rot, const Dimension3<float>& size,
                const Color4<float>& col4, float textureScale, int recusionLimit);


        /*!
         * Creates char sequence*/
        void generate();
        
        /*!
         * Creates char sequence*/
        void parse();
        
        
        /*!
         * Declared pure virtual in GeomBase base class
         * and must be implemented in all derived classes.
         * 
         * Generates all vertices.*/
        void calcVerts();


        /*!
         * Declared pure virtual in GeomBase base class
         * and must be implemented in all derived classes: 
         * 
         * Generates indices to group vertices to triangle faces.*/
        void calcInds();
    private:
        int recursionLimit;
        int recursionCount;

        // axiom
        char chars[1];
        // { 'F' };

        // temp char array
        std::vector<char> tempChars;

        // substitution rule
        std::vector<char> rules;
        // 'F', '[', '+', 'F', ']', 'F', '[', '-', 'F', ']', 'F'
    };

}
#endif	/* LINDENMAYER_H */

