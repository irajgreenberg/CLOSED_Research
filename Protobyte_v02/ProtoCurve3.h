/*!  \brief  ProtoCurve3.h: Abstract base class for all curves
 ProtoCurve3.cpp
Protobyte Library v02
 
 Created by Ira on 7/23/13.
 Copyright (c) 2013 Ira Greenberg. All rights reserved.
 
 Library Usage:
 This work is licensed under the Creative Commons
 Attribution-NonCommercial-ShareAlike 3.0 Unported License.
 To view a copy of this license, visit
 http://creativecommons.org/licenses/by-nc-sa/3.0/
 or send a letter to Creative Commons,
 444 Castro Street, Suite 900,
 Mountain View, California, 94041, USA.
 
 This notice must be retained any source distribution.
 
 \ingroup common
 This class is part of the group common (update)
 \sa NO LINK
 */


#ifndef ProtoCurve3_h
#define ProtoCurve3_h

#include <SFML/OpenGL.hpp>
#include "ProtoDimension3.h"
#include <vector>
#include "ProtoFrenetFrame.h"

namespace ijg {

    class ProtoCurve3 {
    protected:

        /**
         * std::vector of control points.
         */
        std::vector<Vec3f> controlPts;

        /**
         * The number of interpolated points along the curve.
         */
        int interpDetail;

        /**
         * std::vector of interpolated points along curve.
         */
        std::vector<Vec3f> interpPts;

        /**
         * std::vector of all curve vertices.
         */
        std::vector<Vec3f> verts;

        /**
         * std::vector of all curve vertices (Frenet frame).
         */
        std::vector<Vec3f> biNorms;

        /**
         * std::vector of all curve normals (Frenet frame).
         */
        std::vector<Vec3f> norms;

        /**
         * std::vector of Frenet frames.
         */
        std::vector<ProtoFrenetFrame> frenetFrames;

        /**
         * std::vector of Parallel Transport thetas.
         */
        std::vector<float> parallelTransportThetas;


        /**
         * Radius of rectangle used for rendering vertsBuff (?)
         */
        double vertRad;
        // orig val = .075;

        /**
         * boolean to specify whether the path is closed
         */
        bool isCurveClosed;

        /**
         * boolean to specify the curvature at the path terminals 
         */
        bool isTerminalSmooth;

        /**
         * std::vector temporarily stores vertices during calculations in init(); 
         */
        std::vector<Vec3f> tempVecs;

        /**
         * Bounding box of entire curve
         */
        ProtoDimension3<float> dim;


    public:
        // constructors

        ProtoCurve3();

        ProtoCurve3(const std::vector<Vec3f>& controlPts, int interpDetail, bool isCurveClosed);



        // copy Constructor - Use default: no explicit heap allocation
        //ProtoCurve3(ProtoCurve3& curve3d_src);

        // assignment operator – Use default: no explicit heap allocation
        //ProtoCurve3& operator=(ProtoCurve3& curve3d_src);

        // destructor
        virtual ~ProtoCurve3();

        // pure virtual methods - must be overridden in subclasses
        /**
         * Calculate the interpolated curve points populating the vecs array.
         */
        virtual void init() = 0;

        /**
         * Draw the curve.
         */
        virtual void display() = 0;

        /**
         * Draw the curve points.
         */
        virtual void displayControlPts() = 0;

        /**
         * Draw the curve points.
         */
        virtual void displayInterpPts() = 0;

        /**
         * Draw the Frenet Frame.
         */
        virtual void displayFrenetFrames(float len = 20) = 0;

        //virtual void createProtoFrenetFrame();

        /**
         * Returns length of the control points array.
         */
        int getControlPtsLength();

        /**
         * Returns length of the points std::vector (pts between control points).
         */
        int getInterpDetail();



        /**
         * Set the control points, with side effects
         */
        void setControlPts(std::vector<Vec3f>& controlPts);

        /**
         * get a pointer to the  control points array, with side effects
         */
        std::vector<Vec3f>& getControlPts();

        /**
         * Get the curve vertsBuff's length.
         * 
         * @return int
         */
        int getVertsLength() const;

        /**
         * Set all the curve points
         * 
         * @param uniqueVerts
         *            Vector array
         */
        void setVerts(std::vector<Vec3f> verts);

        /**
         * Get pointer all the curve points
         * 
         * @param uniqueVerts
         *            Vector array
         */
        std::vector<Vec3f>& getVerts();

        /**
         * Get std::vector of all vertices
         */
        std::vector<Vec3f>& getVertices();

        /**
         * Get ProtoCurve3 object dimensions.
         * 
         * @return ProtoDimension3 object
         */
        ProtoDimension3<float>& getDimension();

        /**
         * Get vertex radius.
         * 
         * @return double value
         */
        double getVertRad() const;

        /**
         * Set vertex radius
         * 
         * @param vertRad
         *            double value
         */
        void setVertRad(double vertRad);

        /**
         * Get flag value telling if curve is closed
         * 
         * @return boolean value
         */
        bool getIsCurveClosed() const;

        /**
         * Set flag for Curve to be closed
         * 
         * @param isCurveClosed
         *            boolean value
         */
        void setIsCurveClosed(bool isCurveClosed);

        /**
         * Get flag value telling if curve at Terminals is continuous
         * 
         * @return boolean value
         */
        bool getIsTerminalSmooth() const;

        /**
         * Set flag for Curve at Terminals to be continuous
         * 
         * @param isTerminalSmooth
         *            boolean value
         */
        void setIsTerminalSmooth(bool isTerminalSmooth);

        /**
         * get Frenet Frames
         * 
         * @return Frenet Frame
         */
        const std::vector<ProtoFrenetFrame>& getFrenetFrames() const;



    };

}


#endif
