/*!  \brief  ProtoCamera.h: (add brief description)
 ProtoCamera.h
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

#ifndef Protobyte_v02_ProtoCamera_cpp
#define Protobyte_v02_ProtoCamera_cpp

#ifdef _WIN32
#include <GL/glew.h>
#endif

#include <iostream>
#include <SFML/OpenGL.hpp>
#include <stdio.h>
#include "ProtoMath.h"
#include "ProtoBounds.h"
#include "ProtoVector3.h"
#include <string>


namespace ijg {
    
    class ProtoCamera {
        
    public:
//        enum RenderMode {
//            POINT_CLOUD,
//            WIREFRAME,
//            SURFACE
//        };
        
        // cstrs
        ProtoCamera();
        ProtoCamera(const Vec3f& pos, const Vec3f& rot);
        ProtoCamera(const Vec3f& pos, const Vec3f& rot, const ProtoBoundsf& bounds);
        ProtoCamera(const Vec3f& pos, const Vec3f& rot, const ProtoBoundsf& bounds, float fovAngle, float aspectRatio, float nearClipPlane, float farClipPlane);
        ProtoCamera(const Vec3f& pos, const Vec3f& rot, const ProtoBoundsf& bounds, float frustumVals[4]);
        ProtoCamera(float fovAngle, float aspectRatio, float nearClipPlane, float farClipPlane);
        ProtoCamera(float frustumVals[4]);
        
        // include in case of derived ProtoCamera class
        virtual ~ProtoCamera();
        
        // accessors/mutators
        unsigned char getUniqueID() const;
        
        void setName(std::string name);
        std::string getName() const;
        
        void project();
        
        void setProjection(float fovAngle, float aspectRatio, float nearClipPlane = .1f, float farClipPlane = 1000.0f);
        void setPosition(const Vec3f& pos);
        void setRotation(const Vec3f& rot);
        void setViewPort(float x, float y, float w, float h);
        void setAspectRatio(float aspectRatio);
        void setBounds(const ProtoBoundsf& bounds);
        
        Vec3f getPosition() const;
        Vec3f getRotation() const;
        ProtoBoundsf getViewPort() const;
        float getAspectRatio() const;
        ProtoBoundsf getBounds() const;
        
//        void setRenderingMode(RenderMode mode = WIREFRAME);
//        RenderMode getRenderingMode() const;
        
    private:
        Vec3f pos, rot;
        float fovAngle;
        float aspectRatio;
        float nearClipPlane, farClipPlane;
        std::string name;
        ProtoBoundsf bounds, viewPort;
        
        
        static unsigned char static_camera_count;
        
        // ProtoWorld manages multiple cameras through their unique_id
        unsigned char uniqueID;
        
//        RenderMode mode;
        
    };
    
    inline void ProtoCamera::setPosition(const Vec3f& pos) {
        this->pos = pos;
    }
    
    inline void ProtoCamera::setRotation(const Vec3f& rot){
        this->rot = rot;
    }
    
    inline unsigned char ProtoCamera::getUniqueID() const{
        return uniqueID;
    }
    
    inline void ProtoCamera::setName(std::string name){
        this->name = name;
        
    }
    
    inline std::string ProtoCamera::getName() const {
        return name;
    }
    
    inline void ProtoCamera::setAspectRatio(float aspectRatio){
        this->aspectRatio = aspectRatio;
    }
    
    inline void ProtoCamera::setBounds(const ProtoBoundsf& bounds){
        this->bounds = bounds;
    }
    
    
    inline Vec3f ProtoCamera::getPosition() const{
        return pos;
        
    }
    inline Vec3f ProtoCamera::getRotation() const{
        return rot;
    }
    inline ProtoBoundsf ProtoCamera::getViewPort() const{
        return viewPort;
    }
    
    inline float ProtoCamera::getAspectRatio() const{
        return aspectRatio;
    }
    
    inline ProtoBoundsf ProtoCamera::getBounds() const{
        return bounds;
    }
    
//    inline void ProtoCamera::setRenderingMode(RenderMode mode){
//        this->mode = mode;
//    }
//    
//    inline ProtoCamera::RenderMode ProtoCamera::getRenderingMode() const {
//        return mode;
//    }
    
    
}


#endif // Protobyte_v02_ProtoCamera_cpp
