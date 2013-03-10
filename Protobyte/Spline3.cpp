//
//  Spline3.cpp
//  Protobyte Library V01
//
//  Created by Ira Greenberg on 8/2/11.
//  Copyright 2011 SMU. All rights reserved.
//

#include "Spline3.h"
//#include "Quaternion.h"
#include "Matrix3.h"

#include <iostream>

//using namespace ijg;
//Matrix4 m;;

/**
 * Spline cubic curve class, where curve goes through all points. Curve is
 * specified by 6 points, with a constant specifying tension.
 * <p>
 */



Spline3::Spline3(const std::vector<Vector3>& controlPts, int interpDetail, bool isCurveClosed, float smoothness) :
Curve3(controlPts, interpDetail, isCurveClosed), smoothness(smoothness) {
    init();
}

/**
 * Calculate the interpolated curve points populating the uniqueVerts array.
 */
void Spline3::init() {
    // double up first and last control points
    controlPts.insert(controlPts.begin(), controlPts.at(0));
    controlPts.push_back(controlPts.at(controlPts.size() - 1));

    Vector3 v0, v1, v2, v3;
    float step = 1.0 / (interpDetail + 1);
    
    for (int i = 0; i < controlPts.size() - 3; i++) {
        v0 = controlPts.at(i);
        v1 = controlPts.at(i + 1);
        v2 = controlPts.at(i + 2);
        v3 = controlPts.at(i + 3);

        for (float t = 0; t < 1; t += step) {
            // new point between vn-vn+1
            Vector3 pt = (
                    ((v0*-1) + (v1 * 3) - (v2 * 3) + v3) * (t * t * t) +
                    ((v0 * 2) - (v1 * 5) + (v2 * 4) - v3) * (t * t) +
                    ((v0*-1) + v2) * t +
                    v1 * 2) * smoothness;
            verts.push_back(pt);
        }
    }
    // add last control point to verts vector
    verts.push_back(controlPts.at(controlPts.size() - 2)); 

    //for (int i = 0; i < verts.size(); i++) {
       // std::cout << "verts.at(" << i << ") = " << verts.at(i) << std::endl;
    //}
    /* Frenet Frame for extrusion */
    createFrenetFrame();
}

/**
 * Set flag for Curve to be closed
 * overrides
 * @param isCurveClosed
 *            boolean value
 */
void Spline3::setCurveClosed(bool isCurveClosed) {
    this->isCurveClosed = isCurveClosed;
    init();
}

/**
 * Set flag for Curve at Terminals to be continuous
 *
 * @param isTerminalSmooth
 *            boolean value
 */
void Spline3::setTerminalSmooth(bool isTerminalSmooth) {
    this->isTerminalSmooth = isTerminalSmooth;
    init();
}

/**
 * Draw the curve.
 *
 */
void Spline3::display() {
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
        if (/*verts[i] != null && */isCurveClosed && i == verts.size() - 1) {
            glVertex3d(verts[0].x, verts[0].y, verts[0].z);
        }
    }
    glEnd();
}

/**
 * Draw the control points.
 *
 */
void Spline3::displayControlPts() {
    // draw points
    for (int i = 0; i < controlPts.size(); i++) {
        if (i != 0) {
            glColor3f(1, 1, 1); // enables ends points to be rendered differently
            //vertRad = 5;
        } else {
            glColor3f(1, 1, 0);
            //vertRad = 2.5;
        }
        glPushMatrix();
        glTranslatef(controlPts[i].x, controlPts[i].y, controlPts[i].z);
        glRectd(-vertRad, -vertRad, vertRad * 2, vertRad * 2);
        glPopMatrix();
    }

}

/**
 * Draw the interpolated points.
 *
 */
void Spline3::displayInterpPts() {
    glColor3f(0, 1, 1);

    // draw points
    for (int i = 0; i < verts.size(); i++) {
        glPushMatrix();
        glTranslatef(verts[i].x, verts[i].y, verts[i].z);
        glRectd(-vertRad * .5, -vertRad * .5, vertRad, vertRad);
        glPopMatrix();
    }
}

/**
 * Draw the Frenet Frames.
 *
 */
void Spline3::displayFrenetFrames(float len) {
    for (int i = 0; i < verts.size(); i++) {
        frenetFrames[i].display(len);
    }
}

