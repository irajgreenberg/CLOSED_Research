//
//  Spline3d.cpp
//  Protobyte Library V01
//
//  Created by Ira Greenberg on 8/2/11.
//  Copyright 2011 SMU. All rights reserved.
//

#include "Spline3d.h"
#include "Quaternion.h"
#include "Matrix3D.h"

#include <iostream>

using namespace ijg;
//Matrix3D m;;

/**
 * Spline cubic curve class, where curve goes through all points. Curve is
 * specified by 6 points, with a constant specifying tension.
 * <p>
 */


Spline3d::Spline3d(ofVec3f controlPt0, ofVec3f controlPt1, ofVec3f controlPt2, ofVec3f controlPt3, ofVec3f controlPt4, ofVec3f controlPt5, ofVec3f controlPt6, ofVec3f controlPt7, int interpDetail, bool isCurveClosed, float smoothness):
Curve3d(controlPt0, controlPt1, controlPt2, controlPt3, controlPt4,controlPt5, controlPt6, controlPt7, interpDetail), smoothness(smoothness)
{
    // init();
}

Spline3d::Spline3d(const std::vector<ofVec3f>& controlPts,int interpDetail, bool isCurveClosed, float smoothness):
Curve3d(controlPts, interpDetail, isCurveClosed), smoothness(smoothness){
    init();
}



/**
 * Calculate the interpolated curve points populating the uniqueVerts array.
 */
