//
//  Cylinder.h
//  tut03_3d_ver01
//
//  Created by Ira Greenberg on 4/10/12.
//  Copyright 2012 SMU. All rights reserved.
//
// Library Usage:
// This work is licensed under the Creative Commons 
// Attribution-NonCommercial-ShareAlike 3.0 Unported License. 
// To view a copy of this license, visit 
// http://creativecommons.org/licenses/by-nc-sa/3.0/ 
// or send a letter to Creative Commons, 
// 444 Castro Street, Suite 900, 
// Mountain View, California, 94041, USA.
//

#ifndef tut03_3d_ver01_Cylinder_h
#define tut03_3d_ver01_Cylinder_h

#include "ofMain.h"
#include "surf3D.h"

class Cylinder {
    
private:
    
    
    ofVec3f loc;
    int sides;
    float radius;
    float ht;
    ofVec3f topCenterVert, bottCenterVert;
    bool hasCaps;
    ofVec3f* vertsTop;
    ofVec3f* vertsBottom;
    Surf3D* surfs;
    
    int vertsCount;
    int surfCount;
    
    void init();
    
    static int cylinderCount2;
        
public:
    
    Cylinder(ofVec3f loc = ofVec3f(), int sides = 12, float radius = 20, float ht = 150, bool hasCaps = true);
        
    ~Cylinder();
    
    static int cylinderCount;
    
    // add overloaded ops and copy cster
     Cylinder(const  Cylinder& cylinder_src);
    
    
    //=============================================================================
    // Assignment Operator, called by default when:
    // assignment between 2 objects that both exist
    //=============================================================================
     Cylinder& operator= (const  Cylinder& cylinder_src);
    
     friend ostream& operator<< (ostream &out, Cylinder& cylinder_src);


    
    
    
    void display();
    
    int getSides() const;
    void setSides(int sides);
    
    float getRadius() const;
    void setRadius(float radius);
    
    float getHt() const;
    void setHt(float ht);
    
    bool getHasCaps() const;
    void setHasCaps(bool ht);
    
    static int getCylinderCount2();

    
    
};

#endif










