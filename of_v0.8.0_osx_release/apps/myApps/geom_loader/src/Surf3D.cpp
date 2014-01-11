//
//  Surf3D.cpp
//  tut03_3d_ver01
//
//  Created by Ira Greenberg on 4/10/12.
//  Copyright 2012 SMU. All rights reserved.
//

#include <iostream>
#include "Surf3D.h" 


Surf3D::Surf3D(ofVec3f vs[3])
{
    // ensure vecs pass in
    if (vs) {
        setVecs(vs);
        calcNorm();
    }
}

Surf3D::Surf3D(const ofVec3f& v0, const ofVec3f& v1, const ofVec3f& v2)
{
    vs[0] = v0;
    vs[1] = v1;
    vs[2] = v2;
    calcNorm();
}

void Surf3D::calcNorm()
{
    // get surface vectors relative to pt vs[0]
    ofVec3f vn1 = vs[2]-vs[0];
    ofVec3f vn2 = vs[1]-vs[0];
    n = vn1.cross(vn2);
    n.normalize();
}

void Surf3D::display()
{
    ofSetPolyMode(OF_POLY_WINDING_ODD); // normal mode
    glBegin(GL_TRIANGLES);
    
    //front faces
    glNormal3f(n.x, n.y, n.z);
    glVertex3f(vs[0].x, vs[0].y, vs[0].z);
    glVertex3f(vs[1].x, vs[1].y, vs[1].z);
    glVertex3f(vs[2].x, vs[2].y, vs[2].z);
    glEnd();
}

ofVec3f* Surf3D::getNorm()
{
    return &n;
}

void Surf3D::setVecs(ofVec3f vs[3])
{
    this->vs[0] = vs[0];
    this->vs[1] = vs[1];
    this->vs[2] = vs[2];
    calcNorm();
}

void Surf3D::setVecs(const ofVec3f& v0, const ofVec3f& v1, const ofVec3f& v2){
    this->vs[0] = v0;
    this->vs[1] = v1;
    this->vs[2] = v2;
    calcNorm();
}
