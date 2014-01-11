//
//  ProtoPlasm.h
//  Protobyte_dev_v02
//
//  Created by iragreenberg on 9/27/13.
//  Copyright (c) 2013 Ira Greenberg. All rights reserved.
//



#ifndef __Protobyte_dev_v02__ProtoPlasm__
#define __Protobyte_dev_v02__ProtoPlasm__

#ifdef _WIN32
#include <GL/glew.h>
#endif

#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>
#include "ProtoBaseApp.h"

namespace ijg {
    
    class ProtoPlasm {
        
    public:
        explicit ProtoPlasm(ProtoBaseApp* baseApp);
        ProtoPlasm(int appWidth, int appHeight, std::string appTitle, ProtoBaseApp* baseApp);
       
        
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
}

#endif /* defined(__Protobyte_dev_v02__ProtoPlasm__) */
