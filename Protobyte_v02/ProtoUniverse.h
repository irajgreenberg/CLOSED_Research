/*!  \brief  ProtoUniverse.h: Top Level Master controller class -
 Implmented as a pointer singleton
 ProtoUniverse.h
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

#ifndef Protobyte_v02_ProtoUniverse_cpp
#define Protobyte_v02_ProtoUniverse_cpp

#include <iostream>
#include <vector>
#include "ProtoCamera.h"
#include "ProtoAnimator.h"
#include "ProtoRenderer.h"

namespace ijg {
    
    class ProtoUniverse {
        
    private:
        
        // field for singleton instance
        static ProtoUniverse* singletonUniverse;
        
        // private default cstr to enforce singleton pattern
        ProtoUniverse();
        
        // disallow overriding copy cstr
        ProtoUniverse(const ProtoUniverse& universe);
        
        
        // set universe managers : no access outside of class
        ProtoAnimator* animator; // singleton
        ProtoRenderer* renderer; // singleton
        
        // controls rendering style (point cloud, wireframe or surface)
        ProtoRenderer::RenderModeEnum renderMode;
        
        void init();
        
        // collection of all ProtoGeomBase ptrs
        std::vector<ProtoGeomBase*> geomObjs;
        // iterator
        std::vector<ProtoGeomBase*>::iterator geomObjsIter;
        
        // collection of all ProtoCamera ptrs
        std::vector<ProtoCamera*> cameras;
        // iterator
        std::vector<ProtoCamera*>::iterator cameraObjsIter;
        // unsigned
        
    public:
        
        // only returns a single instance
        static ProtoUniverse* getInstance();
        
        // dstr
        ~ProtoUniverse();
        
        // overloaded assignment op
        ProtoUniverse& operator=(const ProtoUniverse& universe);
        
        /****** add/remove stuff to the ProtoUniverse ******/
        // adds ProtoGeomBase/ProtoGeomComposite pointers
        void add(ProtoGeomBase* baseObj); // single geometric obj
        void add(ProtoGeomComposite* compositeObj); // composite geometric obj
        
        // adds camera obs
        void add(ProtoCamera* camera);
        
        // cleans up containers but NOT memory
        void remove(ProtoGeomBase* graphicsObj);
        void remove(ProtoCamera* camera);
        
        
        // run universe
        void run();
        
        // stop universe
        void stop();
        
        
        // state changes
        void setRenderState(ProtoRenderer::RenderModeEnum renderMode = ProtoRenderer::SURFACE, float pointSize = 3.5f);
        
        
    };
}

#endif // Protobyte_v02_ProtoUniverse_cpp
