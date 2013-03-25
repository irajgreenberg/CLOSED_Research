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


Spline3::Spline3() {}


Spline3::Spline3(const std::vector<Vector3>& controlPts, int interpDetail, bool isCurveClosed, float smoothness) :
Curve3(controlPts, interpDetail, isCurveClosed), smoothness(smoothness) {
    init();
}

/**
 * Calculate the interpolated curve points populating the uniqueVerts array.
 */
void Spline3::init() {
    for (int i = 0; i < controlPts.size(); i++) {
        //std::cout << "pre: controlPts.at(" << i << ") = " << controlPts.at(i) << std::endl;
    }


    // double up first and last control points
    controlPts.insert(controlPts.begin(), controlPts.at(0));
    controlPts.push_back(controlPts.at(controlPts.size() - 1));

    /*
    // add begin and end points based on vectors v1-v0 and v(n-1)-vn
    Vector3 delta = controlPts.at(1);
    delta -= controlPts.at(0);
    Vector3 newVec = controlPts.at(0) - delta;
    controlPts.insert(controlPts.begin(), newVec);

    delta = controlPts.at(controlPts.size() - 2);
    delta -= controlPts.at(controlPts.size() - 1);
    newVec = controlPts.at(controlPts.size() - 1) - delta;
    controlPts.push_back(newVec);
     */

    for (int i = 0; i < controlPts.size(); i++) {
        //std::cout << "Post: controlPts.at(" << i << ") = " << controlPts.at(i) << std::endl;
    }

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

    for (int i = 0; i < verts.size(); i++) {
        //  std::cout << "verts.at(" << i << ") = " << verts.at(i) << std::endl;
    }
    /* ensure tube section don't flip */
    parallelTransport();
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
        glTranslatef(controlPts.at(i).x, controlPts.at(i).y, controlPts.at(i).z);
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
        glTranslatef(verts.at(i).x, verts.at(i).y, verts.at(i).z);
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
        frenetFrames.at(i).display(len);
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
            float px = verts.at(i+1).x + x * frenetFrames.at(i).getN().x + y * frenetFrames.at(i).getB().x;
            float py = verts.at(i+1).y + x * frenetFrames.at(i).getN().y + y * frenetFrames.at(i).getB().y;
            float pz = verts.at(i+1).z + x * frenetFrames.at(i).getN().z + y * frenetFrames.at(i).getB().z;
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
            float px = verts.at(i+1).x + x * frenetFrames.at(i).getN().x + y * frenetFrames.at(i).getB().x;
            float py = verts.at(i+1).y + x * frenetFrames.at(i).getN().y + y * frenetFrames.at(i).getB().y;
            float pz = verts.at(i+1).z + x * frenetFrames.at(i).getN().z + y * frenetFrames.at(i).getB().z;
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

void Spline3::parallelTransport() {
    // double up first and last verts
    //verts.insert(verts.begin(), verts.at(0));
    //verts.push_back(verts.at(verts.size() - 1));

    //frenetFrames.push_back(FrenetFrame(verts.at(0), Vector3(1,0,0), Vector3(0,-1,0), Vector3(0,0,-1))); // add first vert
   // std::cout << "in createFrenetFrame():  verts.size() = " << verts.size() << std::endl;
    std::vector<Vector3> tans;
    float theta;
    Vector3 cp0, cp1, cp2;
    Vector3 tan, biNorm, norm, nextBiNorm, nextNorm;


    for (int i = 1; i < verts.size()-1; i++) {
        if (i == 0) {
            cp0 = verts[verts.size()-1];
            cp1 = verts.at(i);
            cp2 = verts.at(i+1);
        } else if (i == verts.size() - 1) {
            cp0 = verts.at(i-1);
            cp1 = verts.at(i);
            cp2 = verts.at(0);
        } else {
            cp0 = verts.at(i-1);
            cp1 = verts.at(i);
            cp2 = verts.at(i+1);
        }
        // fill tangents
        tan = cp2 - cp0;
        tan.normalize();
        tans.push_back(tan);

        // collect initial frame
        if (i == 1) {
            biNorm = cp1.cross(cp2);
            biNorm.normalize();

            norm = biNorm.cross(tan);
            norm.normalize();
        }
    }
    // rotate frame

  //  std::cout << "tans.size() = " << tans.size() << std::endl;
    for (int i = 0; i < tans.size() - 1; i++) {
        if (biNorm.mag() == 0) {
          //  std::cout << "in HERE " << std::endl;
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

        //biNorm.normalize();
        //norm.normalize();
        frenetFrames.push_back(FrenetFrame(verts.at(i), tans.at(i), biNorm, norm));
        norm = nextNorm;
        biNorm = nextBiNorm;
    }
   // std::cout << "in createFrenetFrame():  frenetFrames.size() = " << frenetFrames.size() << std::endl;

}