/* 
 * File:   Branch.h
 * Author: ira
 *
 * Created on April 5, 2013, 10:16 AM
 */

#ifndef BRANCH_H
#define	BRANCH_H

#include "GeomBase.h"
#include "Spline3.h"
#include "Vertex.h"

namespace proto {

    class Branch : GeomBase {
    public:
        
        // cstrs
        Branch();
        Branch(Vertex terminals[2], int segs);
        Branch(Vertex terminalBegin, Vertex terminalEnd, int segs);
        Branch(Vertex terminals[2], int segs, float* radiiBegin, float* radiiEnd, float jitter);
        Branch(Vertex terminalBegin, Vertex terminalEnd, int segs, float* radiiBegin, float* radiiEnd, float jitter);
        Branch(Vertex terminals[2], int segs, float* radiiBegin, float* radiiEnd, float jitter, std::vector< Color4<float> > col4s);
        Branch(Vertex terminalBegin, Vertex terminalEnd, int segs, float* radiiBegin, float* radiiEnd, float jitter, std::vector< Color4<float> > col4s);

        // required overrides from base class
        void calcVerts();
        void calcInds();

    private:
        // Ends of branch
        Vertex terminalBegin, terminalEnd;
        Vertex* terminals;

        // Number of segments defining branch spline
        int segs;

        // Random jitter between terminals
        float jitter;


        // Float arrays for radii describing branch contour at terminals.
        float* radiiBegin, * radiiEnd;

        // Defines branch path
        Spline3 path;

        // disable (via private access) non-applicable 
        // functions from base GeomBase class
        // Let tree define all these

        void move(const Vector3& v) {
        }

        void rotate(const Vector3& r) {
        }

        void scale(const Dimension3<float>& s) {
        }

        void setPosition(const Vector3& pos) {
        }

        void setRotation(const Vector3& rot) {
        }

        void setSize(const Dimension3<float> size) {
        }

        Vector3& getPosition() {
        }

        Vector3& getRotation() {
        }

        Dimension3<float>& getSize() {
        }


    };
}

#endif	/* BRANCH_H */

