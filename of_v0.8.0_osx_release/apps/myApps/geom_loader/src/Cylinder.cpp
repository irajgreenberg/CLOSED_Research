//
//  Cylinder.cpp
//  tut03_3d_ver01
//
//  Created by Ira Greenberg on 4/10/12.
//  Copyright 2012 SMU. All rights reserved.
//

#include <iostream>
#include"Cylinder.h"

// declare static fields
int Cylinder::cylinderCount = 0;
int Cylinder::cylinderCount2 = 0;

Cylinder::Cylinder(ofVec3f loc, int sides, float radius , float ht, bool hasCaps):
loc(loc), sides(sides), radius(radius), ht(ht), hasCaps(hasCaps) {
    cylinderCount ++;
    init();
}


Cylinder::~Cylinder()
{
    cylinderCount --;
    delete [] surfs;
    delete [] vertsTop;
    delete [] vertsBottom;
}

// implement overloaded ops and copy cster
// add overloaded ops and copy cster
Cylinder::Cylinder(const  Cylinder& cylinder_src) 
{
    cylinderCount ++;
    std::cout << " in copy constructor\n";
    //ofVec3f loc, int sides, float radius , float ht, bool hasCaps)
    loc = cylinder_src.loc;
    sides = cylinder_src.sides;
    radius =  cylinder_src.radius;
    ht = cylinder_src.ht;
   // topCenterVert = cylinder_src.topCenterVert;
    //bottCenterVert = cylinder_src.bottCenterVert;
    hasCaps = cylinder_src.hasCaps;
    vertsCount = cylinder_src.vertsCount;
    surfCount =  cylinder_src.surfCount;
    

    vertsTop = new ofVec3f[vertsCount];
    vertsBottom = new ofVec3f[vertsCount];
    surfs = new Surf3D[surfCount];
    for (int i=0; i<vertsCount; i++){
        vertsTop[i] = cylinder_src.vertsTop[i];
        vertsBottom[i] = cylinder_src.vertsBottom[i];
    }
    
    for (int i=0; i<surfCount; i++){
       surfs[i] = cylinder_src.surfs[i];
    }
    
    
    
}


//=============================================================================
// Assignment Operator, called by default when:
// assignment between 2 objects that both exist
//=============================================================================
Cylinder& Cylinder::operator= (const  Cylinder& cylinder_src) 
{

    // make sure assignment is not between same 2 objects
    if (this == &cylinder_src){
        return *this;
    }
    
    loc = cylinder_src.loc;
    sides = cylinder_src.sides;
    radius =  cylinder_src.radius;
    ht = cylinder_src.ht;

    hasCaps = cylinder_src.hasCaps;

    vertsCount = cylinder_src.vertsCount;
    surfCount =  cylinder_src.surfCount;
    
    delete [] vertsTop;
    delete [] vertsBottom;
    delete [] surfs;
    
    vertsTop = new ofVec3f[vertsCount];
    vertsBottom = new ofVec3f[vertsCount];
    surfs = new Surf3D[surfCount];
    for (int i=0; i<vertsCount; i++){
        vertsTop[i] = cylinder_src.vertsTop[i];
        vertsBottom[i] = cylinder_src.vertsBottom[i];
    }
    
    for (int i=0; i<surfCount; i++){
        surfs[i] = cylinder_src.surfs[i];
    }
    
    // this allows assignment chaining (e.g. obj1 = obj2 = obj3)
    return *this;
    
}

ostream& operator<< (ostream &out, Cylinder& cylinder_src)
{
    out << "(" <<  "loc=" << cylinder_src.loc << ", " <<
    "sides=" << cylinder_src.sides << ", " <<
     "radius=" << cylinder_src.radius << ", " <<
     "ht=" << cylinder_src.ht << ", " <<
     "hasCaps=" << cylinder_src.hasCaps << ", " <<
     "vertsCount=" << cylinder_src.vertsCount << ", " <<
     "surfCount=" << cylinder_src.surfCount << ")";
    return out;
}


void Cylinder::init()
{
    vertsCount = sides;
    vertsTop = new ofVec3f[vertsCount];
    vertsBottom = new ofVec3f[vertsCount];
    
    surfCount = sides*4;
    surfs = new Surf3D[surfCount];
    
    // calculate vertices around y-axis
    /************simple rotations************
     x-axis y = cos(theta), z = sin(theta)
     y-axis x = sin(theta), z = cos(theta)
     z-axis x = cos(theta), y = sin(theta)
     ****************************************/
    float theta = 0.0;
    float x = 0.0, y = 0.0, z = 0.0;
    float rotVal = TWO_PI / sides;
    for (int i=0; i<vertsCount; i++){
        x = sin(theta)*radius;
        z = cos(theta)*radius;
        vertsTop[i] = ofVec3f(x, -ht/2, z);
        vertsBottom[i] = ofVec3f(x, ht/2, z);
        theta += rotVal;
    }
    
    // create caps
    topCenterVert = ofVec3f(0, -ht/2, 0);
    bottCenterVert = ofVec3f(0, ht/2, 0);
    
    // create faces CCW (Note: i indexes verts, j indexes surfs)
    for (int i=0, j=0; i<vertsCount; i++){
        // 2 triangles to make each wall between 4 points
        if (i<vertsCount-1) { 
            // walls
            surfs[j++] = Surf3D(vertsTop[i], vertsBottom[i], vertsTop[i+1]);
            surfs[j++] = Surf3D(vertsTop[i+1], vertsBottom[i], vertsBottom[i+1]);
            
            // caps
            if(hasCaps){
                surfs[j++] = Surf3D(vertsTop[i], vertsTop[i+1], topCenterVert);
                surfs[j++] = Surf3D(vertsBottom[i+1], vertsBottom[i], bottCenterVert);
            }
        } else { // for closing the cylinder
            // walls
            surfs[j++] = Surf3D(vertsTop[i], vertsBottom[i], vertsTop[0]);
            surfs[j++] = Surf3D(vertsTop[0], vertsBottom[i], vertsBottom[0]);
            
            // caps
            if(hasCaps){
                surfs[j++] = Surf3D(vertsTop[i], vertsTop[0], topCenterVert);
                surfs[j++] = Surf3D(vertsBottom[0], vertsBottom[i], bottCenterVert);
            }
        }
        
    }
    
}

void Cylinder::display()
{
    for (int i=0; i<surfCount; i++){
        surfs[i].display();
    }
}

int Cylinder::getSides() const
{
    return sides;
}

void Cylinder::setSides(int sides)
{
    this->sides = sides;
}

float Cylinder::getRadius() const
{
    return radius;
}

void Cylinder::setRadius(float radius)
{
    this->radius = radius;
}

float Cylinder::getHt() const
{
    return ht;
}

void Cylinder::setHt(float ht)
{
    this->ht = ht;
}

bool Cylinder::getHasCaps() const
{
    return hasCaps;
}

void Cylinder::setHasCaps(bool ht)
{
    this->hasCaps = hasCaps;
}

int Cylinder::getCylinderCount2()
{
    return cylinderCount2;
}
