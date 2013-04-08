//
//  Curve3.cpp
//  Protobyte Library V01
//
//  Created by Ira Greenberg on 8/2/11.
//  Copyright 2011 SMU. All rights reserved.
//

#include "Curve3.h"
#include <iostream>

using namespace proto;

//

Curve3::Curve3() {}

Curve3::Curve3(const std::vector<Vector3>& controlPts,int interpDetail, bool isCurveClosed):
controlPts(controlPts), interpDetail(interpDetail), isCurveClosed(isCurveClosed){
    
}

Curve3::~Curve3() {
    
}

/**
 * Set the control points.
 * with side effects
 */
void Curve3::setControlPts(std::vector<Vector3>& controlPts) {
    this->controlPts = controlPts;
}

/**
 * Gets control points array length.
 */
int Curve3::getControlPtsLength() {
    return controlPts.size();
}

/**
 * Gets point count between control points.
 */
int Curve3::getInterpDetail(){
    return interpDetail;
}

/**
 * Get a pointer to the control points array.
 * with side effects
 */
std::vector<Vector3>& Curve3::getControlPts() {
    return controlPts;
}


/**
 * Get the curve vertsBuff' length.
 * 
 * @return int
 */
int Curve3::getVertsLength() const  {
    return verts.size();
}

/**
 * Set all the curve points
 * 
 * @param uniqueVerts
 *            Vector[] array
 */
void Curve3::setVerts(std::vector<Vector3> verts) {
    this->verts = verts;
    //std::cout<<"I'm in here dude!!!"<<std::endl;
}

/**
 * Get pointer all the curve points
 * 
 * @param uniqueVerts
 *            Vector array
 */
std::vector<Vector3>& Curve3::getVerts() {
    return verts;
}


/**
 * Get a pointer to a
 * vector of all the vertices
 **** To DO NOTE - switch all verts to vector eventually ****
 */
std::vector<Vector3>& Curve3::getVertices(){
    return tempVecs;
    //return verts;

}

/**
 * Get Curve3 object dimensions.
 * 
 * @return Dimension3 object
 */
Dimension3<float>& Curve3::getDimension() {
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

double Curve3::getVertRad() const  {
    return vertRad;
}

/**
 * Set vertex radius
 * 
 * @param vertRad
 *            double value
 */
void Curve3::setVertRad(double vertRad) {
    this->vertRad = vertRad;
}


/**
 * Get flag value telling if curve is closed
 * 
 * @return bool value
 */
bool Curve3::getIsCurveClosed() const  {
    return isCurveClosed;
}

/**
 * Set flag for Curve to be closed
 * 
 * @param isCurveClosed
 *            bool value
 */
void Curve3::setIsCurveClosed(bool isCurveClosed) {
    this->isCurveClosed = isCurveClosed;
}

/**
 * Get flag value telling if curve at Terminals is continuous
 * 
 * @return bool value
 */
bool Curve3::getIsTerminalSmooth() const  {
    return isTerminalSmooth;
}

/**
 * Set flag for Curve at Terminals to be continuous
 * 
 * @param isTerminalSmooth
 *            bool value
 */
void Curve3::setIsTerminalSmooth(bool isTerminalSmooth) {
    this->isTerminalSmooth = isTerminalSmooth;
}

/**
 * get Frenet Frame
 * 
 * @return Frenet Frame
 */
const std::vector<FrenetFrame>& Curve3::getFrenetFrame() const
{
    return frenetFrames;
}