void Spline3d::init() {


    // std::cout<< "In Spline3d init method"<< std::endl;
    int len = 0;
    if(isCurveClosed){
        len = (controlPts.size())*interpDetail;
    } else {
        len =(controlPts.size()-1)*interpDetail;
    }
    vertRad = 5;
    
    // detect if curve should be closed
    if (isCurveClosed) {
        for (int i = 0; i < controlPts.size(); i++) {
            //tempVecs.push_back(controlPts[i]);
            //std::cout<< "controlPts["<<i<<"] = " << controlPts[i] << std::endl;
            ofVec3f t1;
            ofVec3f t2;
            // equation to calculate spline tangents
            // Ti = tension * ( Pi+1 - Pi-1 )
            
            // tangent 1 (i)
            // Pi+1
            if (i < controlPts.size()-1) {
                t1 = controlPts[i + 1];
            } else {
                t1 = controlPts[0];
            }
            // Pi-1
            if (i > 0) {
                t1 -= controlPts[i - 1];
            } else {
                // if i==0, subtract last point as pi-i to form smooth curve back in
                t1 -= controlPts[controlPts.size() - 1];
            }
            t1 *= smoothness;
            
            
            // tangent 2 (i+1)
            // Pi+1
            if (i < controlPts.size() - 2) {
                t2 = controlPts[i + 2];
                //t2.sub(controlPts[i]);
            } else if (i == controlPts.size() - 2){
                t2 = controlPts[0];
            } else {
                t2 = controlPts[1];
            }
            // Pi-1
            t2 -= controlPts[i];
            t2 *= smoothness;
            
            //std::cout <<"t1 = " << t1 << std::endl;
            //std::cout <<"t2 = " << t2 << std::endl;
            
            // 1st plot control points
            tempVecs.push_back(controlPts[i]);
            
            // 2nd plot interpolated points
            for (int t = 1; t < interpDetail + 1; t++) {
                // std::cout <<"interpDetail = " << interpDetail << std::endl;
                // scale between 0.0-1.0
                double s = t / (double) (interpDetail+1);
                //std::cout <<"s = " << s << std::endl;
                // calculate basis functions
                // for controls
                double h1 = 2.0 * s * s * s - 3.0 * s * s + 1.0; // y = 2s^3 - 3s^2 + 1, y' = 6s^2 - 6s
                double h2 = -2.0 * s * s * s + 3.0 * s * s; // y = -2s^3 - 3s^2, y' = -6s^2 - 6s
                // for tangents
                double h3 = s * s * s - 2.0 * s * s + s; // y = s^3 - 2s^3, y' = s^2 - 6s^2
                double h4 = s * s * s - s * s; // y = s^3 - s^2, y' = 3s^2 - 2s
                
                // create temporary vector
                ofVec3f tempVec;
                tempVec = controlPts[i]; // p0
                tempVec *= h1;
                if (i<controlPts.size()-1){
                    tempVec += (controlPts[i + 1] * h2); // p3
                } else {
                    // final node
                    tempVec += (controlPts[0] * h2); // p3
                }
                // tangent 1
                tempVec += (t1 * h3); // p1
                // tangent 2
                tempVec += (t2 * h4); // p2
                tempVecs.push_back(tempVec);
            }
        }
        // smooth curves at end of paths
    } else if (isTerminalSmooth) {
        std::cout <<"Inside isTerminalSmooth block" << std::endl;
        for (int i = 0; i < controlPts.size()-1; i++) {
            // ONLY add inital control point to vertex list
            if(i==0)  { tempVecs.push_back(controlPts[i]); }
            
            ofVec3f t1, t2;
            // equation to calculate spline tangents
            // Ti = a * ( Pi+1 - Pi-1 )
            
            // tangent 1 (i)
            // Pi+1
            if (i < controlPts.size()-1) {
                t1 = controlPts[i + 1];
            } else {
                //uses 1st CP to control curvature on last point
                t1 = controlPts[0];
            }
            // Pi-1
            if (i > 0) {
                t1 -= controlPts[i - 1];
            } else {
                // if i==0, subtract last point as pi-i to form smooth curve back in
                t1 -= controlPts[controlPts.size() - 1];
            }
            t1 *= smoothness;
            
            // tangent 2 (i+1)
            // Pi+1
            if (i < controlPts.size() - 2) {
                t2 = controlPts[i + 2];
            } else if (i == controlPts.size() - 2){
                //uses 1st CP to control curvature on last point
                t2 = controlPts[0];
            } else {
                //uses 2nd CP to control curvature on last point
                t2 = controlPts[1];
            }
            // Pi-1
            t2 -= controlPts[i];
            t2 *= smoothness;
            
            //std::cout << "control point "<< i << " = " << controlPts[i] << std::endl;
            // FIXED 8/9/10 to allow symmetry on curve
            // ADDED 10/15/12 "<=" was "<"  - creates interpolated
            // point at control point, allowing derivatives to be calculated
            // for Frenet Frame (not sure I really need this once I get
            // parralel transport implemented - oh well...
            for (int t = 1; t <= interpDetail+1; t++) { /*fixed*/
                // scale between 0.0-1.0
                double s = t / (double) (interpDetail+1 /*fixed*/);
                // std::cout <<"s = " << s << std::endl;
                // calculate basis functions
                // for controls
                double h1 = 2.0 * s * s * s - 3.0 * s * s + 1.0; // 2*s^3 - 3*s^2 + 1
                double h2 = -2.0 * s * s * s + 3.0 * s * s; // -2*s^3 + 3*s^2
                // for tangents
                double h3 = s * s * s - 2.0 * s * s + s; // s^3 - 2*s^2 + s
                double h4 = s * s * s - s * s; // s^3 - s^2
                
                // create temporary vector
                ofVec3f tempVec, tempVec2, T, B, N;
                tempVec = controlPts[i]; // p0
                tempVec *= h1;
                if (i<controlPts.size()-1){ // NOT at end of curve
                    tempVec += (controlPts[i + 1]*h2); // p3
                } else {
                    // end of curve
                    tempVec+= (controlPts[0] * h2); // p3
                }
                // tangent 1
                tempVec += (t1 * h3); // p1
                // tangent 2
                tempVec += (t2 * h4); // p2
                
                //std::cout << "tempVec "<< t << " = " << tempVec << std::endl;
                tempVecs.push_back(tempVec);

                
            }
        }
        // add last control point to tempVecs
        //tempVecs.push_back(controlPts[controlPts.size() - 1]);
        // curve smoothness terminates at end of path
    } else {
        /******************************************/
        /***********NOT WORKING BELOW HERE*********/
        /******************************************/
        std::cout << "in Spline3d catch all else" << std::endl;
        for (int i = 0; i < controlPts.size() - 1; i++) {
            tempVecs.push_back(controlPts[i]);
            ofVec3f t1;
            ofVec3f t2;
            // equation to calculate spline tangents
            // Ti = a * ( Pi+1 - Pi-1 )
            
            // tangent 1 (i)
            // Pi+1
            t1 = controlPts[i + 1];
            // Pi-1
            if (i > 0) {
                t1 -= controlPts[i - 1];
            } else {
                t1 -= controlPts[i];
            }
            t1 *= smoothness;
            
            // tangent 2 (i+1)
            // Pi+1
            if (i < controlPts.size() - 2) {
                t2 = controlPts[i + 2];
                
                // Pi-1
                t2 -= controlPts[i];
            } else {
                t2 = controlPts[i + 1];
                
                // Pi-1
                t2 -= controlPts[i];
            }
            
            t2 *= smoothness;
            
            for (int t = 1; t < interpDetail+1; t++) {
                // scale between 0.0-1.0
                double s = t / (double) (interpDetail+1);
                // calculate basis functions
                // for controls
                double h1 = 2.0 * s * s * s - 3.0 * s * s + 1.0; // 2*s^3-3*s^2 + 1
                double h2 = -2.0 * s * s * s + 3.0 * s * s; // -2*s^3-3*s^2
                // for tangents
                double h3 = s * s * s - 2.0 * s * s + s; // s^3-2*s^3
                double h4 = s * s * s - s * s; // s^3 - s^2
                
                // 1st derivative for Frenet frame
                double y1 = 6.0 * s * s - 6.0 * s; // 6*s^2-6*s
                double y2 = -4.0 * s * s + 6.0 * s; // -6*s^2+6*s
                // for tangents
                double y3 = 3 * s * s - 6.0 * s * s; // 3s^2-6*s^2
                double y4 = 3 * s * s - s; // 3s^2 - s
                
                // 2nd derivative for Frenet frame
                double yy1 = 12.0 * s - 6.0; // 12*s-6
                double yy2 = -8.0 * s + 6.0; // -8*s+6
                // for tangents
                double yy3 = 6 * s - 12.0 * s; // 6s-12
                double yy4 = 6 * s; // 6s
                
                // create temporary vector
                ofVec3f tempVec, tempVec2, T, B, N;
                
                // calculate vertex
                tempVec = controlPts[i]; // p0
                tempVec *= h1;
                tempVec += (controlPts[i + 1] * h2); // p3
                // tangent 1
                tempVec += (t1 * h3); // p1
                // tangent 2
                tempVec += (t2 * h4); // p2
                tempVecs.push_back(tempVec);
                //std::cout << "tempVec "<< t << " = " << tempVec << std::endl;

            }
        }
        
        // add last control point to tempVecs DOESN'T SEEM NECESSARY ANY MORE
        // tempVecs.push_back(controlPts[controlPts.size() - 1]); // not needed
        
    }
    // copy array vals to verts array - NOTE: not efficient to do this.
    //verts = new ofVec3f[tempVecs.size()];
    for (int i = 0; i < tempVecs.size(); i++) {
        verts.push_back(tempVecs[i]);
        if (i==0){  std::cout << "\n****VERTS****" << std::endl; }
        //std::cout <<"verts["<<i<<"] = " <<  verts[i] << std::endl;
    }
    
    /******* Create Frenet Frame for extrusion *****/
    createFrenetFrame();
}

