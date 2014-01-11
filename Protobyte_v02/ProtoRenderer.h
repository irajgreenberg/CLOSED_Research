/*!  \brief  ProtoRenderer.h: Coordinates all rendering in ProtoUniverse
 ProtoRenderer.h
 Protobyte Library v02
 
 Created by Ira on 7/25/13.
 Copyright (c) 2013 Ira Greenberg. All rights reserved.
 
 Library Usage:
 This work is licensed under the Creative Commons
 Attribution-NonCommercial-ShareAlike 3.0 Unported License.
 To view a copy of this license, visit
 http://creativecommons.org/licenses/by-nc-sa/3.0/
 or send a letter to Creative Commons,
 444 Castro Street, Suite 900,
 Mountain View, California, 94041, USA.
 
 This notice must be retained any source distribution.
 
 \ingroup common
 This class is part of the group common (update)
 \sa NO LINK
 */

#ifndef PROTO_RENDERER_H
#define PROTO_RENDERER_H


#if defined(_WIN32) || defined(__linux__)
#include <GL/glew.h>
#endif

#include <SFML/OpenGL.hpp>
#include <iostream>
#include "ProtoGeom3.h"
#include <memory>
//#include "ProtoGeomComposite.h"

namespace ijg {
    
    class ProtoRenderer {
        
    private:
        
        // field for singleton instance
        static ProtoRenderer* singletonRenderer;
        static bool singletonFlag;
        
        // private default cstr to enforce singleton pattern
        ProtoRenderer();
        
        // disallow overriding copy cstr
        ProtoRenderer(const ProtoRenderer& renderer);
        
        void init();
        
        
        
    public:
        
        /**********************************
         *    Display Modes for testing   *
         *********************************/
        enum DisplayMode {
            IMMEDIATE, // begin at 0
            VERTEX_ARRAY,
            VERTEX_ARRAY_INTERLEAVED,
            DISPLAY_LIST,
            VERTEX_BUFFER_OBJECT
        };
        
        enum RenderMode {
            POINT_CLOUD,
            WIREFRAME, // begin at 0
            SURFACE
        };
        
        // singleton
        static ProtoRenderer* getInstance();
        
       // dstr
        ~ProtoRenderer();
        
        
        void draw(const std::unique_ptr<ProtoGeom3>& geomObj, DisplayMode mode = VERTEX_BUFFER_OBJECT, RenderMode render = SURFACE, float pointSize = 1.0);
        
        void display(const std::unique_ptr<ProtoGeom3>& geomObj, DisplayMode mode = VERTEX_BUFFER_OBJECT, RenderMode render = SURFACE, float pointSize = 1.0);
        
    };
#define Renderer ProtoRenderer
}

#endif // PROTO_RENDERER_H
