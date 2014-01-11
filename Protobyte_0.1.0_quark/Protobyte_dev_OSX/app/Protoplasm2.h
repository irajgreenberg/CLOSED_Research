//
//  ProtoPlasm2.h
//  Protobyte_dev_v02
//
//  Created by iragreenberg on 9/27/13.
//  Copyright (c) 2013 Ira Greenberg. All rights reserved.
//



#ifndef __Protobyte_dev_v02__ProtoPlasm2__
#define __Protobyte_dev_v02__ProtoPlasm2__

// about to switch to GLFW
#ifdef _WIN32
#include <GL/glew.h>
#endif

// from OF documentation
// OSX link with " " instead of < > to avoid putting in defualt include path
#if (_MSC_VER)
#include <GLFW/glfw3.h>
#else
#include "GLFW/glfw3.h"
#endif

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "ProtoBaseApp.h"

// use GL3 context (OpenGL 3.2-4.1)
#define GLFW_INCLUDE_GLCOREARB

// bring in GLU
#define GLFW_INCLUDE_GLU

namespace ijg {
    
    class ProtoPlasm2 {
        
    public:
        static int frameCount;
        static int frameRate;
        
        
        explicit ProtoPlasm2(ProtoBaseApp* baseApp);
        ProtoPlasm2(int appWidth, int appHeight, std::string appTitle, ProtoBaseApp* baseApp);
        
        
        
    private:
        
        void initSFMLInit();
        void initSFMLRun();
        
        // cross-platform SFML Window
        sf::Window* window;
        
        // Master controller class, manages view, lighting and rendering
        std::unique_ptr<ProtoWorld> world;
        
        // base app class for user defined app classes
        ProtoBaseApp* baseApp;
        
        int appWidth;
        int appHeight;
        std::string appTitle;
    };
    
#define frameCount ProtoPlasm2::frameCount
#define frameRate ProtoPlasm2::frameRate
}

#endif /* defined(__Protobyte_dev_v02__ProtoPlasm2__) */
