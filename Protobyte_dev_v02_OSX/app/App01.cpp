//
//  App01.cpp
//  Protobyte_dev_v02
//
//  Created by iragreenberg on 9/27/13.
//  Copyright (c) 2013 Ira Greenberg. All rights reserved.
//

#include "App01.h"

using namespace ijg;

App01::App01(){
}

void App01::setup(){
    world = ProtoWorld::getInstance();
    // objects
    // add world geoemetry polymorphicially
    std::unique_ptr<ProtoGeom3> toroid1(new ProtoToroid(Vec3f(0, 0, 0), Vec3f(15,90,-30), Dim3f(.15, .15, .15),ProtoColor4f(.3, .4, .5, 1), 22, 22, 1.5, .15));
    
    std::unique_ptr<ProtoGeom3> toroid2(new ProtoToroid(Vec3f(0, 0, 0), Vec3f(15,0,0), Dim3f(1.3, 1.3, 1.3),ProtoColor4f(.2, .2, .6, 1), 65, 65, 1.5, .05));
    
    std::unique_ptr<ProtoGeom3> toroid3(new ProtoToroid(Vec3f(0, 0, 0), Vec3f(0,0,90), Dim3f(.6, .6, .6),ProtoColor4f(.2, .6, .4, 1), 45, 45, 1.5, .15));
    
    std::unique_ptr<ProtoGeom3> toroid4(new ProtoToroid(Vec3f(0, 0, 0), Vec3f(0,0,0), Dim3f(.3, .3, .3),ProtoColor4f(.1, .3, .3, 1), 32, 55, 1.5, .185));
    
//     ProtoGeom3* toroid1 = new ProtoToroid(Vec3f(0, 0, 0), Vec3f(15,90,-30), Dim3f(.15, .15, .15),ProtoColor4f(.3, .4, .5, 1), 22, 22, 1.5, .15);
    
    
    //add(toroid1);
    world->add(std::move(toroid1));
    world->add(std::move(toroid2));
    world->add(std::move(toroid3));
    world->add(std::move(toroid4));
    
    //add(new ProtoToroid);
    
}
void App01::draw(){
    world->run();
}

void App01::keyPressed(){

}


void App01::mousePressed(){
    std::cout << "mousePressed" << std::endl;
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
    std::cout << "in Closed" << std::endl;
}