/**
 * Draw cross-section extruded along the spline path.
 * Default cross-section is an ellipse
 */
void Spline3::drawCrossSections() {
    for (int i = 0; i < frenetFrames.size(); i++) {
        // draw cross-section ellipse
        glColor3f(1, 1, 1);
        glBegin(GL_POLYGON);
        float th = 0;
        for (int j = 0; j < 6; j++) {
            float x = cos(th)*10;
            float y = sin(th)*10;
            float z = 0;
            float px = verts[i + 1].x + x * frenetFrames[i].getN().x + y * frenetFrames[i].getB().x;
            float py = verts[i + 1].y + x * frenetFrames[i].getN().y + y * frenetFrames[i].getB().y;
            float pz = verts[i + 1].z + x * frenetFrames[i].getN().z + y * frenetFrames[i].getB().z;
            glVertex3f(px, py, pz);
            th += M_PI * 2.0 / 6.0;
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
            float z = 0;
            float px = verts[i + 1].x + x * frenetFrames[i].getN().x + y * frenetFrames[i].getB().x;
            float py = verts[i + 1].y + x * frenetFrames[i].getN().y + y * frenetFrames[i].getB().y;
            float pz = verts[i + 1].z + x * frenetFrames[i].getN().z + y * frenetFrames[i].getB().z;
            glColor3f(0, 1 - 1 / (j + 1), 1 / (j + 1));
            glVertex3f(px, py, pz);
            th += M_PI * 2 / 6;
        }
        glEnd();
    }

}

/**
 * Set the smoothenss value.
 *
 */
void Spline3::setSmoothness(float smoothness) {
    this->smoothness = smoothness;
}

/**
 * get the smoothenss value.
 *
 */
float Spline3::getSmoothness(float smoothness) const {
    return smoothness;
}

/**
 * Calculate a Frenet frame for extrusion (tubes/tendrils).
 * - private access
 */

void Spline3::createFrenetFrame() {
    //frenetFrames.push_back(FrenetFrame(verts[0], Vector3(1,0,0), Vector3(0,-1,0), Vector3(0,0,-1))); // add first vert
    std::cout << "in createFrenetFrame():  verts.size() = " << verts.size() << std::endl;
    std::vector<Vector3> tans;
    float theta;
    Vector3 cp0, cp1, cp2;
    Vector3 tan, biNorm, norm, nextBiNorm, nextNorm;
    for (int i = 1; i < verts.size(); i++) {

        /* if (i == 0) {
             cp0 = verts[i];
             cp1 = verts[i];
             cp2 = verts[i + 1];

         } else if (i == verts.size()) {
             cp0 = verts[i - 1];
             cp1 = verts[i];
             cp2 = verts[i];

         } else {
             cp0 = verts[i - 1];
             cp1 = verts[i];
             cp2 = verts[i + 1];
         }*/

        cp0 = verts[i - 1];
        cp1 = verts[i];
        cp2 = verts[i + 1];

        tan = cp2 - cp0;
        tan.normalize();
        tans.push_back(tan);

        if (i == 1) {

            biNorm = cp1;
            biNorm = biNorm.cross(cp2);
            biNorm.normalize();

            norm = biNorm;
            norm = norm.cross(tan);
            norm.normalize();
        }
        // std::cout << "tan = " << tan <<std::endl;
        // std::cout << "biNorm = " << biNorm <<std::endl;
        // std::cout << "norm = " << norm <<std::endl;
    }
    // rotate frame
    for (int i = 0; i < tans.size() - 1; i++) {
        if (biNorm.mag() == 0) {
            nextNorm = norm;
        } else {
            theta = acos(tans.at(i).dot(tans.at(i + 1)));
            Vector3 axis = tans.at(i);
            axis = axis.cross(tans.at(i + 1));
            axis.normalize();

            Matrix3 m;
            nextNorm = m.getRotate(theta, axis, norm);
            nextBiNorm = tans.at(i + 1);
            nextBiNorm = nextBiNorm.cross(nextNorm);

        }

        biNorm.normalize();
        norm.normalize();
        frenetFrames.push_back(FrenetFrame(verts[i], tans.at(i), biNorm, norm));
        norm = nextNorm;
        biNorm = nextBiNorm;
    }
    std::cout << "in createFrenetFrame():  frenetFrames.size() = " << frenetFrames.size() << std::endl;

}