/**
 * Set flag for Curve to be closed
 * overrides
 * @param isCurveClosed
 *            boolean value
 */
void Spline3d::setCurveClosed(bool isCurveClosed) {
    this->isCurveClosed = isCurveClosed;
    init();
}

/**
 * Set flag for Curve at Terminals to be continuous
 *
 * @param isTerminalSmooth
 *            boolean value
 */
void Spline3d::setTerminalSmooth(bool isTerminalSmooth) {
    this->isTerminalSmooth = isTerminalSmooth;
    init();
}

/**
 * Draw the curve.
 *
 */
void Spline3d::display() {
    // int len = vertsLength;
    glBegin(GL_LINE_STRIP);
    glColor3f(1, 1, 0);
    //glVertex3d(controlPts[0].getX(), controlPts[0].getY(), controlPts[0].getZ());
    //glVertex3d(tempVecs[0].getX(), tempVecs[0].getY(), tempVecs[0].getZ());
    // std::cout << "controlPts[0] = " <<  controlPts[0] << std::endl;
    for (int i = 0; i < verts.size(); i++) {
        //if (verts[i]) {
        // std::cout <<" temp Vecs["<<i<<"] = " <<  tempVecs[i] << std::endl;
        glVertex3d(verts[i].x, verts[i].y, verts[i].z);
        //glVertex3d(tempVecs[i].getX(), tempVecs[i].getY(), tempVecs[i].getZ());
        //  std::cout <<" TWO:: verts["<<i<<"] = " <<  verts[i] << std::endl;
        //}
        if (/*verts[i] != null && */isCurveClosed && i == verts.size()-1) {
            glVertex3d(verts[0].x, verts[0].y, verts[0].z);
        }
    }
    glEnd();
}

/**
 * Draw the control points.
 *
 */
void Spline3d::displayControlPts() {
    // draw points
    for (int i = 0; i < controlPts.size(); i++) {
        if (i != 0) {
            glColor3f(1, 1, 1);  // enables ends points to be rendered differently
            //vertRad = 5;
        } else {
            glColor3f(1, 1, 0);
            //vertRad = 2.5;
        }
        glPushMatrix();
        glTranslatef(controlPts[i].x, controlPts[i].y, controlPts[i].z);
        glRectd(- vertRad,  -vertRad,  vertRad*2, vertRad*2);
        glPopMatrix();
    }
    
}

