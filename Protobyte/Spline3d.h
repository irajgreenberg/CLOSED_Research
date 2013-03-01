//
//  Spline3d.h
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

#ifndef Protobyte_Library_V01_Spline3d_h
#define Protobyte_Library_V01_Spline3d_h

#include "Curve3d.h"

/**
 * Spline cubic curve class, where curve goes through all points. Curve is
 * specified by 6 points, with a smoothness value specifying tension.
 * <p>
 */

namespace ijg {
    
    class Spline3d: public Curve3d {
        
    public:
        Spline3d(ofVec3f controlPt0 = ofVec3f(), ofVec3f controlPt1 = ofVec3f(), ofVec3f controlPt2 = ofVec3f(), ofVec3f controlPt3 = ofVec3f(), ofVec3f controlPt4 = ofVec3f(), ofVec3f controlPt5 = ofVec3f(), ofVec3f controlPt6 = ofVec3f(), ofVec3f controlPt7 = ofVec3f(), int interpDetail = .1, bool isCurveClosed = false, float smoothness = .5);    
        
        Spline3d(const std::vector<ofVec3f>& controlPts, int interpDetail, bool isCurveClosed, float smoothness);        
        
        
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
        void createFrenetFrame();
        
    };
}


#endif
