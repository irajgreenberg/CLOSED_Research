/*!  \brief  ProtoGeom3.h: Abstact Base Geometry class
 ProtoGeom3.h
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

#ifndef PROTO_GEOM3_H
#define PROTO_GEOM3_H


#if defined(_WIN32) || defined(__linux__)
#include <GL/glew.h>
#endif

#include <SFML/OpenGL.hpp>
#include <iostream>
#include <vector>
#include "ProtoVector3.h"
#include "ProtoFace3.h"
#include "ProtoTuple3.h"
#include "ProtoDimension3.h"
#include "ProtoColor4.h"
#include "ProtoTexture2.h"
//#include "ProtoGLInfo.h"
#include <fstream>
#include <sys/stat.h>
#include <sys/types.h>
#include "ProtoShape3.h"


namespace ijg {


    // for offset into the FBO interleaved buffer (ugly I know!)
#define BUFFER_OFFSET(i) ((void*)(i)) 

    class ProtoGeom3: public ProtoShape3{
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
        std::vector<ProtoVertex3> verts;
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
        GLuint vboID, indexVboID;
        
        //shared memory pointer for dynamic VBO's
        float* sharedMemPointer;

        // Utility for extension support
       // ProtoGLInfo glInfo;
        


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

        ProtoGeom3();

        ProtoGeom3(const Vec3f& pos, const Vec3f& rot, const Dim3f size,
                const ProtoColor4f col4);

        ProtoGeom3(const Vec3f& pos, const Vec3f& rot, const Dim3f size,
                const std::vector< ProtoColor4f > col4s);

        ProtoGeom3(const Vec3f& pos, const Vec3f& rot, const Dim3f size,
                const ProtoColor4f col4, float textureScale);

        ProtoGeom3(const Vec3f& pos, const Vec3f& rot, const Dim3f size,
                const std::vector< ProtoColor4f > col4s, float textureScale);

       virtual ~ProtoGeom3();

        virtual void move(const Vec3f& v);
        virtual void rotate(const Vec3f& r);
        virtual void scale(const ProtoDimension3f& s);

        // vertex arrays are implemented by default
        virtual void display(displayMode mode = VERTEX_BUFFER_OBJECT, renderMode render = SURFACE, float pointSize = 3.5f);

        // setters/getters
        virtual void setPosition(const Vec3f& pos);
        virtual void setRotation(const Vec3f& rot);
        virtual void setSize(const ProtoDimension3f size);
        virtual void setColor(const ProtoColor4f col4);

        virtual Vec3f& getPosition();
        virtual Vec3f& getRotation();
        virtual ProtoDimension3f& getSize();
        virtual ProtoColor4f& getColor();

        // a bit dangerous to return references, so be careful
        // justification, you got no 3d if you delete this stuff

        std::vector<ProtoFace3>& getFaces();
        std::vector<ProtoVertex3>& getVertices();

        virtual void sortFaces();   

        void setTextureScale(float textureScale);
        float getTextureScale() const;
        
        void setBumpMap(ProtoTexture2 bumpMap);
        ProtoTexture2 getBumpMap() const;
        
        // stl exporter
//        void exportSTL();
        
        // required by ProtobteRenderer
        GLuint getVboID() const;
        GLuint getIndexVboID() const;
        int getIndicesSize() const;
        


    };

    
     // setters/getters
    inline void ProtoGeom3::setPosition(const Vec3f& pos) {
        this->pos = pos;
    }

    inline void ProtoGeom3::setRotation(const Vec3f& rot) {
        this->rot = rot;
    }

    inline void ProtoGeom3::setSize(const ProtoDimension3f size) {
        this->size = size;
    }

    inline void ProtoGeom3::setColor(const ProtoColor4f col4) {
        this->col4 = col4;
    }

    inline Vec3f& ProtoGeom3::getPosition() {
        return pos;
    }

    inline Vec3f& ProtoGeom3::getRotation() {
        return rot;
    }

    inline ProtoDimension3f& ProtoGeom3::getSize() {
        return size;
    }

    inline ProtoColor4f& ProtoGeom3::getColor() {
        return col4;
    }

    inline std::vector<ProtoFace3>& ProtoGeom3::getFaces() {
        return faces;
    }

    inline std::vector<ProtoVertex3>& ProtoGeom3::getVertices() {
        return verts;
    }

    inline void ProtoGeom3::setTextureScale(float textureScale) {
        this->textureScale = textureScale;
    }

    inline float ProtoGeom3::getTextureScale() const {
        return textureScale;
    }

    inline void ProtoGeom3::setBumpMap(ProtoTexture2 bumpMap) {
        this->bumpMap = bumpMap;
    }

    inline ProtoTexture2 ProtoGeom3::getBumpMap() const {
        return bumpMap;
    }
    
    inline GLuint ProtoGeom3::getVboID() const {
        return vboID;
    }
    
    inline GLuint ProtoGeom3::getIndexVboID() const {
        return indexVboID;
    }
    
    inline int ProtoGeom3::getIndicesSize() const{
        return static_cast<int>(inds.size());
    }
     

}
#endif /* defined(PROTO_GEOM3_H) */
