/*!  \brief  ProtoSpline3.cpp: Catmull-Rom spline class implementation
 ProtoSpline3.cpp
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

#include "ProtoSpline3.h"
//#include "ProtoQuaternion.h"
#include "ProtoMatrix3.h"


#include <iostream>

using namespace ijg;
//Matrix4 m;;

/**
 * Spline cubic curve class, where curve goes through all points. Curve is
 * specified by 6 points, with a constant specifying tension.
 * <p>
 */


ProtoSpline3::ProtoSpline3() {
}

// requires 4 control points to work

ProtoSpline3::ProtoSpline3(const std::vector<Vec3f>& controlPts, int interpDetail, bool isCurveClosed, float smoothness) :
ProtoCurve3(controlPts, interpDetail, isCurveClosed), smoothness(smoothness) {
    init();
}

/**
 * Calculate the interpolated curve points populating the uniqueVerts array.
 */
void ProtoSpline3::init() {
    
    
    
    // double up first and last control points
    controlPts.insert(controlPts.begin(), controlPts.at(0));
    controlPts.push_back(controlPts.at(controlPts.size() - 1));
    
    
    Vec3f v0, v1, v2, v3;
    float t2 = 0, t3 = 0;
    float step = 1.0 / (interpDetail + 1);
    
    for (int i = 0; i < controlPts.size() - 3; i++) {
        v0 = controlPts.at(i);
        v1 = controlPts.at(i + 1);
        v2 = controlPts.at(i + 2);
        v3 = controlPts.at(i + 3);
        
        
        
        for (float t = 0; t < 1; t += step) {
            t2 = t*t;
            t3 = t2*t;
            // from: http://www.mvps.org/directx/articles/catmull/
            
            
 //NOTE: something is screwy with my overloaded ops (Need to FIX)
            Vec3f v = smoothness * ((2.0f * v1) +
                    (-v0 + v2) * t +
                    (2.0f * v0 - 5.0f * v1 + 4.0f * v2 - v3) * t2 +
                    (-v0 + 3.0f * v1 - 3.0f * v2 + v3) * t3);
            verts.push_back(v);
        }
    }
    // add last control point to verts vector
    verts.push_back(controlPts.at(controlPts.size() - 2));
    
    //    for (int i = 0; i < verts.size(); i++) {
    //        std::cout << "verts.at(" << i << ") = " << verts.at(i) << std::endl;
    //    }
    /* ensure tube section don't flip */
    parallelTransport();
}

/**
 * Set flag for Curve to be closed
 * overrides
 * @param isCurveClosed
 *            boolean value
 */
void ProtoSpline3::setCurveClosed(bool isCurveClosed) {
    this->isCurveClosed = isCurveClosed;
    init();
}

/**
 * Set flag for Curve at Terminals to be continuous
 *
 * @param isTerminalSmooth
 *            boolean value
 */
void ProtoSpline3::setTerminalSmooth(bool isTerminalSmooth) {
    this->isTerminalSmooth = isTerminalSmooth;
    init();
}

/**
 * Draw the curve.
 *
 */
void ProtoSpline3::display() {
    
    glDisable(GL_CULL_FACE);
    glDisable(GL_LIGHTING);
    glLineWidth(4.0f);
    glColor3f(1, 1, 0);
    // int len = vertsLength;
    glBegin(GL_LINE_STRIP);
    glColor3f(1, 1, 0);
    //glVertex3d(controlPts.at(0).getX(), controlPts.at(0).getY(), controlPts.at(0).getZ());
    //glVertex3d(tempVecs.at(0).getX(), tempVecs.at(0).getY(), tempVecs.at(0).getZ());
    // std::cout << "controlPts.at(0) = " <<  controlPts.at(0) << std::endl;
    for (int i = 0; i < verts.size(); i++) {
        //if (verts.at(i)) {
        // std::cout <<" temp Vecs["<<i<<"] = " <<  tempVecs.at(i) << std::endl;
        glVertex3d(verts.at(i).x, verts.at(i).y, verts.at(i).z);
        //glVertex3d(tempVecs.at(i).getX(), tempVecs.at(i).getY(), tempVecs.at(i).getZ());
        //  std::cout <<" TWO:: verts["<<i<<"] = " <<  verts.at(i) << std::endl;
        //}
        if (/*verts.at(i) != null && */isCurveClosed && i == verts.size() - 1) {
            glVertex3d(verts.at(0).x, verts.at(0).y, verts.at(0).z);
        }
    }
    glEnd();
    
    
    //Start VBO's
    //    glDisable(GL_CULL_FACE);
    //    glDisable(GL_LIGHTING);
    //    glLineWidth(4.0f);
    //    glColor3f(1, 1, 0);
    //
    //    unsigned int vboID = 0;
    //    glGenBuffers(1, &vboID);
    //    glBindBuffer(GL_ARRAY_BUFFER, vboID);
    //    glBufferData(GL_ARRAY_BUFFER, sizeof(verts.size()) * 4 * sizeof(float), &verts[0], GL_STATIC_DRAW);
    //
    //    glEnableClientState(GL_VERTEX_ARRAY);
    //    glVertexPointer(3, GL_FLOAT, 0, &verts[0]);
    //
    //    glDrawArrays(GL_LINES, 0, verts.size());
    //
    //    glDisableClientState(GL_VERTEX_ARRAY);
    //
    //    glBindBuffer(GL_ARRAY_BUFFER, 0);
    //    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    
    //END VBO
}

