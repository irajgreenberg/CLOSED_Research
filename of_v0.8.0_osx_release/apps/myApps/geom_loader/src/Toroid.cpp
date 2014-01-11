//
//  Toroid.cpp
//  tut03_3d_ver02
//
//  Created by Ira Greenberg on 4/21/12.
//  Copyright 2012 SMU. All rights reserved.
//


#include "Toroid.h"

// constructors


Toroid::Toroid(ofVec3f loc, ofVec3f dim, int segs, float segRadius, int detail):
loc(loc), dim(dim), segs(segs), segRadius(segRadius), detail(detail)  
{
    init();
}


// destructor
Toroid::~Toroid()
{
    delete [] surfs;

    // deallocate pointer to pointer
    for (int i=0; i<detail; i++){
        delete [] verts2D[i];
    }
    delete [] verts2D;

}

// Copy Constructor
Toroid::Toroid(const Toroid& toroid_src)
{
    loc =  toroid_src.loc;
    dim =  toroid_src.dim;
    segs =  toroid_src.segs;
    segRadius =  toroid_src.segRadius;
    detail =  toroid_src.detail;
    
    vertCount = detail * segs;
    surfCount = vertCount*2;
    
    allocate();
    
    // clone verts
    for(int i=0; i<segs; i++){
        for(int j=0; j<detail; j++){
            verts2D[i][j] = toroid_src.verts2D[i][j];
        }
    }
    
    // clone surfs
    for(int i=0; i<surfCount; i++){
        surfs[i] = toroid_src.surfs[i];        
    }
}

// Assignemnt Operator
Toroid& Toroid::operator= (const Toroid& toroid_src)
{
    // ensure not assignment to self
    if (this != &toroid_src){
        
        delete [] surfs; 
        // deallocate pointer to pointer
        for (int i=0; i<detail; i++){
            delete [] verts2D[i];
        }
        delete [] verts2D;
        loc =  toroid_src.loc;
        dim =  toroid_src.dim;
        segs =  toroid_src.segs;
        segRadius =  toroid_src.segRadius;
        detail =  toroid_src.detail;
        vertCount = detail * segs;
        surfCount = vertCount*2;

        allocate();
        
        // clone verts
        for(int i=0; i<segs; i++){
            for(int j=0; j<detail; j++){
                verts2D[i][j] = toroid_src.verts2D[i][j];
            }
        }
        
        // clone surfs
        for(int i=0; i<surfCount; i++){
            surfs[i] = toroid_src.surfs[i];        
        }
    }

    // allow chaining
    return *this;
}


void Toroid::allocate() {
    verts2D = new ofVec3f*[segs];
    for (int i=0; i<segs; i++){
        verts2D[i] = new ofVec3f[detail];
    }
    
    surfs = new Surf3D[surfCount];
}

void Toroid::init(){
    vertCount = detail * segs;
    surfCount = vertCount*2;
    
    allocate();
    
    // CREATE VERTS
    float x = 0, y = 0, z = 0, x2 = 0, y2 = 0, z2 = 0;
    float theta = 0, phi = 0;
    for (int i=0; i<segs; i++){
        // reset theta for each cross-section
        theta = 0;
        // draw cross-sections (the segs) around z-axis
        // then rotate around y axis. detail is number of 
        // points around each cross-section
        for (int j=0; j<detail; j++){
            x = dim.x + cos(theta)*segRadius; // start at right side of torus
            y = sin(theta)*segRadius;
            z = 0;
            
            /* 
             rotate each point around y-axis based on phi
             x' = z*sin(phi) + x*cos(phi)
             z' = z*cos(phi) - x*sin(phi)
             */
            x2 = z*sin(phi) + x*cos(phi);
            y2 = y; // assignment not really necessary but maintains consistency
            z2 = z*cos(phi) - x*sin(phi);
            
            verts2D[i][j] = ofVec3f(x2, y2, z2);
            
            theta += PI*2.0/detail;
        }
        phi -= PI*2.0/segs;
    }
    
    //CREATE SURFS
    int counter = 0;
    for (int i=0; i<segs; i++){
        for (int j=0; j<detail; j++){
            if (i<segs-1){
                if (j<detail-1){
                    surfs[counter++] = Surf3D(verts2D[i][j], verts2D[i+1][j], verts2D[i][j+1]);
                    surfs[counter++] = Surf3D(verts2D[i+1][j], verts2D[i+1][j+1], verts2D[i][j+1]);
                } else {
                    surfs[counter++] = Surf3D(verts2D[i][j], verts2D[i+1][j], verts2D[i][0]);
                    surfs[counter++] = Surf3D(verts2D[i+1][j], verts2D[i+1][0], verts2D[i][0]);
                }
            } else {
                if (j<detail-1){
                    surfs[counter++] = Surf3D(verts2D[i][j], verts2D[0][j], verts2D[i][j+1]);
                    surfs[counter++] = Surf3D(verts2D[0][j], verts2D[0][j+1], verts2D[i][j+1]);
                } else {
                    surfs[counter++] = Surf3D(verts2D[i][j], verts2D[0][j], verts2D[i][0]);
                    surfs[counter++] = Surf3D(verts2D[0][j], verts2D[0][0], verts2D[i][0]);

                }
            }
        }
    }
    
}


void Toroid::display(){
    for (int i=0; i<surfCount; i++){
        surfs[i].display(); 
    }
}
