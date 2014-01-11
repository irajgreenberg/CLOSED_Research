#include "SMUEngine.h"
#include <iostream>

SMUEngine::~SMUEngine()
{
    //delete poly;
}

//--------------------------------------------------------------
// Runs once: Initialize Values
void SMUEngine::setup(){
    ofBackground(185, 185, 0);
	ofSetWindowTitle("CSE1342 Tut03 - Particles");
	ofSetFrameRate(60); 
    ofEnableAlphaBlending();
    ofEnableSmoothing();
   	glEnable(GL_DEPTH_TEST);
    
    eCam.setDistance(300);
    
    lt.enable();
    lt.setPosition(ofVec3f(-200, 20, 100));
  
    lt.setAmbientColor(ofColor(0,0, 70));
    cyl = new Cylinder(ofVec3f(), 5);
   // cyl2 = new Cylinder(ofVec3f(), 50);
    
    // Toroid paramters: ofVec3f loc, ofVec3f dim, int segs, float segRadius, int detail
    t = new Toroid(ofVec3f(), ofVec3f(30, 30, 30), 30, 15, 30);

    Cylinder c3(ofVec3f(), 5); // call constructor
    Cylinder c4(c3); // calls copy constructor
    
    std::cout << "c4: " << c4 << std::endl;
    // or Cylinder  c4 = c3 // calls copy constructor
    
    //c3 = c4; // calls assignment operator
    
    //ofEnableLighting();
    //ofNoFill();
    //ofSetBackgroundAuto(FALSE);
    //poly = new SMUPoly(4, 125);

}

//--------------------------------------------------------------
// Runs continuously: update values but don't draw in here
void SMUEngine::update(){
}

//--------------------------------------------------------------
// Runs continuously: the place to draw
void SMUEngine::draw(){
    // if this was not a pointer then we would use .display()
    // but based on how we coded it won't draw

    eCam.begin();
    
    ofPushMatrix();
    ofTranslate(-125, 0, 0);
    ofSetColor(15, 125, 10);
    ofSphere(0, 0, 0, 30.0f);
    ofPopMatrix();
    
    ofPushMatrix();
    ofSetColor(0, 0, 100);
    ofRotateY(45);
    ofBox(0, 0, 50);
    ofPopMatrix();
    
    ofTranslate(125, 0, 0);
    ofSetColor(150, 75, 0);
    
    t->display();
    
    eCam.end();
 
} 




