/**
 * Draw the control points.
 *
 */
void ProtoSpline3::displayControlPts() {
    glDisable(GL_CULL_FACE);
    glDisable(GL_LIGHTING);
    glPointSize(20);
    glColor3f(.5, .5, 1.0);
    // draw points
    glBegin(GL_POINTS);
    for (int i = 0; i < controlPts.size(); i++) {
        glVertex3f(controlPts.at(i).x, controlPts.at(i).y, controlPts.at(i).z);
    }
    glEnd();
}

/**
 * Draw the interpolated points.
 *
 */
void ProtoSpline3::displayInterpPts() {
    glDisable(GL_CULL_FACE);
    glDisable(GL_LIGHTING);
    glPointSize(7);
    glColor3f(1, .5, .3);
    // draw points
    glBegin(GL_POINTS);
    for (int i = 0; i < verts.size(); i++) {
        glVertex3f(verts.at(i).x, verts.at(i).y, verts.at(i).z);
    }
    glEnd();
}

/**
 * Draw the Frenet Frames.
 *
 */
void ProtoSpline3::displayFrenetFrames(float len) {
    for (int i = 0; i < verts.size(); i++) {
        frenetFrames.at(i).display(len);
    }
}

/**
 * Draw cross-section extruded along the spline path.
 * Default cross-section is an ellipse
 */
void ProtoSpline3::drawCrossSections() {
    for (int i = 0; i < frenetFrames.size(); i++) {
        // draw cross-section ellipse
        glColor3f(1, 1, 1);
        glBegin(GL_POLYGON);
        float th = 0;
        for (int j = 0; j < 6; j++) {
            float x = cos(th)*10;
            float y = sin(th)*10;
            //float z = 0;
            float px = verts.at(i + 1).x + x * frenetFrames.at(i).getN().x + y * frenetFrames.at(i).getB().x;
            float py = verts.at(i + 1).y + x * frenetFrames.at(i).getN().y + y * frenetFrames.at(i).getB().y;
            float pz = verts.at(i + 1).z + x * frenetFrames.at(i).getN().z + y * frenetFrames.at(i).getB().z;
            glVertex3f(px, py, pz);
            th += ProtoMath::PI * 2.0 / 6.0;
        }
        glEnd();
    }
    
    glPointSize(4);
    for (int i = 0; i < frenetFrames.size(); i++) {
        // draw cross-section ellipse
        glBegin(GL_POINTS);
        float th = 0;
        for (int j = 0; j < 6; j++) {
            float x = cos(th)*10;
            float y = sin(th)*10;
            //float z = 0;
            float px = verts.at(i + 1).x + x * frenetFrames.at(i).getN().x + y * frenetFrames.at(i).getB().x;
            float py = verts.at(i + 1).y + x * frenetFrames.at(i).getN().y + y * frenetFrames.at(i).getB().y;
            float pz = verts.at(i + 1).z + x * frenetFrames.at(i).getN().z + y * frenetFrames.at(i).getB().z;
            glColor3f(0, 1 - 1 / (j + 1), 1 / (j + 1));
            glVertex3f(px, py, pz);
            th += ProtoMath::PI * 2 / 6;
        }
        glEnd();
    }
    
}

/**
 * Set the smoothenss value.
 *
 */
void ProtoSpline3::setSmoothness(float smoothness) {
    this->smoothness = smoothness;
}

/**
 * get the smoothenss value.
 *
 */
float ProtoSpline3::getSmoothness(float smoothness) const {
    return smoothness;
}

/**
 * Calculate a Frenet frame for extrusion (tubes/tendrils).
 * - private access
 */

