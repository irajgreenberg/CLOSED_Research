//
//  Curve3.h
//  Protobyte Library V01
//
//  Created by Ira Greenberg on 8/2/11.
//  Copyright 2011 SMU. All rights reserved.
//
// Library Usage:
// This work is licensed under the Creative Commons 
// Attribution-NonCommercial-ShareAlike 3.0 Unported License. 
// To view a copy of this license, visit 
// http://creativecommons.org/licenses/by-nc-sa/3.0/ 
// or send a letter to Creative Commons, 
// 444 Castro Street, Suite 900, 
// Mountain View, California, 94041, USA.
//

#ifndef Protobyte_Library_V01_Curve3_h
#define Protobyte_Library_V01_Curve3_h

#include "Dimension3.h"
#include <vector>
#include "FrenetFrame.h"

namespace proto {

    class Curve3 {
    protected:

        /**
         * std::vector of control points.
         */
        std::vector<Vector3> controlPts;

        /**
         * The number of interpolated points along the curve.
         */
        int interpDetail;

        /**
         * std::vector of interpolated points along curve.
         */
        std::vector<Vector3> interpPts;

        /**
         * std::vector of all curve vertices.
         */
        std::vector<Vector3> verts;

        /**
         * std::vector of all curve vertices (Frenet frame).
         */
        std::vector<Vector3> biNorms;

        /**
         * std::vector of all curve normals (Frenet frame).
         */
        std::vector<Vector3> norms;

        /**
         * std::vector of Frenet frames.
         */
        std::vector<FrenetFrame> frenetFrames;

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
        std::vector<Vector3> tempVecs;

        /**
         * Bounding box of entire curve
         */
        Dimension3<float> dim;


    public:
        // constructors

        Curve3();

        Curve3(const std::vector<Vector3>& controlPts, int interpDetail, bool isCurveClosed);



        // copy Constructor - Use default: no explicit heap allocation
        //Curve3(Curve3& curve3d_src);

        // assignment operator – Use default: no explicit heap allocation
        //Curve3& operator=(Curve3& curve3d_src);

        // destructor
        virtual ~Curve3();

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

        //virtual void createFrenetFrame();

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
        void setControlPts(std::vector<Vector3>& controlPts);

        /**
         * get a pointer to the  control points array, with side effects
         */
        std::vector<Vector3>& getControlPts();

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
        void setVerts(std::vector<Vector3> verts);

        /**
         * Get pointer all the curve points
         * 
         * @param uniqueVerts
         *            Vector array
         */
        std::vector<Vector3>& getVerts();

        /**
         * Get std::vector of all vertices
         */
        std::vector<Vector3>& getVertices();

        /**
         * Get Curve3 object dimensions.
         * 
         * @return Dimension3 object
         */
        Dimension3<float>& getDimension();

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
         * get Frenet Frame
         * 
         * @return Frenet Frame
         */
        const std::vector<FrenetFrame>& getFrenetFrame() const;



    };

}


#endif
