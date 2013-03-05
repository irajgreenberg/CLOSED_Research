//
//  Curve3d.cpp
//  Protobyte Library V01
//
//  Created by Ira Greenberg on 8/2/11.
//  Copyright 2011 SMU. All rights reserved.
//

#include "Curve3d.h"
#include <iostream>

using namespace ijg;

Curve3d::Curve3d(ofVec3f controlPt0, ofVec3f controlPt1, ofVec3f controlPt2, ofVec3f controlPt3, ofVec3f controlPt4, ofVec3f controlPt5, ofVec3f controlPt6, ofVec3f controlPt7, int interpDetail, bool isCurveClosed):
controlPt0(controlPt0), controlPt1(controlPt1), controlPt2(controlPt2), controlPt3(controlPt3), controlPt4(controlPt4),controlPt5(controlPt5), controlPt6(controlPt6), controlPt7(controlPt7), interpDetail(interpDetail)
{
    
}

Curve3d::Curve3d(const std::vector<ofVec3f>& controlPts,int interpDetail, bool isCurveClosed):
controlPts(controlPts), interpDetail(interpDetail), isCurveClosed(isCurveClosed){
    
}

Curve3d::Curve3d::~Curve3d(){}


/**
 * Get the first control point.
 * 
 * @return ofVec3f object
 */
ofVec3f Curve3d::getControlPt0() const {
    return controlPt0;
}

/**
 * Set the first control point.
 * 
 * @param controlPt0
 *            ofVec3f object
 */
void Curve3d::setControlPt0(const ofVec3f& controlPt0) {
    this->controlPt0 = controlPt0;
}

/**
 * Get the second control point.
 * 
 * @return ofVec3f object
 */
ofVec3f Curve3d::getControlPt1() const  {
    return controlPt1;
}

/**
 * Set the second control point.
 * 
 * @param controlPt1
 *            ofVec3f object
 */
void Curve3d::setControlPt1(const ofVec3f& controlPt1) {
    this->controlPt1 = controlPt1;
}

/**
 * Get the third control point.
 * 
 * @return ofVec3f object
 */
ofVec3f Curve3d::getControlPt2() const  {
    return controlPt2;
}

/**
 * Set the third control point.
 * 
 * @param controlPt2
 *            ofVec3f object
 */
void Curve3d::setControlPt2(const ofVec3f& controlPt2) {
    this->controlPt2 = controlPt2;
}

/**
 * Get the fourth control point.
 * 
 * @return ofVec3f object
 */
ofVec3f Curve3d::getControlPt3() const  {
    return controlPt3;
}

/**
 * Set the fourth control point.
 * 
 * @param controlPt3
 *            ofVec3f object
 */
void Curve3d::setControlPt3(const ofVec3f& controlPt3) {
    this->controlPt3 = controlPt3;
}

/**
 * Get the fifth control point.
 * 
 * @return ofVec3f object
 */
ofVec3f Curve3d::getControlPt4() const  {
    return controlPt4;
}

/**
 * Set the fifth control point.
 * 
 * @param controlPt4
 *            ofVec3f object
 */
void Curve3d::setControlPt4(const ofVec3f& controlPt4) {
    this->controlPt4 = controlPt4;
}

/**
 * Get the sixth control point.
 * 
 * @return ofVec3f object
 */
ofVec3f Curve3d::getControlPt5() const  {
    return controlPt5;
}

/**
 * Set the sixth control point.
 * 
 * @param controlPt5
 *            ofVec3f object
 */
void Curve3d::setControlPt5(const ofVec3f& controlPt5) {
    this->controlPt5 = controlPt5;
}

/**
 * Get the seventh control point.
 * 
 * @return ofVec3f object
 */
ofVec3f Curve3d::getControlPt6() const  {
    return controlPt6;
}

/**
 * Set the seventh control point.
 * 
 * @param controlPt6
 *            ofVec3f object
 */
void Curve3d::setControlPt6(const ofVec3f& controlPt6) {
    this->controlPt6 = controlPt6;
}

/**
 * Get the eighth control point.
 * 
 * @return ofVec3f object
 */
ofVec3f Curve3d::getControlPt7() const  {
    return controlPt7;
}

