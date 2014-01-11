//
//  App01.cpp
//  Protobyte_dev_v02
//
//  Created by iragreenberg on 9/27/13.
//  Copyright (c) 2013 Ira Greenberg. All rights reserved.
//

#include "App01.h"

using namespace ijg;
float x = 0;
float theta = 0;
int ind = 0;
int ind2 = 0;

App01::App01(){
    // call base class 1st
    //std::cout << "in derived class cstr" << std::endl;
}

void App01::init(){
    
    verletSurf = std::unique_ptr<ProtoVerletSurface> (new ProtoVerletSurface(Vec3f(0,0,0),
                                                                             Vec3f(0,0,0), Dim3f(200, 200, 0), ProtoColor4f(.6, .6, .8, 1.0), 41, 41, .005, "resources/stiller.raw"));
    toroid2 = std::unique_ptr<ProtoToroid> (new ProtoToroid(Vec3f(0, 0, 0), Vec3f(0, ProtoMath::PI/3.0,0), Dim3f(20, 20, 20),ProtoColor4f(.5, .2, .3, 1), 75, 75, .9, .2));
    
}

// event thread runs continuously
//ProtoWorld draw independently
void App01::run(){
    //std::cout << "ind = " << ind << std::endl;
    glPushMatrix();
    glTranslatef(0, 0, -200);
    glRotatef(x+=.2, 1, 1, 0);
    toroid2->display();
    verletSurf->flow();
    verletSurf->display(ProtoGeom3::VERTEX_BUFFER_OBJECT, ProtoGeom3::SURFACE, .1);
    verletSurf->display(ProtoGeom3::VERTEX_BUFFER_OBJECT, ProtoGeom3::WIREFRAME, .1);
    glPopMatrix();
    
}

void App01::keyPressed(){
    
}


void App01::mousePressed(){
    //std::cout << "mousePressed" << std::endl;
}
void App01::mouseRightPressed(){
    
}
void App01::mouseReleased(){
    
}
void App01::mouseRightReleased(){
    
}
void App01::mouseMoved(){
    
}
void App01::mouseDragged(){
    
}

void App01::onResized(){
    
}
void App01::onClosed(){
    // std::cout << "in Closed" << std::endl;
}



