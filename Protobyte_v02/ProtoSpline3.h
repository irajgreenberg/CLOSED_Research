/*!  \brief  ProtoSpline3.h: Catmull-Rom spline class implementation
 ProtoSpline3.h
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

#ifndef PROTO_SPLINE3_H
#define PROTO_SPLINE3_H

#include "ProtoCurve3.h"

/**
 * Spline cubic curve class, where curve goes through all points. Curve is
 * specified by 6 points, with a smoothness value specifying tension.
 * <p>
 */

namespace ijg {

    class ProtoSpline3 : public ProtoCurve3 {
    public:

        ProtoSpline3();

        ProtoSpline3(const std::vector<Vec3f>& controlPts, int interpDetail, bool isCurveClosed, float smoothness);


        /**
         * Set flag for Curve at Terminals to be continuous
         * 
         * @param isTerminalSmooth
         *            boolean value
         */
        void setTerminalSmooth(bool isTerminalSmooth);

        /**
         * Draw the curve.
         * 
         */
        void display();

        /**
         * Draw the control points.
         * 
         */
        void displayControlPts();

        /**
         * Draw the interpolated points.
         * 
         */
        void displayInterpPts();

        /**
         * Draw the Frenet Frames.
         *
         */
        void displayFrenetFrames(float len = 20);

        /**
         * Set the smoothenss value.
         * 
         */
        void setSmoothness(float smoothness);

        /**
         * get the smoothenss value.
         * 
         */
        float getSmoothness(float smoothness) const;

        /**
         * sets flag for curve closed
         * 
         */
        void setCurveClosed(bool isCurveClosed);

        /**
         * Draw cross-section extruded along the spline path.
         * Default cross-section is an ellipse
         */
        void drawCrossSections(); // temp
        
        

    private:

        /**
         * Controls spline curve curvature.
         */
        float smoothness;

        /**
         * allocate memory and initialize stuff.
         */
        void init();

        /**
         * Frenet frame is used to calcuate extrusions
         * along spline path (Tubes & Tendrils baby!).
         * Called automatically by init()
         */
        void parallelTransport();

    };

}


#endif // PROTO_SPLINE3_H
