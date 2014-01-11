/*!  \brief  ProtoCamera.cpp: (add brief description)
 ProtoCamera.cpp
 Protobyte Library v02
 
 Created by Ira on 7/25/13.
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

#include "ProtoCamera.h"

using namespace ijg;

// inialize static counter
unsigned char ProtoCamera::static_camera_count = 0;


// cstrs

ProtoCamera::ProtoCamera():
pos(Vec3f(0, 0, 1.9)), rot(Vec3f(0, 0, 0)){
    static_camera_count++;
    uniqueID = static_camera_count;
}

ProtoCamera::ProtoCamera(const Vec3f& pos, const Vec3f& rot):
pos(pos), rot(rot)
{
    static_camera_count++;
    uniqueID = static_camera_count;
}

ProtoCamera::ProtoCamera(const Vec3f& pos, const Vec3f& rot, const ProtoBoundsf& bounds):
pos(pos), rot(rot), bounds(bounds)
{
    static_camera_count++;
    uniqueID = static_camera_count;
}

ProtoCamera::ProtoCamera(const Vec3f& pos, const Vec3f& rot, const ProtoBoundsf& bounds, float fovAngle, float aspectRatio, float nearClipPlane, float farClipPlane):
pos(pos), rot(rot), bounds(bounds), fovAngle(fovAngle), aspectRatio(aspectRatio), nearClipPlane(nearClipPlane), farClipPlane(farClipPlane)
{
    static_camera_count++;
    uniqueID = static_camera_count;
}

ProtoCamera::ProtoCamera(const Vec3f& pos, const Vec3f& rot, const ProtoBoundsf& bounds, float frustumVals[4]): pos(pos), rot(rot), bounds(bounds), fovAngle(frustumVals[0]), aspectRatio(frustumVals[1]), nearClipPlane(frustumVals[2]), farClipPlane(frustumVals[3])
{
    static_camera_count++;
    uniqueID = static_camera_count;
}

ProtoCamera::ProtoCamera(float fovAngle, float aspectRatio, float nearClipPlane, float farClipPlane): fovAngle(fovAngle), aspectRatio(aspectRatio), nearClipPlane(nearClipPlane), farClipPlane(farClipPlane)
{
    static_camera_count++;
    uniqueID = static_camera_count;
}

ProtoCamera::ProtoCamera(float frustumVals[4]):
fovAngle(frustumVals[0]), aspectRatio(frustumVals[1]), nearClipPlane(frustumVals[2]), farClipPlane(frustumVals[3])

{
    static_camera_count++;
    uniqueID = static_camera_count;
}




// dstr
ProtoCamera::~ProtoCamera() {
    
}

void ProtoCamera::project(){
//    std::cout << "in camera init" << std::endl;
//    std::cout << "fovAngle " << fovAngle <<std::endl;
//    std::cout << "aspectRatio " << aspectRatio << std::endl;
//    std::cout << "nearClipPlane " << nearClipPlane << std::endl;
//    std::cout << "farClipPlane " << farClipPlane << std::endl;
    
    
    // make projection matrix active
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // set the viewport
    // controls what part of window is painted to. Can be called multiple times
    // for split screen
    glViewport(viewPort.x, viewPort.y, viewPort.w, viewPort.h);
    
    // from http://nehe.gamedev.net/article/replacement_for_gluperspective/21002/
    // replaces gluPerspective(fovAngle, aspectRatio, nearClipPlane, farClipPlane);
    
    // gl uses degrees
    float fh = tan( fovAngle / 360 * ProtoMath::PI ) * nearClipPlane;
    float fw = fh * aspectRatio;
    
    glFrustum(-fw, fw, -fh, fh, nearClipPlane, farClipPlane);
    
    //glMatrixMode(GL_MODELVIEW);
    //glLoadIdentity();
    glTranslatef(-pos.x, -pos.y, -pos.z);
    glRotatef(-rot.x, 1, 0, 0);
    glRotatef(-rot.y, 0, 1, 0);
    glRotatef(-rot.z, 0, 0, 1);
    //gluPerspective(fovAngle, aspectRatio, nearClipPlane, farClipPlane);
    
}

void ProtoCamera::setProjection(float fovAngle, float aspectRatio, float nearClipPlane, float farClipPlane) {
    this->fovAngle = fovAngle;
    this->aspectRatio = aspectRatio;
    this->nearClipPlane = nearClipPlane;
    this->farClipPlane = farClipPlane;
}

void ProtoCamera::setViewPort(float x, float y, float w, float h) {
    viewPort.x = x;
    viewPort.y = y;
    viewPort.w = w;
    viewPort.h = h;
}



