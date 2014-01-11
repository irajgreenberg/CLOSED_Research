/*!  \brief  ProtoGeomBase.h: Abstact Base Geometry class
 ProtoGeomBase.h
 Protobyte Library v02
 
 Created by Ira on 7/23/13.
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

#ifndef PROTO_GEOMBASE_H
#define PROTO_GEOMBASE_H


#ifdef  __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#elif __linux
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>
#define GL_GLEXT_PROTOTYPES
#include <GL/glext.h>
#elif _WIN32
#include <GL/gl.h>
#include <GL/glu.h>
#define GL_GLEXT_PROTOTYPES
#include <GL/glext.h>
#elif _WIN64
#include <GL/gl.h>
#include <GL/glu.h>
#define GL_GLEXT_PROTOTYPES
#include <GL/glext.h>
#endif


#include <iostream>
#include <vector>
#include "ProtoVector3.h"
#include "ProtoFace3.h"
#include "ProtoTuple3.h"
#include "ProtoDimension3.h"
#include "ProtoColor4.h"
#include "ProtoTexture2.h"
#include "ProtoGLInfo.h"
#include <fstream>
#include <sys/stat.h>
#include <sys/types.h>
#include "ProtoGraphicsCore.h"


namespace ijg {


    // for offset into the FBO interleaved buffer (ugly I know!)
#define BUFFER_OFFSET(i) ((void*)(i)) 

    class ProtoGeomBase: public ProtoGraphicsCore{
    protected:
        ProtoTexture2 bumpMap;
        float textureScale;

        virtual void init();
        virtual void calcVerts() = 0;
        virtual void calcInds() = 0;
        virtual void calcFaces(); // probably not necessary to override
        virtual void calcVertexNorms();
        virtual void calcPrimitives();

        void fillDisplayLists();

        // composite guts
        std::vector<ProtoVertex> verts;
        std::vector<ProtoFace3> faces;
        std::vector< ProtoTuple3<int> > inds;

        //primitive guts
        std::vector<float> vertPrims;
        std::vector<unsigned int> indPrims;
        std::vector<float> normPrims;
        std::vector<float> colorPrims;
        std::vector<float> texturePrims;
        std::vector<float> interleavedPrims;

        // Display List var
        GLuint displayListIndex;

        // VBO stuff
        GLuint vboID, indexVBOID;
        
        //shared memory pointer for dynamic VBO's
        float* sharedMemPointer;

        // Utility for extension support
        ProtoGLInfo glInfo;


    public:

        /**********************************
         *    Display Modes for testing   *
         *********************************/
        enum displayMode {
            IMMEDIATE, // begin at 0
            VERTEX_ARRAY,
            VERTEX_ARRAY_INTERLEAVED,
            DISPLAY_LIST,
            VERTEX_BUFFER_OBJECT
        };

        enum renderMode {
            POINT_CLOUD,
            WIREFRAME, // begin at 0
            SURFACE
        };

        ProtoGeomBase();

        ProtoGeomBase(const ProtoVector3& pos, const ProtoVector3& rot, const ProtoDimension3f size,
                const ProtoColor4f col4);

        ProtoGeomBase(const ProtoVector3& pos, const ProtoVector3& rot, const ProtoDimension3f size,
                const std::vector< ProtoColor4f > col4s);

        ProtoGeomBase(const ProtoVector3& pos, const ProtoVector3& rot, const ProtoDimension3f size,
                const ProtoColor4f col4, float textureScale);

        ProtoGeomBase(const ProtoVector3& pos, const ProtoVector3& rot, const ProtoDimension3f size,
                const std::vector< ProtoColor4f > col4s, float textureScale);

        virtual ~ProtoGeomBase();

        virtual void move(const ProtoVector3& v);
        virtual void rotate(const ProtoVector3& r);
        virtual void scale(const ProtoDimension3f& s);

        // vertex arrays are implemented by default
        virtual void display(displayMode mode = VERTEX_BUFFER_OBJECT, renderMode render = SURFACE, float pointSize = 3.5f);

        // setters/getters
        virtual void setPosition(const ProtoVector3& pos);
        virtual void setRotation(const ProtoVector3& rot);
        virtual void setSize(const ProtoDimension3f size);
        virtual void setColor(const ProtoColor4f col4);

        virtual ProtoVector3& getPosition();
        virtual ProtoVector3& getRotation();
        virtual ProtoDimension3f& getSize();
        virtual ProtoColor4f& getColor();

        // a bit dangerous to return references, so be careful
        // justification, you got no 3d if you delete this stuff

        std::vector<ProtoFace3>& getFaces();
        std::vector<ProtoVertex>& getVertices();

        virtual void sortFaces();

        void setTextureScale(float textureScale);
        float getTextureScale() const;
        
        void setBumpMap(ProtoTexture2 bumpMap);
        ProtoTexture2 getBumpMap() const;
        
        // stl exporter
        void exportSTL();


    };

    // setters/getters
    inline void ProtoGeomBase::setPosition(const ProtoVector3& pos) {
        this->pos = pos;
    }

    inline void ProtoGeomBase::setRotation(const ProtoVector3& rot) {
        this->rot = rot;
    }

    inline void ProtoGeomBase::setSize(const ProtoDimension3f size) {
        this->size = size;
    }

    inline void ProtoGeomBase::setColor(const ProtoColor4f col4) {
        this->col4 = col4;
    }

    inline ProtoVector3& ProtoGeomBase::getPosition() {
        return pos;
    }

    inline ProtoVector3& ProtoGeomBase::getRotation() {
        return rot;
    }

    inline ProtoDimension3f& ProtoGeomBase::getSize() {
        return size;
    }

    inline ProtoColor4f& ProtoGeomBase::getColor() {
        return col4;
    }

    inline std::vector<ProtoFace3>& ProtoGeomBase::getFaces() {
        return faces;
    }

    inline std::vector<ProtoVertex>& ProtoGeomBase::getVertices() {
        return verts;
    }

    inline void ProtoGeomBase::setTextureScale(float textureScale) {
        this->textureScale = textureScale;
    }

    inline float ProtoGeomBase::getTextureScale() const {
        return textureScale;
    }

    inline void ProtoGeomBase::setBumpMap(ProtoTexture2 bumpMap) {
        this->bumpMap = bumpMap;
    }

    inline ProtoTexture2 ProtoGeomBase::getBumpMap() const {
        return bumpMap;
    }

}
#endif /* defined(PROTO_GEOMBASE_H) */