void ProtoSpline3::parallelTransport() {
    // double up first and last verts
    //verts.insert(verts.begin(), verts.at(0));
    //verts.push_back(verts.at(verts.size() - 1));
    
    //frenetFrames.push_back(FrenetFrame(verts.at(0), Vec3f(1,0,0), Vec3f(0,-1,0), Vec3f(0,0,-1))); // add first vert
    // std::cout << "in createFrenetFrame():  verts.size() = " << verts.size() << std::endl;
    std::vector<Vec3f> tans;
    float theta = 0.0;
    Vec3f cp0, cp1, cp2;
    Vec3f tan, biNorm, norm, nextBiNorm, nextNorm;
    
    
    for (int i = 0; i < verts.size(); i++) {
        if (i == 0) {
            //cp0 = verts[verts.size() - 1];
            cp0 = verts.at(i);
            cp1 = verts.at(i);
            cp2 = verts.at(i + 1);
            
        } else if (i == verts.size() - 1) {
            cp0 = verts.at(i - 1);
            cp1 = verts.at(i);
            cp2 = verts.at(i); // 0, circled back here? changed to i
            
        } else {
            cp0 = verts.at(i - 1);
            cp1 = verts.at(i);
            cp2 = verts.at(i + 1);
            
            //std::cout << "i = = " << i << std::endl;
            //            std::cout << "cp0 " << cp0 << std::endl;
            
            //            std::cout << "cp1 " << cp1 << std::endl;
            //            std::cout << "cp2 " << cp2 << std::endl;
            //            std::cout << "cross(cp1, cp2) " << cross(cp1, cp2) << std::endl;
            //std::cout << "cp2 " << cp2 << std::endl;
        }
        // fill tangents
        tan = cp2 - cp0;
        tan.normalize();
        tans.push_back(tan);
        
        // collect initial frame
        if (i == 1) {
            // fix biNorm for parralel vectors
            biNorm = cp1.cross(cp2);
            
            // uh-oh parallel vecs
            // ! HACK ! avoids problems with orthonormal tubes.
            if (biNorm.mag() == 0) {
                
                if (cp1.x !=0 && cp2.x !=0){
                    biNorm = Vec3f(0, 1, 0);
                }
                if (cp1.y !=0 && cp2.y !=0){
                    biNorm = Vec3f(0, 0, -1);
                }
                if (cp1.z !=0 && cp2.z !=0){
                    biNorm = Vec3f(1, 0, 0);
                }
                
            }
            //std::cout << "biNorm pre = " << biNorm << std::endl;
            //std::cout << "biNorm.mag() = " << biNorm.mag() << std::endl;
            biNorm.normalize();
            //            biNorm.x = 1;
            //            biNorm.y = 0;
            //            biNorm.z = 0;
            //            std::cout << "cp1 " << cp1 << std::endl;
            //            std::cout << "cp2 " << cp2 << std::endl;
            //            std::cout << "biNorm post = " << biNorm << std::endl;
            
            norm = biNorm.cross(tan);
            norm.normalize();
        }
    }
    // rotate frame
    
    //  std::cout << "tans.size() = " << tans.size() << std::endl;
    for (int i = 0; i < tans.size() - 1; i++) {
        
        
        if (biNorm.mag() == 0) {
            nextNorm = norm;
            //frenetFrames.push_back(FrenetFrame(verts.at(i), Vec3f(1,1,1), Vec3f(1,1,1), Vec3f(1,1,1)));
            // std::cout << "norm = " << norm << std::endl;
        } else {
            theta = acos(tans.at(i).dot(tans.at(i + 1)));
            Vec3f axis = tans.at(i);
            //std::cout << "tans.at(i + 1) = " << tans.at(i + 1) << std::endl;
            //std::cout << i << std::endl;
            axis = axis.cross(tans.at(i + 1));
            //std::cout << "axis = " << axis << std::endl;
            axis.normalize();
            
            
            
            ProtoMatrix3f m;
            nextNorm = m.getRotate(theta, axis, norm);
            //std::cout << "axis = " << axis << std::endl;
            
            nextBiNorm = tans.at(i + 1);
            nextBiNorm = nextBiNorm.cross(nextNorm);
            
            
            
            // std::cout << "nextNorm = " << nextNorm << std::endl;
            // std::cout << "norm = " << norm << std::endl;
            
        }
        
        //biNorm.normalize();
        //norm.normalize();
        //        std::cout <<i<<std::endl;
        //        std::cout << "tans.at(i) = " << tans.at(i) << std::endl;
        //        std::cout << "biNorm = " << biNorm << std::endl;
        //        std::cout << "norm = " << norm << std::endl;
        frenetFrames.push_back(ProtoFrenetFrame(verts.at(i), tans.at(i), biNorm, norm));
        norm = nextNorm;
        biNorm = nextBiNorm;
        
        //std::cout << "verts = " << verts.at(i) << std::endl;
    }
    // std::cout << "in createFrenetFrame():  frenetFrames.size() = " << frenetFrames.size() << std::endl;
    
}