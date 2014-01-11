/*!  \brief  ProtoWorld.h: Top Level Master controller class -
 Implemented as a pointer singleton. Manages all aspects of Protobyte
 library. Implements rendering strictly using VBO/VAO's and Shaders.
 Default Phong shader enabled (tbd)
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

#ifndef Protobyte_v02_ProtoWorld_cpp
#define Protobyte_v02_ProtoWorld_cpp

#if defined(_WIN32) || defined(__linux__)
#include <GL/glew.h>
#endif

#include <iostream>
#include <vector>
#include "ProtoBounds.h"
#include "ProtoCamera.h"
#include "ProtoLight.h"
//#include "ProtoAnimator.h"
#include "ProtoShader.h"
#include "ProtoRenderer.h"

// from http://www.nuonsoft.com/blog/2012/10/21/implementing-a-thread-safe-singleton-with-c11/
// to ensure thread safety
#include <memory>
#include <mutex>

//#define NDEBUG //uncomment for production code
#include <cassert>


// testing only
#include "ProtoGeom3.h"

namespace ijg {
    
    /*******************************************************************
    *** global convenience functions enabling procedural convenience ***
    ********************************************************************/
    
    void add(std::unique_ptr<ProtoGeom3> geomObj); // single geometric obj
    
    void add(ProtoGeom3* geomObj); // single geometric obj
    
    // ADD ProtoGeomComposite pointers
    //void add(ProtoGeomComposite* compositeObj); // composite geometric obj
    
    // ADD shared pointer
    void add(std::shared_ptr<ProtoGeom3> geomObj);
    
    // ADD raw pointer
    void add(const ProtoGeom3* geomObj);
    
    //+++++ CAMERA +++++
    // ADD camera obs
    void add(std::unique_ptr<ProtoCamera> camera);
    
    //+++++ LIGHTS +++++
    void add(std::unique_ptr<ProtoLight> light);
    
    void add(ProtoLight* light);
    
    /*********************************
     *** END convenience functions ***
     *********************************/

    
    
    class ProtoWorld {
        
    private:
        
        // field for singleton instance
        static ProtoWorld* singletonWorld;
        //static std::once_flag protoOnceFlag; // for thread safety
        
        // private default cstr to enforce singleton pattern
        ProtoWorld();
        
        // private copy cstr
        ProtoWorld(const ProtoWorld& world);
        
        // private operator= "still thinking about this..."
        //ProtoWorld& operator=(const ProtoWorld& world);
        
        
        // Cameras
        static ProtoBoundsf canvasBounds; // for aspect ratio
        std::vector< std::unique_ptr<ProtoCamera> > cameras; // holds up to 4 cameras
        static unsigned char cameraCount; // 1-4
        static const unsigned char CAMERA_COUNT_MAX; // 4
        
        // Lights
        std::vector< std::unique_ptr<ProtoLight> > lights; // holds up to 8 lights
        std::vector<ProtoLight* > lights2; // holds up to 8 lights
        static unsigned char lightCount; // 1-8
        static const unsigned char LIGHT_COUNT_MAX; // 8
        
        
        // Renderer
        ProtoRenderer* renderer;
        
        // Objs
        std::vector< std::unique_ptr<ProtoShape3> > shapes; // composite geom forms
        std::vector< std::shared_ptr<ProtoGeom3> > sharedGeoms; // composite geom forms
        std::vector< std::unique_ptr<ProtoGeom3> > geoms; // indiviudal geom forms
        
        // Shaders
        ProtoShader shader;
        
        
        // world fields
        Vec3f worldRotSpeed;
        
        //iterator
        //std::vector<ProtoCamera&>::iterator cameraObjsIter;
        
        // set world managers : no access outside of class
        //        std::unique_ptr<ProtoAnimator>  animator; // singleton
        //        std::unique_ptr<ProtoRenderer> renderer; // singleton
        
        // controls rendering style (point cloud, wireframe or surface)
        //ProtoRenderer::RenderMode renderMode;
        
        void init();
        //
        //        // collection of all ProtoGeomBase ptrs
        //        std::vector<ProtoGeomBase*> geomObjs;
        //        // iterator
        //        std::vector<ProtoGeomBase*>::iterator geomObjsIter;
        //
        
       
        // need to implement this function
        int activeCamera;
        
        

        
    public:
        
        static float canvasWidth, canvasHeight;
        
        enum LightSetup {
            THREE_POINT,
            FILL,
            KEY,
            BACK
        };
        
        enum Light {
            LIGHT_0,
            LIGHT_1,
            LIGHT_2,
            LIGHT_3,
            LIGHT_4,
            LIGHT_5,
            LIGHT_6,
            LIGHT_7
        };
        
        // convenience default shaders
        enum Shader {
            GIRAUD,
            PHONG,
            CELL_SHADE,
            RAY_TRACE,
            RADIOSITY
        };
        
        
        enum RenderingMode {
            POINTS,
            WIREFRAME,
            SURFACE
        };
        
        // for multiple views
        enum WorldView {
            SINGLE_VIEW,
            DOUBLE_VIEW_LANDSCAPE,
            DOUBLE_VIEW_PORTRAIT,
            QUAD_VIEW
        };
        
        float fovAngle;
        float nearClipPlane;
        float farClipPlane;
        WorldView worldView;
        
        
        friend std::ostream& operator<<(std::ostream& out, const ProtoWorld& protoWorld);
        
        // singleton pattern (&)
        //static ProtoWorld& getInstance();
        //static ProtoWorld& getInstance(float canvasWidth = 100.0, float canvasHeight = 100.0);
        
        // singleton pattern (*)
        //static ProtoWorld* getInstance();
        static ProtoWorld* getInstance(float canvasWidth, float canvasHeight);
        static ProtoWorld* getInstance();
        
        
        /*************************************************
        *       ADD/REMOVE stuff to the ProtoWorld       *
        *         using overloaded ADD functions         *
        *************************************************/
        
        //+++++ GEOMETRY +++++
        // ADD ProtoGeom3 pointers
        void add(std::unique_ptr<ProtoGeom3> geomObj); // single geometric obj
        void add(const ProtoGeom3& geomObj); // single geometric obj
        
        
        // ADD ProtoGeomComposite pointers
        //void add(ProtoGeomComposite* compositeObj); // composite geometric obj
        
        // ADD shared pointer
        void add(std::shared_ptr<ProtoGeom3> geomObj);
        
        // ADD raw pointer
        void add(const ProtoGeom3* geomObj);
        
        
        //+++++ CAMERA +++++
        // ADD camera obs
        void add(std::unique_ptr<ProtoCamera> camera);
      
        
        //+++++ LIGHTS +++++
         void add(std::unique_ptr<ProtoLight> light);
        
        void add(ProtoLight* light);
        
        
        //        // cleans up containers but NOT memory
        //        void remove(ProtoGeomBase* graphicsObj);
        //        void remove(ProtoCamera* camera);
        
        
        
        
        // run world
        void run();
        
        // stop world
        void stop();
        
        void draw();
        
        void rotate(const Vec3f& worldRot);
        
        
        // state changes
        //void setRenderState(ProtoRenderer::RenderModeEnum renderMode = ProtoRenderer::SURFACE, float pointSize = 3.5f);
        
        void setWorldRotSpeed(const Vec3f& worldRotSpeed);
        //void setWorldFrustum(float fovAngle=60, float nearClipPlane = 0.1f, float farClipPlane = 1000.0f);
        void setWorldView(WorldView worldView = QUAD_VIEW);
        void setCurrentCamera(int cameraID1, int cameraID2);
        void setCurrentCameras();
        void setActiveCamera(int activeCamera);
        void setDefaultProjection(float fovAngle=80, float nearClipPlane = 0.1f, float farClipPlane = 1000.0f);
        void setLights();
        
        void updateCanvasSize(float, float);
        
        void setRenderingMode(RenderingMode=SURFACE);
        
        
        /***********************
         *       shaders       *
         **********************/
        void setVertexShader(const char *vertexShader);
        void setVertexShader(const std::string vertexShader);
        void setFragmentShader(const char *fragmentShader);
        void setFragmentShader(const std::string fragmentShader);
        void setShaders(const char *vertexShader, const char *fragmentShader);
        void setShaders(const std::string vertexShader, const std::string fragmentShader);
        
        // Lighting handled through world
        void setDiffuse(Light lightID, const ProtoColor4f& color=ProtoColor4f(1.0, 1.0, 1.0, 1.0), const ProtoColor4f& material=ProtoColor4f(1.0, 1.0, 1.0, 1.0));
        void setSpecular(Light lightID, const ProtoColor4f& color=ProtoColor4f(1.0, 1.0, 1.0, 1.0), const ProtoColor4f& material=ProtoColor4f(1.0, 1.0, 1.0, 1.0), float shininess = 46);
        void setShininess(float shininess = 46);
        void setAmbient(Light lightID, const ProtoColor4f& color=ProtoColor4f(.4, .4, .4, 1.0), const ProtoColor4f& material=ProtoColor4f(1.0, 1.0, 1.0, 1.0));
        void setEmission(Light lightID, const ProtoColor4f& color=ProtoColor4f(0.0, 0.0, 0.0, 1.0), const ProtoColor4f& material=ProtoColor4f(0.0, 0.0, 0.0, 1.0));
        
        
        
    };
}

#endif // Protobyte_v02_ProtoWorld_cpp
