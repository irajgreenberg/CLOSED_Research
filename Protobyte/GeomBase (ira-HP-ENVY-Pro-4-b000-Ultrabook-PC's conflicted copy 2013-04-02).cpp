//
//  GeomBase.cpp
//  Protobyte Library Development
//
//  Created by Ira on 2/13/13.
//  Copyright (c) 2013 Ira Greenberg. All rights reserved.
//

#include "GeomBase.h"

GeomBase::GeomBase() {
}

GeomBase::GeomBase(const Vector3& pos, const Vector3& rot, const Dimension3<float> size, const Color4<float> col4) :
pos(pos), rot(rot), size(size), col4(col4) {
}

// pass array of colors

GeomBase::GeomBase(const Vector3& pos, const Vector3& rot, const Dimension3<float> size, const std::vector< Color4<float> > col4s) :
pos(pos), rot(rot), size(size), col4s(col4s) {
}

GeomBase::~GeomBase() {
    // glDeleteLists(displayListIndex, 1);
}

void GeomBase::init() {
    GLInfo glInfo;
    // get OpenGL info
    glInfo.getInfo();
    glInfo.printSelf();
    
    calcVerts();
    calcInds();
    calcFaces();
    calcVertexNorms();
    calcPrimitives();
    fillDisplayLists(); // just in case we want to render with display Lists: Data can't be changed though





#ifdef _WIN32
    // check VBO is supported by your video card
    if (GLInfo.isExtensionSupported("GL_ARB_vertex_buffer_object")) {
        // get pointers to GL functions
        glGenBuffersARB = (PFNGLGENBUFFERSARBPROC) wglGetProcAddress("glGenBuffersARB");
        glBindBufferARB = (PFNGLBINDBUFFERARBPROC) wglGetProcAddress("glBindBufferARB");
        glBufferDataARB = (PFNGLBUFFERDATAARBPROC) wglGetProcAddress("glBufferDataARB");
        glBufferSubDataARB = (PFNGLBUFFERSUBDATAARBPROC) wglGetProcAddress("glBufferSubDataARB");
        glDeleteBuffersARB = (PFNGLDELETEBUFFERSARBPROC) wglGetProcAddress("glDeleteBuffersARB");
        glGetBufferParameterivARB = (PFNGLGETBUFFERPARAMETERIVARBPROC) wglGetProcAddress("glGetBufferParameterivARB");
        glMapBufferARB = (PFNGLMAPBUFFERARBPROC) wglGetProcAddress("glMapBufferARB");
        glUnmapBufferARB = (PFNGLUNMAPBUFFERARBPROC) wglGetProcAddress("glUnmapBufferARB");

        // check once again VBO extension
        if (glGenBuffersARB && glBindBufferARB && glBufferDataARB && glBufferSubDataARB &&
                glMapBufferARB && glUnmapBufferARB && glDeleteBuffersARB && glGetBufferParameterivARB) {
            vboSupported = vboUsed = true;
            std::cout << "Video card supports GL_ARB_vertex_buffer_object." << std::endl;
        } else {
            vboSupported = vboUsed = false;
            std::cout << "Video card does NOT support GL_ARB_vertex_buffer_object." << std::endl;
        }
    } else {
        vboSupported = vboUsed = false;
        std::cout << "Video card does NOT support GL_ARB_vertex_buffer_object." << std::endl;
    }
#else // for linux/Mac, do not need to get function pointers, it is up-to-date
    if (glInfo.isExtensionSupported("GL_ARB_vertex_buffer_object")) {
        vboSupported = vboUsed = true;
        std::cout << "Video card supports GL_ARB_vertex_buffer_object." << std::endl;
    } else {
        vboSupported = vboUsed = false;
        std::cout << "Video card does NOT support GL_ARB_vertex_buffer_object." << std::endl;
    }
#endif


    if (vboSupported) {
       // glGenBuffersARB(1, &vboId);
        glGenBuffersARB(1, &vboID); // Create the buffer ID
        glBindBufferARB(GL_ARRAY_BUFFER_ARB, vboID); // Bind the buffer (vertex array data)
        int vertsDataSize = sizeof (float) *interleavedPrims.size();
        glBufferDataARB(GL_ARRAY_BUFFER_ARB, vertsDataSize, NULL, GL_STATIC_DRAW); // allocate space
        glBufferSubDataARB(GL_ARRAY_BUFFER_ARB, 0, vertsDataSize, &interleavedPrims[0]); // upload the data
        //glBufferData(GL_ARRAY_BUFFER, vertsDataSize, &interleavedPrims[0], GL_STATIC_DRAW); // allocate and upload

        //indices data - use GL_ELEMENT_ARRAY_BUFFER
        glGenBuffersARB(1, &indexVBOID); // Generate buffer
        glBindBufferARB(GL_ELEMENT_ARRAY_BUFFER_ARB, indexVBOID); // Bind the element array buffer
        int indsDataSize = inds.size()*3 * sizeof (GL_UNSIGNED_INT);
        glBufferDataARB(GL_ELEMENT_ARRAY_BUFFER_ARB, indsDataSize, NULL, GL_STATIC_DRAW_ARB); // allocate
        glBufferSubDataARB(GL_ELEMENT_ARRAY_BUFFER_ARB, 0, indsDataSize, &indPrims[0]); // upload the data
        //glBufferData(GL_ELEMENT_ARRAY_BUFFER, indsDataSize, &indPrims[0], GL_STATIC_DRAW); // allocate and upload
    }






}

/*void GeomBase::calcFaces() {
    for (int i = 0; i < inds.size(); i++) {
        faces.push_back(Face3(verts.at(inds.at(i).elem0), verts.at(inds.at(i).elem1), verts.at(inds.at(i).elem2)));
    }
}*/

void GeomBase::calcFaces() {
    // pass vertex addresses
    for (int i = 0; i < inds.size(); i++) {
        faces.push_back(Face3(&verts.at(inds.at(i).elem0), &verts.at(inds.at(i).elem1),
                &verts.at(inds.at(i).elem2)));
    }
}

void GeomBase::calcVertexNorms() {

    for (int i = 0; i < verts.size(); i++) {
        Vector3 v;
        for (int j = 0; j < faces.size(); j++) {
            if (&verts.at(i) == faces.at(j)[0] || &verts.at(i) == faces.at(j)[1] ||
                    &verts.at(i) == faces.at(j)[2]) {
                v += faces.at(j).getNorm();
            }
        }
        v.normalize();
        verts.at(i).setNormal(v);
    }
}

void GeomBase::sortFaces() {
    bool swapped = true;
    int j = 0;
    //Face3 tmp;
    while (swapped) {
        swapped = false;
        j++;
        for (int i = 0; i < faces.size() - j; i++) {
            if (faces.at(i).getCentroid().z > faces.at(i + 1).getCentroid().z) {
                Face3 tmp = faces.at(i);
                faces.at(i) = faces.at(i + 1);
                faces.at(i + 1) = tmp;
                swapped = true;
            }
        }
    }
}

void GeomBase::calcPrimitives() {

    for (int i = 0; i < verts.size(); i++) {

        vertPrims.push_back(verts.at(i).pos.x);
        vertPrims.push_back(verts.at(i).pos.y);
        vertPrims.push_back(verts.at(i).pos.z);

        normPrims.push_back(verts.at(i).getNormal().x);
        normPrims.push_back(verts.at(i).getNormal().y);
        normPrims.push_back(verts.at(i).getNormal().z);

        colorPrims.push_back(verts.at(i).getColor().getR());
        colorPrims.push_back(verts.at(i).getColor().getG());
        colorPrims.push_back(verts.at(i).getColor().getB());
        colorPrims.push_back(verts.at(i).getColor().getA());


        // fill interleaved primitive arrays
        interleavedPrims.push_back(verts.at(i).pos.x);
        interleavedPrims.push_back(verts.at(i).pos.y);
        interleavedPrims.push_back(verts.at(i).pos.z);

        interleavedPrims.push_back(verts.at(i).getNormal().x);
        interleavedPrims.push_back(verts.at(i).getNormal().y);
        interleavedPrims.push_back(verts.at(i).getNormal().z);

        interleavedPrims.push_back(verts.at(i).getColor().getR());
        interleavedPrims.push_back(verts.at(i).getColor().getG());
        interleavedPrims.push_back(verts.at(i).getColor().getB());
        interleavedPrims.push_back(verts.at(i).getColor().getA());
    }


    // explode inds arrays to primitives
    for (int i = 0; i < inds.size(); i++) {
        indPrims.push_back(inds.at(i).elem0);
        indPrims.push_back(inds.at(i).elem1);
        indPrims.push_back(inds.at(i).elem2);
    }
}

void GeomBase::fillDisplayLists() {
    glNewList(displayListIndex, GL_COMPILE);
    for (int i = 0; i < faces.size(); ++i) {
        faces.at(i).display();
    }
    glEndList();
}
// Includes multiple display implementations

/* NOTE:: Drawing will eventually get delegated to a 
 world type class, to enable aggregate face sorting and 
 and primitive processing*/
void GeomBase::display(displayMode mode, renderMode render) {
    switch (render) {
        case WIREFRAME:

            glDisable(GL_CULL_FACE);
            glDisable(GL_LIGHTING);
            glLineWidth(1.0f);
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            break;

        case SURFACE:
            glEnable(GL_CULL_FACE);
            glEnable(GL_LIGHTING);
            glPolygonMode(GL_FRONT, GL_FILL);
            break;
    }
    // hackity-hack - fix eventually
    static float rx = .02;
    static float ry = .03;
    static float rz = .04;
    glPushMatrix();
    //glLoadIdentity();
    glTranslatef(pos.x, pos.y, pos.z);
    glScalef(size.w, size.h, size.d);
    glRotatef(rot.x, 1, 0, 0); // x-axis
    glRotatef(rot.y, 0, 1, 0); // y-axis
    glRotatef(rot.z, 0, 0, 1); // z-axis
    rot.x += rx;
    rot.y += ry;
    rot.z += rz;

    //sortFaces(); 
    /* NOTE:: sorting here is not solving self-overlap highlighting with alpha
    possible solution will be doing manual rotations on geometry 
    (as compared to modelview matrix transformation) and then sorting faces. 
     * See note above above delegating this to a world type class.*/

    switch (mode) {
        case IMMEDIATE:
            //glDeleteLists(displayListIndex, 1);
            for (int i = 0; i < faces.size(); ++i) {
                faces.at(i).display();
            }
            break;

        case VERTEX_ARRAY:
            // ensure data not bound to VBO
            glBindBufferARB(GL_ARRAY_BUFFER_ARB, 0);
            glBindBufferARB(GL_ELEMENT_ARRAY_BUFFER_ARB, 0);

            // ensure Diaplsy list released 
            glDeleteLists(displayListIndex, 1);

            glEnableClientState(GL_NORMAL_ARRAY);
            glEnableClientState(GL_COLOR_ARRAY);
            glEnableClientState(GL_VERTEX_ARRAY);


            glNormalPointer(GL_FLOAT, 0, &normPrims[0]);
            glColorPointer(4, GL_FLOAT, 0, &colorPrims[0]);
            glVertexPointer(3, GL_FLOAT, 0, &vertPrims[0]);

            glDrawElements(GL_TRIANGLES, inds.size()*3, GL_UNSIGNED_INT, &indPrims[0]);

            // deactivate arrays after drawing
            glDisableClientState(GL_VERTEX_ARRAY); // disable vertex arrays
            glDisableClientState(GL_NORMAL_ARRAY);
            glDisableClientState(GL_COLOR_ARRAY);
            break;

        case VERTEX_ARRAY_INTERLEAVED:
            // ensure data not bound to VBO
            glBindBufferARB(GL_ARRAY_BUFFER_ARB, 0);
            glBindBufferARB(GL_ELEMENT_ARRAY_BUFFER_ARB, 0);

            // ensure Diaplsy list released 
            glDeleteLists(displayListIndex, 1);

            glEnableClientState(GL_NORMAL_ARRAY);
            glEnableClientState(GL_COLOR_ARRAY);
            glEnableClientState(GL_VERTEX_ARRAY);

            // stride is 10 : (x, y, z, nx, ny, nz, r, g, b, a)
            // // vertices, normals, color
            glVertexPointer(3, GL_FLOAT, 10 * sizeof (GLfloat), &interleavedPrims[0]);
            glNormalPointer(GL_FLOAT, 10 * sizeof (GLfloat), &interleavedPrims[0] + 3);
            glColorPointer(4, GL_FLOAT, 10 * sizeof (GLfloat), &interleavedPrims[0] + 6);

            glDrawElements(GL_TRIANGLES, inds.size()*3, GL_UNSIGNED_INT, &indPrims[0]);

            // disable stuff
            glDisableClientState(GL_NORMAL_ARRAY);
            glDisableClientState(GL_COLOR_ARRAY);
            glDisableClientState(GL_VERTEX_ARRAY);
            break;

        case DISPLAY_LIST:
            glCallList(displayListIndex);
            break;

        case VERTEX_BUFFER_OBJECT:
            //glDeleteLists(displayListIndex, 1);

            // make sure data is bound to buffer
            glBindBuffer(GL_ARRAY_BUFFER, vboID);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexVBOID);

            // enable and specify pointers to vertex arrays
            glEnableClientState(GL_VERTEX_ARRAY);
            glEnableClientState(GL_NORMAL_ARRAY);
            glEnableClientState(GL_COLOR_ARRAY);

            // stride is 10 : (x, y, z, nx, ny, nz, r, g, b, a)

            // vertices, normals, color
            glVertexPointer(3, GL_FLOAT, 10 * sizeof (GLfloat), BUFFER_OFFSET(0));
            glNormalPointer(GL_FLOAT, 10 * sizeof (GLfloat), BUFFER_OFFSET(12)); // step over 3 bytes
            glColorPointer(4, GL_FLOAT, 10 * sizeof (GLfloat), BUFFER_OFFSET(24)); // step over 6 bytes

            glDrawElements(GL_TRIANGLES, inds.size()*3, GL_UNSIGNED_INT, BUFFER_OFFSET(0));

            glDisableClientState(GL_NORMAL_ARRAY);
            glDisableClientState(GL_COLOR_ARRAY);
            glDisableClientState(GL_VERTEX_ARRAY);

            // free pointers to data
            glBindBufferARB(GL_ARRAY_BUFFER_ARB, 0);
            glBindBufferARB(GL_ELEMENT_ARRAY_BUFFER_ARB, 0);

            break;

    }
    glPopMatrix();

    // reset fill and lighting
    glEnable(GL_LIGHTING);
    glPolygonMode(GL_FRONT, GL_FILL);
}

void GeomBase::move(const Vector3& v) {
    pos += v;
}

void GeomBase::rotate(const Vector3& r) {
    rot += r;
}

void GeomBase::scale(const Dimension3<float>& s) {
    size += s;
}

// setters/getters

void GeomBase::setPosition(const Vector3& pos) {
    this->pos = pos;
}

void GeomBase::setRotation(const Vector3& rot) {
    this->rot = rot;
}

void GeomBase::setSize(const Dimension3<float> size) {
    this->size = size;
}

void GeomBase::setColor(const Color4<float> col4) {
    this->col4 = col4;
}

Vector3& GeomBase::getPosition() {
    return pos;
}

Vector3& GeomBase::getRotation() {
    return rot;
}

Dimension3<float>& GeomBase::getSize() {
    return size;
}

Color4<float>& GeomBase::getColor() {
    return col4;
}

std::vector<Face3>& GeomBase::getFaces() {
    return faces;
}

std::vector<Vertex>& GeomBase::getVertices() {
    return verts;
}

