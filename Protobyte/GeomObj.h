//
//  GeomObj.h
//  SFML_simple_renderer_06
//
//  Created by Ira on 2/13/13.
//  Copyright (c) 2013 Ira Greenberg. All rights reserved.
//

#ifndef __SFML_simple_renderer_06__GeomObj__
#define __SFML_simple_renderer_06__GeomObj__

#include <SFML/OpenGL.hpp>
#include <iostream>
#include <vector>
#include "Vector3.h"
#include "Face3.h"
#include "Tuple3.h"
#include "Dimension3.h"
#include "Color3.h"
#include "Color4.h"


class GeomObj {
    
protected:
    Vector3 pos, rot;
    Vector3 spd, rotSpd;
    Dimension3<float> size;
    Color3<float> col3;
    //Color4<float> //col4;
    
    virtual void init() = 0;
    virtual void calcVerts() = 0;
    virtual void calcInds() = 0;
    virtual void calcFaces(); //not necessary to override
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
    
    
public:
   // GeomObj();
    GeomObj(const Vector3& pos, const Vector3& rot, const Dimension3<float> size, const Color3<float> col3);
    virtual ~GeomObj();
    
    void move(const Vector3& v);
    void rotate(const Vector3& r);
    void scale(const Dimension3<float>& s);
    virtual void display();
    
    // setters/getters
    void setPosition(const Vector3& pos);
    void setRotation(const Vector3& rot);
    void setSize(const Dimension3<float> size);
    void setColor(const Color3<float> col3);
    
    Vector3& getPosition();
    Vector3& getRotation();
    Dimension3<float>& getSize();
    Color3<float>& getColor();
    
    // a bit dangerous to return references, so be careful
    // justification, you got no 3d if you delete this stuff
    
    std::vector<Face3>& getFaces();
    std::vector<Vertex>& getVertices();
    
    void sortFaces();
    
    
    
};


#endif /* defined(__SFML_simple_renderer_06__GeomObj__) */
