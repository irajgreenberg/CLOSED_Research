//
//  GeomBase.h
//  Protobyte Library Development
//
//  Created by Ira on 2/13/13.
//  Copyright (c) 2013 Ira Greenberg. All rights reserved.
//

#ifndef __SFML_simple_renderer_06__GeomBase__
#define __SFML_simple_renderer_06__GeomBase__


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
#include "Vector3.h"
#include "Face3.h"
#include "Tuple3.h"
#include "Dimension3.h"
#include "Color4.h"
#include "Texture2.h"
#include "GLInfo.h"


namespace proto {


    // for offset into the FBO interleaved buffer (ugly I know!)
#define BUFFER_OFFSET(i) ((void*)(i)) 

    class GeomBase {
    protected:

        Vector3 pos, rot;
        Vector3 spd, rotSpd;
        Dimension3f size;
        Color4f col4;
        std::vector< Color4f > col4s;
        Texture2 bumpMap;
        float textureScale;

        virtual void init();
        virtual void calcVerts() = 0;
        virtual void calcInds() = 0;
        virtual void calcFaces(); // probably not necessary to override
        virtual void calcVertexNorms();
        virtual void calcPrimitives();

        void fillDisplayLists();

        // composite guts
        std::vector<Vertex> verts;
        std::vector<Face3> faces;
        std::vector< Tuple3<int> > inds;

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

        // Utility for extension support
        GLInfo glInfo;


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

        GeomBase();

        GeomBase(const Vector3& pos, const Vector3& rot, const Dimension3f size,
                const Color4f col4);

        GeomBase(const Vector3& pos, const Vector3& rot, const Dimension3f size,
                const std::vector< Color4f > col4s);

        GeomBase(const Vector3& pos, const Vector3& rot, const Dimension3f size,
                const Color4f col4, float textureScale);

        GeomBase(const Vector3& pos, const Vector3& rot, const Dimension3f size,
                const std::vector< Color4f > col4s, float textureScale);

        virtual ~GeomBase();

        virtual void move(const Vector3& v);
        virtual void rotate(const Vector3& r);
        virtual void scale(const Dimension3f& s);

        // vertex arrays are implemented by default
        virtual void display(displayMode mode = VERTEX_ARRAY, renderMode render = SURFACE, float pointSize = 3.5f);

        // setters/getters
        virtual void setPosition(const Vector3& pos);
        virtual void setRotation(const Vector3& rot);
        virtual void setSize(const Dimension3f size);
        virtual void setColor(const Color4f col4);

        virtual Vector3& getPosition();
        virtual Vector3& getRotation();
        virtual Dimension3f& getSize();
        virtual Color4f& getColor();

        // a bit dangerous to return references, so be careful
        // justification, you got no 3d if you delete this stuff

        std::vector<Face3>& getFaces();
        std::vector<Vertex>& getVertices();

        virtual void sortFaces();

        void setTextureScale(float textureScale);
        float getTextureScale() const;
        
        void setBumpMap(Texture2 bumpMap);
        Texture2 getBumpMap() const;



    };

    // setters/getters

    inline void GeomBase::setPosition(const Vector3& pos) {
        this->pos = pos;
    }

    inline void GeomBase::setRotation(const Vector3& rot) {
        this->rot = rot;
    }

    inline void GeomBase::setSize(const Dimension3f size) {
        this->size = size;
    }

    inline void GeomBase::setColor(const Color4f col4) {
        this->col4 = col4;
    }

    inline Vector3& GeomBase::getPosition() {
        return pos;
    }

    inline Vector3& GeomBase::getRotation() {
        return rot;
    }

    inline Dimension3f& GeomBase::getSize() {
        return size;
    }

    inline Color4f& GeomBase::getColor() {
        return col4;
    }

    inline std::vector<Face3>& GeomBase::getFaces() {
        return faces;
    }

    inline std::vector<Vertex>& GeomBase::getVertices() {
        return verts;
    }

    inline void GeomBase::setTextureScale(float textureScale) {
        this->textureScale = textureScale;
    }

    inline float GeomBase::getTextureScale() const {
        return textureScale;
    }

    inline void GeomBase::setBumpMap(Texture2 bumpMap) {
        this->bumpMap = bumpMap;
    }

    inline Texture2 GeomBase::getBumpMap() const {
        return bumpMap;
    }

}
#endif /* defined(__SFML_simple_renderer_06__GeomBase__) */