/**
 * Set the eighth control point.
 * 
 * @param controlPt7
 *            ofVec3f object
 */
void Curve3d::setControlPt7(const ofVec3f& controlPt7) {
    this->controlPt7 = controlPt7;
}


/**
 * Set the control points.
 * with side effects
 */
void Curve3d::setControlPts(std::vector<ofVec3f>& controlPts) {
    this->controlPts = controlPts;
}

/**
 * Gets control points array length.
 */
int Curve3d::getControlPtsLength() {
    return controlPts.size();
}

/**
 * Gets point count between control points.
 */
int Curve3d::getInterpDetail(){
    return interpDetail;
}

/**
 * Get a pointer to the control points array.
 * with side effects
 */
std::vector<ofVec3f>& Curve3d::getControlPts() {
    return controlPts;
}


/**
 * Get the curve vertsBuff' length.
 * 
 * @return int
 */
int Curve3d::getVertsLength() const  {
    return verts.size();
}

/**
 * Set all the curve points
 * 
 * @param uniqueVerts
 *            Vector[] array
 */
void Curve3d::setVerts(std::vector<ofVec3f> verts) {
    this->verts = verts;
    //std::cout<<"I'm in here dude!!!"<<std::endl;
}

/**
 * Get pointer all the curve points
 * 
 * @param uniqueVerts
 *            Vector array
 */
const vector<ofVec3f>& Curve3d::getVerts() {
    return verts;
}


/**
 * Get a pointer to a
 * vector of all the vertices
 **** To DO NOTE - switch all verts to vector eventually ****
 */
std::vector<ofVec3f>& Curve3d::getVertices(){
    return tempVecs;
    //return verts;

}

/**
 * Get Curve3d object dimensions.
 * 
 * @return Dimension3D object
 */
Dimension3D& Curve3d::getDimension() {
    double minX=0, maxX=0, minY=0, maxY=0, minZ=0, maxZ=0.0;
    minX = verts[0].x;
    maxX = verts[verts.size()-1].x;
    minY = verts[0].y;
    maxY = verts[verts.size()-1].y;
    minZ = verts[0].z;
    maxZ = verts[verts.size()-1].z;
    
    for(int i=1; i<verts.size(); i++){
        minX = minX < verts[i].x ? minX : verts[i].x;
        maxX = maxX > verts[i].x ? maxX : verts[i].x;
        
        minY = minY < verts[i].y ? minY : verts[i].y;
        maxY = maxY > verts[i].y ? maxY : verts[i].y;
        
        minZ = minZ < verts[i].z ? minZ : verts[i].z;
        maxZ = maxZ > verts[i].z ? maxZ : verts[i].z;
    }
    dim.w = maxX-minX;
    dim.h = maxY-minY;
    dim.d = maxZ-minZ;
    return dim;
}

/**
 * Get vertex radius.
 * 
 * @return double value
 */

double Curve3d::getVertRad() const  {
    return vertRad;
}

/**
 * Set vertex radius
 * 
 * @param vertRad
 *            double value
 */
void Curve3d::setVertRad(double vertRad) {
    this->vertRad = vertRad;
}


/**
 * Get flag value telling if curve is closed
 * 
 * @return bool value
 */
bool Curve3d::getIsCurveClosed() const  {
    return isCurveClosed;
}

/**
 * Set flag for Curve to be closed
 * 
 * @param isCurveClosed
 *            bool value
 */
void Curve3d::setIsCurveClosed(bool isCurveClosed) {
    this->isCurveClosed = isCurveClosed;
}

/**
 * Get flag value telling if curve at Terminals is continuous
 * 
 * @return bool value
 */
bool Curve3d::getIsTerminalSmooth() const  {
    return isTerminalSmooth;
}

/**
 * Set flag for Curve at Terminals to be continuous
 * 
 * @param isTerminalSmooth
 *            bool value
 */
void Curve3d::setIsTerminalSmooth(bool isTerminalSmooth) {
    this->isTerminalSmooth = isTerminalSmooth;
}

/**
 * get Frenet Frame
 * 
 * @return Frenet Frame
 */
const std::vector<FrenetFrame>& Curve3d::getFrenetFrame() const
{
    return frenetFrames;
}

