//
//  Box.cpp
//  tut03_3d_ver01
//
//  Created by Ira Greenberg on 4/10/12.
//  Copyright 2012 SMU. All rights reserved.
//

#include "Box.h"


Box::Box()
{
    verts[0] = ofVec3f(-.5,.5,-.5);
    verts[1] = ofVec3f(.5,.5,-.5);
    verts[2] = ofVec3f(.5,.5,.5);
    verts[3] = ofVec3f(-.5,.5,.5);
    verts[4] = ofVec3f(-.5,-.5,-.5);
    verts[5] = ofVec3f(-.5,-.5,.5);
    verts[6] = ofVec3f(.5,-.5,.5);
    verts[7] = ofVec3f(.5,-.5,-.5);
    
    norms[0] = ofVec3f(0,0,1);
    norms[1] = ofVec3f(0,0,1);
    norms[2] = ofVec3f(1,0,0);
    norms[3] = ofVec3f(1,0,0);
    norms[4] = ofVec3f(0,0,-1);
    norms[5] = ofVec3f(0,0,-1);
    norms[6] = ofVec3f(-1,0,0);
    norms[7] = ofVec3f(-1,0,0);
    norms[8] = ofVec3f(0,-1,0);
    norms[9] = ofVec3f(0,-1,0);
    norms[10] = ofVec3f(0,1,0);
    norms[11] = ofVec3f(0,1,0);
    
}

void Box::display()
{
    // fill shape
    ofSetColor(255, 100, 255);
    ofFill();

    ofSetPolyMode(OF_POLY_WINDING_ODD); // normal mode
    glBegin(GL_TRIANGLES);
     
    //front faces
    glNormal3f(0.0, 0.0, 1.0);
    glVertex3f(verts[0].x, verts[0].y, verts[0].z);
    glVertex3f(verts[1].x, verts[1].y, verts[1].z);
    glVertex3f(verts[2].x, verts[2].y, verts[2].z);
    
    glNormal3f(0.0, 0.0, 1.0);
    glVertex3f(verts[0].x, verts[0].y, verts[0].z);
    glVertex3f(verts[2].x, verts[2].y, verts[2].z);
    glVertex3f(verts[3].x, verts[3].y, verts[3].z);
    
    //right
    glNormal3f(1.0, 0.0, 0.0);
    glVertex3f(verts[3].x, verts[3].y, verts[3].z);
    glVertex3f(verts[2].x, verts[2].y, verts[2].z);
    glVertex3f(verts[5].x, verts[5].y, verts[5].z);
    
    glNormal3f(1.0, 0.0, 0.0);
    glVertex3f(verts[3].x, verts[3].y, verts[3].z);
    glVertex3f(verts[5].x, verts[5].y, verts[5].z);
    glVertex3f(verts[4].x, verts[4].y, verts[4].z);
    
    //back
    glNormal3f(0.0, 0.0, -1.0);
    glVertex3f(verts[4].x, verts[4].y, verts[4].z);
    glVertex3f(verts[5].x, verts[5].y, verts[5].z);
    glVertex3f(verts[6].x, verts[6].y, verts[6].z);

    
    glNormal3f(0.0, 0.0, -1.0);
    glVertex3f(verts[4].x, verts[4].y, verts[4].z);
    glVertex3f(verts[6].x, verts[6].y, verts[6].z);
    glVertex3f(verts[7].x, verts[7].y, verts[7].z);
    
    //left
    glNormal3f(-1.0, 0.0, 0.0);
    glVertex3f(verts[7].x, verts[7].y, verts[7].z);
    glVertex3f(verts[6].x, verts[6].y, verts[6].z);
    glVertex3f(verts[1].x, verts[1].y, verts[1].z);
    
    glNormal3f(-1.0, 0.0, 0.0);
    glVertex3f(verts[7].x, verts[7].y, verts[7].z);
    glVertex3f(verts[1].x, verts[1].y, verts[1].z);
    glVertex3f(verts[0].x, verts[0].y, verts[0].z);
    
    //bottem
    glNormal3f(0.0, -1.0, 0.0);
    glVertex3f(verts[1].x, verts[1].y, verts[1].z);
    glVertex3f(verts[6].x, verts[6].y, verts[6].z);
    glVertex3f(verts[5].x, verts[5].y, verts[5].z);
    
    glNormal3f(0.0, -1.0, 0.0);
    glVertex3f(verts[1].x, verts[1].y, verts[1].z);
    glVertex3f(verts[5].x, verts[5].y, verts[5].z);
    glVertex3f(verts[2].x, verts[2].y, verts[2].z);
    
    //top
    glNormal3f(0.0, 1.0, 0.0);
    glVertex3f(verts[7].x, verts[7].y, verts[7].z);
    glVertex3f(verts[0].x, verts[0].y, verts[0].z);
    glVertex3f(verts[3].x, verts[3].y, verts[3].z);
    
    glNormal3f(0.0, 1.0, 0.0);
    glVertex3f(verts[7].x, verts[7].y, verts[7].z);
    glVertex3f(verts[3].x, verts[3].y, verts[3].z);
    glVertex3f(verts[4].x, verts[4].y, verts[4].z);
    
    glEnd();
    
}

























