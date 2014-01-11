#ifdef _WIN32
#include <GL/glew.h>
#endif

#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

#include "../../Protobyte_v02/ProtoWorld.h"
#include "../../Protobyte_v02/ProtoMath.h"
#include "../../Protobyte_v02/ProtoVector2.h"
#include "../../Protobyte_v02/ProtoVector3.h"
#include "../../Protobyte_v02/ProtoToroid.h"
#include "../../Protobyte_v02/ProtoSpline3.h"
#include "../../Protobyte_v02/ProtoSphere.h"
#include "../../Protobyte_v02/ProtoTube.h"
#include "../../Protobyte_v02/ProtoLight.h"


#ifndef PROTO_BASEAPP_H
#define PROTO_BASEAPP_H

#include <iostream>

namespace ijg {
    
    class ProtoBaseApp {
        
        friend class ProtoPlasm;
        
    public:
        ProtoBaseApp();
        
       // void setAppWindowDetails(int appWidth, int appHeight, std::string appTitle);
        
        
    private:
        // only needed to be called by ProtoPlasm class - a friend
        void setWorld(std::unique_ptr<ProtoWorld> world);
        void runWorld();
        
    protected:
        // pure virtual funcs require override
        virtual void init()=0;
        virtual void run()=0;
        
        // mouse/key events
        virtual void keyPressed();
        virtual void mousePressed();
        virtual void mouseRightPressed();
        virtual void mouseReleased();
        virtual void mouseRightReleased();
        virtual void mouseMoved();
        virtual void mouseDragged();
        
        // window events
        virtual void onResized();
        virtual void onClosed();
        
        
        // Add content to world
        void add(std::unique_ptr<ProtoGeom3> geom);
        void add(std::unique_ptr<ProtoLight> lt);
        void add(std::unique_ptr<ProtoCamera> cam);
        //void initWorld();

        
        std::unique_ptr<ProtoWorld> world;
        int appWidth;
        int appHeight;
        std::string appTitle;
        
    
        
        
       
        
        
    };
    
}

#endif /* defined(PROTO_BASEAPP_H) */
