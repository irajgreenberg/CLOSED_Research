/*!  \brief  ProtoLight.cpp: (add brief description)
 ProtoLight.cpp
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

#include "ProtoLight.h"

using namespace ijg;

// default cstr
ProtoLight::ProtoLight():
position(Vec3f(-2, 2, 2)), diffuse(ProtoColor4f(.8, .5, .1, 1.0)), ambient(ProtoColor4f(.5, .5, .5, 1.0)), specular(ProtoColor4f(1.0, 1.0, 1.0, 1.0)), shininess(25), diffuseMaterial(ProtoColor4f(1.0, 1.0, 1.0, 1.0)), ambientMaterial(ProtoColor4f(.25, .25, .25, 1)), specularMaterial(ProtoColor4f(1.0, 1.0, 1.0, 1.0)), emissiveMaterial(ProtoColor4f(0, 0, 0, 1.0)){
}

// cstr
ProtoLight::ProtoLight(const Vec3f& position, const ProtoColor4f& diffuse):
position(position), diffuse(diffuse), ambient(ProtoColor4f(.3, .3, .3, 1.0)), specular(ProtoColor4f(1.0, 1.0, 1.0, 1.0)), shininess(28), diffuseMaterial(ProtoColor4f(1.0, 1.0, 1.0, 1.0)), ambientMaterial(ProtoColor4f(1.0, 1.0, 1.0, 1.0)), specularMaterial(ProtoColor4f(1.0, 1.0, 1.0, 1.0)), emissiveMaterial(ProtoColor4f(.1, .1, .1, .1))
{
    
}

ProtoLight::ProtoLight(const Vec3f& position, const ProtoColor4f& diffuse, const ProtoColor4f& ambient, const ProtoColor4f& specular, float shininess):position(position), diffuse(diffuse), ambient(ambient), specular(specular), shininess(shininess), diffuseMaterial(ProtoColor4f(1.0, 1.0, 1.0, 1.0)), ambientMaterial(ProtoColor4f(1.0, 1.0, 1.0, 1.0)), specularMaterial(ProtoColor4f(1.0, 1.0, 1.0, 1.0)), emissiveMaterial(ProtoColor4f(.1, .1, .1, .1))
{
    
}


// dstr
ProtoLight::~ProtoLight() {
    
}