/**
 * Draw the interpolated points.
 *
 */
void Spline3d::displayInterpPts()
{
    glColor3f(0, 1, 1);
    
    // draw points
    for (int i = 0; i < verts.size(); i++) {
        glPushMatrix();
        glTranslatef(verts[i].x, verts[i].y, verts[i].z);
        glRectd(- vertRad*.5,  -vertRad*.5,  vertRad, vertRad);
        glPopMatrix();
    }
}

/**
 * Draw the Frenet Frames.
 *
 */
void Spline3d::displayFrenetFrames(float len)
{
    for (int i = 0; i <verts.size(); i++) {
        frenetFrames[i].display(len);
    }
}

/**
 * Draw cross-section extruded along the spline path.
 * Default cross-section is an ellipse
 */
void Spline3d::drawCrossSections(){
    for (int i = 0; i <frenetFrames.size(); i++) {
        // draw cross-section ellipse
        glColor3f(1, 1, 1);
        glBegin(GL_POLYGON);
        float th = 0;
        for(int j=0; j<6; j++){
            float x = cos(th)*10;
            float y = sin(th)*10;
            float z = 0;
            float px = verts[i+1].x + x*frenetFrames[i].getN().x + y*frenetFrames[i].getB().x;
            float py = verts[i+1].y + x*frenetFrames[i].getN().y + y*frenetFrames[i].getB().y;
            float pz = verts[i+1].z + x*frenetFrames[i].getN().z + y*frenetFrames[i].getB().z;
            glVertex3f(px, py, pz);
            th += PI*2/6;
        }
        glEnd();
    }
    
    glPointSize(4);
    for (int i = 0; i <frenetFrames.size(); i++) {
        // draw cross-section ellipse
        glBegin(GL_POINTS);
        float th = 0;
        for(int j=0; j<6; j++){
            float x = cos(th)*10;
            float y = sin(th)*10;
            float z = 0;
            float px = verts[i+1].x + x*frenetFrames[i].getN().x + y*frenetFrames[i].getB().x;
            float py = verts[i+1].y + x*frenetFrames[i].getN().y + y*frenetFrames[i].getB().y;
            float pz = verts[i+1].z + x*frenetFrames[i].getN().z + y*frenetFrames[i].getB().z;
            glColor3f(0, 1-1/(j+1), 1/(j+1));
            glVertex3f(px, py, pz);
            th += PI*2/6;
        }
        glEnd();
    }
    
}

/**
 * Set the smoothenss value.
 *
 */
void Spline3d::setSmoothness(float smoothness)
{
    this->smoothness = smoothness;
}

/**
 * get the smoothenss value.
 *
 */
float Spline3d::getSmoothness(float smoothness) const
{
    return smoothness;
}

/**
 * Calculate a Frenet frame for extrusion (tubes/tendrils).
 * - private access
 */

void Spline3d::createFrenetFrame()
{
    std::vector<ofVec3f> tans;
    float theta;
    ofVec3f cp0, cp1, cp2;
    ofVec3f tan, biNorm, norm, nextBiNorm, nextNorm;
    for (int i = 1; i <verts.size(); i++) {
        
        cp0 = verts[i-1];
        cp1 = verts[i];
        cp2 = verts[i+1];
        
        tan = cp2 - cp0;
        tan.normalize();
        tans.push_back(tan);
            
        if (i==1){
            
            biNorm = cp1;
            biNorm.cross(cp2);
            biNorm.normalize();
            
            norm = biNorm;
            norm.cross(tan);
            norm.normalize();
        }
              // std::cout << "tan = " << tan <<std::endl;
               // std::cout << "biNorm = " << biNorm <<std::endl;
               // std::cout << "norm = " << norm <<std::endl;
    }
    // rotate frame
    for (int i = 0; i <tans.size()-1; i++) {
        if (biNorm.length() == 0) {
            nextNorm = norm;
        } else {
            theta = acos(tans.at(i).dot(tans.at(i+1)));
            ofVec3f axis = tans.at(i);
            axis.cross(tans.at(i+1));
            axis.normalize();
         
            Matrix3D m;
            nextNorm = m.getRotate(theta, axis, norm);
            nextBiNorm = tans.at(i+1);
            nextBiNorm.cross(nextNorm);

        }
        frenetFrames.push_back(FrenetFrame(verts[i], tans.at(i), biNorm.normalize(), norm.normalize()));
        norm = nextNorm;
        biNorm = nextBiNorm;
    }
    
}



