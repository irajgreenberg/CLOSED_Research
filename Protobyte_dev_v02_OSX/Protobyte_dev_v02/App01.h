//
//  App01.h
//  Protobyte_dev_v02
//
//  Created by iragreenberg on 9/27/13.
//  Copyright (c) 2013 Ira Greenberg. All rights reserved.
//

#ifndef __Protobyte_dev_v02__App01__
#define __Protobyte_dev_v02__App01__

#include "ProtoBaseApp.h"
#include <iostream>

using namespace ijg;

class App01 : public ProtoBaseApp {

private:
    ProtoWorld* world;

public:
    App01();
    void setup();
    void draw();
    
    // Mouses/Key Events
    void keyPressed();
    void mousePressed();
    void mouseRightPressed();
    void mouseReleased();
    void mouseRightReleased();
    void mouseMoved();
    void mouseDragged();
    
    // window events
    void onResized();
    void onClosed();


    
    
};

#endif /* defined(__Protobyte_dev_v02__App01__) */
