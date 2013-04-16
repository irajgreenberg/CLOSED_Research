//
//  Face3.h
//  SFML_simple_renderer_03
//
//  Created by Ira on 2/6/13.
//  Copyright (c) 2013 Ira Greenberg. All rights reserved.
//

#ifndef __SFML_simple_renderer_03__Face3__
#define __SFML_simple_renderer_03__Face3__

#ifdef __APPLE__
#include <OpenGL/gl.h>
#elif __linux
#include <GL/gl.h>
#elif defined(_WIN32) || defined(_WIN64)
#include <GL/gl.h>
#endif

#include <vector>
#include "Vertex.h"
#include "Vector3.h"
#include <cmath>
#include <iostream>

namespace proto {

    class Face3 {
    private:
        //Vector3 vecs[3];
        // Vector3 v0, v1, v2;
        Vertex vecs[3];
        //Vertex v0, v1, v2;
        Vertex *v0_p, *v1_p, *v2_p;
        Vector3 norm, centroid;

        void init();

        void calcNorm();
        void calcCentroid();


    public:
        friend std::ostream& operator<<(std::ostream& output, const Face3& face3);

        //Face3(Vertex& v0, Vertex& v1, Vertex& v2);
        Face3(Vertex* v0_p, Vertex* v1_p, Vertex* v2_p);
        void display();

        const Vector3& getNorm() const;
        const Vector3& getCentroid() const;


        //const Vertex& operator[](int index);
        const Vertex* operator[](int index);

    };
}

#endif /* defined(__SFML_simple_renderer_03__Face3__) */
