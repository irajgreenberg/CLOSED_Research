/*!  \brief  ProtoLight.h: (add brief description)
 ProtoLight.h
 Protobyte Library v02
 
 Created by Ira on 8/26/13.
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

#ifndef PROTO_LIGHT_H
#define PROTO_LIGHT_H

#include <iostream>
#include "ProtoColor4.h"
#include "ProtoVector3.h"

namespace ijg {
    
    class ProtoLight {
    
    public:
        ProtoLight();
        ProtoLight(const Vec3f& position, const ProtoColor4f& diffuse);
        ProtoLight(const Vec3f& position, const ProtoColor4f& diffuse, const ProtoColor4f& ambient, const ProtoColor4f& specular, float shininess);
        virtual ~ProtoLight();
        
        enum lightPosMode{
            DIRECTIONAL_INFINITE,
            POSITIONAL
        };
        
        void setPosition(const Vec3f& position);
        const Vec3f& getPosition() const;
        
        void setDiffuse(const ProtoColor4f& diffuse);
        const ProtoColor4f& getDiffuse() const;
        
        void setAmbient(const ProtoColor4f& ambient);
        const ProtoColor4f getAmbient() const;
        
        void setSpecular(const ProtoColor4f& specular);
        const ProtoColor4f& getSpecular() const;
        
        void setDiffuseMaterial(const ProtoColor4f& diffuseMaterial);
        const ProtoColor4f& getDiffuseMaterial() const;
        
        void setAmbientMaterial(const ProtoColor4f& ambientMaterial);
        const ProtoColor4f& getAmbientMaterial() const;
        
        void setSpecularMaterial(const ProtoColor4f& specularMaterial);
        const ProtoColor4f& getSpecularMaterial() const;
        
        void setEmissiveMaterial(const ProtoColor4f& emissiveMaterial);
        const ProtoColor4f& getEmissiveMaterial() const;
        
        void setShininess(float shininess);
        float getShinines() const;
        
    private:
        Vec3f position;
        
        // light properties
        ProtoColor4f diffuse, ambient, specular;
        
        //material properties
        ProtoColor4f diffuseMaterial, ambientMaterial, specularMaterial, emissiveMaterial;
        
        float shininess;
        
    };
    
    // accessors/mutators
    inline void ProtoLight::setPosition(const Vec3f& position){
        this->position = position;
    }
    
    inline const Vec3f& ProtoLight::getPosition() const{
        return position;
    }
    
    inline void ProtoLight::setDiffuse(const ProtoColor4f& diffuse){
        this->diffuse = diffuse;
    }
    
    inline const ProtoColor4f& ProtoLight::getDiffuse() const{
        return diffuse;
    }

    inline void ProtoLight::setAmbient(const ProtoColor4f& ambient){
        this->ambient = ambient;
    }
    
    inline const ProtoColor4f ProtoLight::getAmbient() const {
        return ambient;
    }
    
    inline void ProtoLight::setSpecular(const ProtoColor4f& specular){
        this->specular = specular;
    }
    inline const ProtoColor4f& ProtoLight::getSpecular() const{
        return specular;
    }
    
    //materials
    inline void ProtoLight::setDiffuseMaterial(const ProtoColor4f& diffuseMaterial){
        this->diffuseMaterial = diffuseMaterial;
    }
    
    inline const ProtoColor4f& ProtoLight::getDiffuseMaterial() const{
        return diffuseMaterial;
    }
    
    inline void ProtoLight::setAmbientMaterial(const ProtoColor4f& ambientMaterial){
        this->ambientMaterial = ambientMaterial;
    }
    
    inline const ProtoColor4f& ProtoLight::getAmbientMaterial() const{
        return ambientMaterial;
    }

    inline void ProtoLight::setSpecularMaterial(const ProtoColor4f& specularMaterial){
        this->specularMaterial = specularMaterial;
    }
    inline const ProtoColor4f& ProtoLight::getSpecularMaterial() const{
        return specularMaterial;
    }
    
    inline void ProtoLight::setEmissiveMaterial(const ProtoColor4f& emissiveMaterial){
        this->emissiveMaterial = emissiveMaterial;
    }
    inline const ProtoColor4f& ProtoLight::getEmissiveMaterial() const{
        return emissiveMaterial;
    }
    
    inline void ProtoLight::setShininess(float shininess){
        this->shininess = shininess;
    }
    
    inline float ProtoLight::getShinines() const{
        return shininess;
    }

}

#endif // PROTO_LIGHT_H
