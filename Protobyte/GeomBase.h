//
//  GeomBase.h
//  Protobyte Library Development
//
//  Created by Ira on 2/13/13.
//  Copyright (c) 2013 Ira Greenberg. All rights reserved.
//

#ifndef __SFML_simple_renderer_06__GeomBase__
#define __SFML_simple_renderer_06__GeomBase__

#include <SFML/OpenGL.hpp>
#include <iostream>
#include <vector>
#include "Vector3.h"
#include "Face3.h"
#include "Tuple3.h"
#include "Dimension3.h"
#include "Color4.h"

class GeomBase {
protected:
    Vector3 pos, rot;
    Vector3 spd, rotSpd;
    Dimension3<float> size;
    Color4<float> col4;

    virtual void init() = 0;
    virtual void calcVerts() = 0;
    virtual void calcInds() = 0;
    virtual void calcFaces(); // probably not necessary to override
    virtual void calcVertexNorms();
    virtual void calcPrimitives();

    // composite guts
    std::vector<Vertex> verts;
    std::vector<Vertex*> verts_p;
    std::vector<Face3> faces;
    std::vector< Tuple3<int> > inds;

    //primitive guts
    std::vector<float> vertPrims;
    std::vector<unsigned int> indPrims;
    std::vector<float> normPrims;
    std::vector<float> colorPrims;
    std::vector<float> interleavedPrims;






public:

    /**********************************
     *    Display Modes for testing   *
     *********************************/
    enum displayMode {
        IMMEDIATE = 0,
        VERTEX_ARRAY = 1,
        VERTEX_ARRAY_INTERLEAVED = 2,
        FBO = 3
    };

    // GeomBase();
    GeomBase(const Vector3& pos, const Vector3& rot, const Dimension3<float> size,
            const Color4<float> col4);
    virtual ~GeomBase();

    void move(const Vector3& v);
    void rotate(const Vector3& r);
    void scale(const Dimension3<float>& s);

    // vertex arrays are implemented by default
    virtual void display(displayMode mode = VERTEX_ARRAY);

    // setters/getters
    void setPosition(const Vector3& pos);
    void setRotation(const Vector3& rot);
    void setSize(const Dimension3<float> size);
    void setColor(const Color4<float> col4);

    Vector3& getPosition();
    Vector3& getRotation();
    Dimension3<float>& getSize();
    Color4<float>& getColor();

    // a bit dangerous to return references, so be careful
    // justification, you got no 3d if you delete this stuff

    std::vector<Face3>& getFaces();
    std::vector<Vertex>& getVertices();

    void sortFaces();



};


#endif /* defined(__SFML_simple_renderer_06__GeomBase__) */
