/*!  \brief  ProtoCurve3.cpp: Abstract base class for all curves
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

#include "ProtoCurve3.h"
#include <iostream>

using namespace ijg;

//

ProtoCurve3::ProtoCurve3() {}

ProtoCurve3::ProtoCurve3(const std::vector<Vec3f>& controlPts,int interpDetail, bool isCurveClosed):
controlPts(controlPts), interpDetail(interpDetail), isCurveClosed(isCurveClosed){
    
}

ProtoCurve3::~ProtoCurve3() {
    
}

/**
 * Set the control points.
 * with side effects
 */
void ProtoCurve3::setControlPts(std::vector<Vec3f>& controlPts) {
    this->controlPts = controlPts;
}

/**
 * Gets control points array length.
 */
int ProtoCurve3::getControlPtsLength() {
    return static_cast<int>(controlPts.size());
}

/**
 * Gets point count between control points.
 */
int ProtoCurve3::getInterpDetail(){
    return interpDetail;
}

/**
 * Get a pointer to the control points array.
 * with side effects
 */
std::vector<Vec3f>& ProtoCurve3::getControlPts() {
    return controlPts;
}


/**
 * Get the curve vertsBuff' length.
 * 
 * @return int
 */
int ProtoCurve3::getVertsLength() const  {
    return static_cast<int>(verts.size());
}

/**
 * Set all the curve points
 * 
 * @param uniqueVerts
 *            Vector[] array
 */
void ProtoCurve3::setVerts(std::vector<Vec3f> verts) {
    this->verts = verts;
    //std::cout<<"I'm in here dude!!!"<<std::endl;
}

/**
 * Get pointer all the curve points
 * 
 * @param uniqueVerts
 *            Vector array
 */
std::vector<Vec3f>& ProtoCurve3::getVerts() {
    return verts;
}


/**
 * Get a pointer to a
 * vector of all the vertices
 **** To DO NOTE - switch all verts to vector eventually ****
 */
std::vector<Vec3f>& ProtoCurve3::getVertices(){
    return tempVecs;
    //return verts;

}

/**
 * Get ProtoCurve3 object dimensions.
 * 
 * @return ProtoDimension3 object
 */
ProtoDimension3<float>& ProtoCurve3::getDimension() {
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

double ProtoCurve3::getVertRad() const  {
    return vertRad;
}

/**
 * Set vertex radius
 * 
 * @param vertRad
 *            double value
 */
void ProtoCurve3::setVertRad(double vertRad) {
    this->vertRad = vertRad;
}


/**
 * Get flag value telling if curve is closed
 * 
 * @return bool value
 */
bool ProtoCurve3::getIsCurveClosed() const  {
    return isCurveClosed;
}

/**
 * Set flag for Curve to be closed
 * 
 * @param isCurveClosed
 *            bool value
 */
void ProtoCurve3::setIsCurveClosed(bool isCurveClosed) {
    this->isCurveClosed = isCurveClosed;
}

/**
 * Get flag value telling if curve at Terminals is continuous
 * 
 * @return bool value
 */
bool ProtoCurve3::getIsTerminalSmooth() const  {
    return isTerminalSmooth;
}

/**
 * Set flag for Curve at Terminals to be continuous
 * 
 * @param isTerminalSmooth
 *            bool value
 */
void ProtoCurve3::setIsTerminalSmooth(bool isTerminalSmooth) {
    this->isTerminalSmooth = isTerminalSmooth;
}

/**
 * get Frenet Frames
 * 
 * @return Frenet Frame
 */
const std::vector<ProtoFrenetFrame>& ProtoCurve3::getFrenetFrames() const
{
    return frenetFrames;
}

