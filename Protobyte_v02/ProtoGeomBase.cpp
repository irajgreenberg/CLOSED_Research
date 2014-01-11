/*!  \brief  ProtoGeomBase.cpp: Abstact Base Geometry class
 ProtoGeomBase.cpp
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

#include "ProtoGeomBase.h"


using namespace ijg;

ProtoGeomBase::ProtoGeomBase() {
}


// pass array of colors

ProtoGeomBase::ProtoGeomBase(const ProtoVector3& pos, const ProtoVector3& rot, const ProtoDimension3f size, const ProtoColor4f col4) :
ProtoGraphicsCore(pos, rot, size, col4) {
}

ProtoGeomBase::ProtoGeomBase(const ProtoVector3& pos, const ProtoVector3& rot, const ProtoDimension3f size, const std::vector< ProtoColor4f > col4s) :
ProtoGraphicsCore(pos, rot, size, col4s) {
}

ProtoGeomBase::ProtoGeomBase(const ProtoVector3& pos, const ProtoVector3& rot, const ProtoDimension3f size, const ProtoColor4f col4, float textureScale) :
ProtoGraphicsCore(pos, rot, size, col4), textureScale(textureScale) {
}

ProtoGeomBase::ProtoGeomBase(const ProtoVector3& pos, const ProtoVector3& rot, const ProtoDimension3f size,
        const std::vector< ProtoColor4f > col4s, float textureScale) :
ProtoGraphicsCore(pos, rot, size, col4s), textureScale(textureScale) {
}

ProtoGeomBase::~ProtoGeomBase() {
    // glDeleteLists(displayListIndex, 1);
}

void ProtoGeomBase::init() {
    calcVerts();
    calcInds();
    calcFaces();
    calcVertexNorms();
    calcPrimitives();
    fillDisplayLists(); // just in case we want to render with display Lists: Data can't be changed though

#ifdef  __linux__
    // Call to utilize all the neato things in Linux/Win - loads extensions
    glewInit();

    /* screwy and not working
    if (glInfo.isExtensionSupported("GL_vertex_buffer_object")) {
        //vboSupported = vboUsed = true;
        std::cout << "Video card supports GL_vertex_buffer_object." << std::endl;
    } else {
        //vboSupported = vboUsed = false;
        std::cout << "Video card does NOT support GL_vertex_buffer_object." << std::endl;
    }*/
#endif
    glGenBuffers(1, &vboID); // Create the buffer ID
    glBindBuffer(GL_ARRAY_BUFFER, vboID); // Bind the buffer (vertex array data)
    int vertsDataSize = sizeof (float) *interleavedPrims.size();
    glBufferData(GL_ARRAY_BUFFER, vertsDataSize, NULL, GL_STREAM_DRAW); // allocate space
    glBufferSubData(GL_ARRAY_BUFFER, 0, vertsDataSize, &interleavedPrims[0]); // upload the data
    //glBufferData(GL_ARRAY_BUFFER, vertsDataSize, &interleavedPrims[0], GL_STATIC_DRAW); // allocate and upload
    //sharedMemPointer = (float*) glMapBuffer(GL_ARRAY_BUFFER, GL_READ_WRITE);
    //std::cout << "sharedMemPointer = " << sharedMemPointer << std::endl;

    //indices data - use GL_ELEMENT_ARRAY_BUFFER
    glGenBuffers(1, &indexVBOID); // Generate buffer
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexVBOID); // Bind the element array buffer
    int indsDataSize = inds.size()*3 * sizeof (GL_UNSIGNED_INT);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indsDataSize, NULL, GL_DYNAMIC_DRAW); // allocate
    glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, indsDataSize, &indPrims[0]); // upload the data
    //glBufferData(GL_ELEMENT_ARRAY_BUFFER, indsDataSize, &indPrims[0], GL_STATIC_DRAW); // allocate and upload

    //    if (glMapBuffer && glUnmapBuffer) {
    //        //std::cout << "glMapBuffer is supported" << std::endl;
    //    }
}

void ProtoGeomBase::calcFaces() {
    // pass vertex addresses
    for (int i = 0; i < inds.size(); i++) {
        faces.push_back(ProtoFace3(&verts.at(inds.at(i).elem0), &verts.at(inds.at(i).elem1),
                &verts.at(inds.at(i).elem2)));
    }
}

void ProtoGeomBase::calcVertexNorms() {

    for (int i = 0; i < verts.size(); i++) {
        ProtoVector3 v;
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

void ProtoGeomBase::sortFaces() {
    bool swapped = true;
    int j = 0;
    //ProtoFace3 tmp;
    while (swapped) {
        swapped = false;
        j++;
        for (int i = 0; i < faces.size() - j; i++) {
            if (faces.at(i).getCentroid().z > faces.at(i + 1).getCentroid().z) {
                ProtoFace3 tmp = faces.at(i);
                faces.at(i) = faces.at(i + 1);
                faces.at(i + 1) = tmp;
                swapped = true;
            }
        }
    }
}

void ProtoGeomBase::calcPrimitives() {
    vertPrims.resize(verts.size()*3);
    normPrims.resize(verts.size()*3);
    colorPrims.resize(verts.size()*4);
    texturePrims.resize(verts.size()*2);
    interleavedPrims.resize(verts.size()*12);

    indPrims.resize(inds.size()*3);

    for (int i = 0, j = 0, k = 0, l = 0, m = 0, n = 0; i < verts.size(); i++) {

        // fill individual primitive arrays - eventually remove
        vertPrims.at(j++) = verts.at(i).pos.x;
        vertPrims.at(j++) = verts.at(i).pos.y;
        vertPrims.at(j++) = verts.at(i).pos.z;

        normPrims.at(k++) = verts.at(i).getNormal().x;
        normPrims.at(k++) = verts.at(i).getNormal().y;
        normPrims.at(k++) = verts.at(i).getNormal().z;

        colorPrims.at(l++) = verts.at(i).getColor().getR();
        colorPrims.at(l++) = verts.at(i).getColor().getG();
        colorPrims.at(l++) = verts.at(i).getColor().getB();
        colorPrims.at(l++) = verts.at(i).getColor().getA();

        texturePrims.at(m++) = verts.at(i).getUV().elem0;
        texturePrims.at(m++) = verts.at(i).getUV().elem1;

        // fill interleaved primitive arrays
        interleavedPrims.at(n++) = verts.at(i).pos.x;
        interleavedPrims.at(n++) = verts.at(i).pos.y;
        interleavedPrims.at(n++) = verts.at(i).pos.z;

        interleavedPrims.at(n++) = verts.at(i).getNormal().x;
        interleavedPrims.at(n++) = verts.at(i).getNormal().y;
        interleavedPrims.at(n++) = verts.at(i).getNormal().z;

        interleavedPrims.at(n++) = verts.at(i).getColor().getR();
        interleavedPrims.at(n++) = verts.at(i).getColor().getG();
        interleavedPrims.at(n++) = verts.at(i).getColor().getB();
        interleavedPrims.at(n++) = verts.at(i).getColor().getA();

        interleavedPrims.at(n++) = verts.at(i).getUV().elem0;
        interleavedPrims.at(n++) = verts.at(i).getUV().elem1;
    }

    //    std::cout << "verts.size() = " << verts.size() << std::endl;
    //    std::cout << "interleavedPrims.size()/12 = " << interleavedPrims.size()/12 << std::endl;


    // explode inds arrays to primitives
    for (int i = 0, j = 0; i < inds.size(); i++) {
        indPrims.at(j++) = inds.at(i).elem0;
        indPrims.at(j++) = inds.at(i).elem1;
        indPrims.at(j++) = inds.at(i).elem2;
    }
}

void ProtoGeomBase::fillDisplayLists() {
    glNewList(displayListIndex, GL_COMPILE);
    for (int i = 0; i < faces.size(); ++i) {
        faces.at(i).display();
    }
    glEndList();
}
// Includes multiple display implementations

/* NOTE:: Drawing will/MAY eventually get delegated to a 
 world type class, to enable aggregate face sorting and 
 and primitive processing*/
void ProtoGeomBase::display(displayMode mode, renderMode render, float pointSize) {
    switch (render) {
        case POINT_CLOUD:
            glDisable(GL_CULL_FACE);
            glDisable(GL_LIGHTING);
            glPointSize(pointSize);
            break;

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
    glRotatef(rot.x, 1, 0, 0); // x-axis
    glRotatef(rot.y, 0, 1, 0); // y-axis
    glRotatef(rot.z, 0, 0, 1); // z-axis
    glScalef(size.w, size.h, size.d);




    //rot.x += rx;
    //rot.y += ry;
    //rot.z += rz;

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
            glBindBuffer(GL_ARRAY_BUFFER, 0);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

            // ensure Diaplsy list released 
            glDeleteLists(displayListIndex, 1);

            glEnableClientState(GL_NORMAL_ARRAY);
            glEnableClientState(GL_COLOR_ARRAY);
            glEnableClientState(GL_VERTEX_ARRAY);
            glEnableClientState(GL_TEXTURE_COORD_ARRAY);


            glNormalPointer(GL_FLOAT, 0, &normPrims[0]);
            glColorPointer(4, GL_FLOAT, 0, &colorPrims[0]);
            glVertexPointer(3, GL_FLOAT, 0, &vertPrims[0]);
            glTexCoordPointer(2, GL_FLOAT, 0, &texturePrims[0]);

            if (render == POINT_CLOUD) {
                glDrawElements(GL_POINTS, inds.size()*3, GL_UNSIGNED_INT, &indPrims[0]);
            } else {
                glDrawElements(GL_TRIANGLES, inds.size()*3, GL_UNSIGNED_INT, &indPrims[0]);


            }

            // deactivate arrays after drawing
            glDisableClientState(GL_VERTEX_ARRAY); // disable vertex arrays
            glDisableClientState(GL_NORMAL_ARRAY);
            glDisableClientState(GL_COLOR_ARRAY);
            glDisableClientState(GL_TEXTURE_COORD_ARRAY);
            break;

        case VERTEX_ARRAY_INTERLEAVED:
            // ensure data not bound to VBO
            glBindBuffer(GL_ARRAY_BUFFER, 0);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

            // ensure Diaplsy list released 
            glDeleteLists(displayListIndex, 1);

            glEnableClientState(GL_NORMAL_ARRAY);
            glEnableClientState(GL_COLOR_ARRAY);
            glEnableClientState(GL_VERTEX_ARRAY);
            glEnableClientState(GL_TEXTURE_COORD_ARRAY);

            // stride is 12 : (x, y, z, nx, ny, nz, r, g, b, a, u, v)
            // // vertices, normals, color, texture
            glVertexPointer(3, GL_FLOAT, 12 * sizeof (GLfloat), &interleavedPrims[0]);
            glNormalPointer(GL_FLOAT, 12 * sizeof (GLfloat), &interleavedPrims[0] + 3);
            glColorPointer(4, GL_FLOAT, 12 * sizeof (GLfloat), &interleavedPrims[0] + 6);
            glTexCoordPointer(2, GL_FLOAT, 12 * sizeof (GLfloat), &interleavedPrims[0] + 10);

            if (render == POINT_CLOUD) {
                glDrawElements(GL_POINTS, inds.size()*3, GL_UNSIGNED_INT, &indPrims[0]);
            } else {
                glDrawElements(GL_TRIANGLES, inds.size()*3, GL_UNSIGNED_INT, &indPrims[0]);
            }

            // disable stuff
            glDisableClientState(GL_NORMAL_ARRAY);
            glDisableClientState(GL_COLOR_ARRAY);
            glDisableClientState(GL_VERTEX_ARRAY);
            glDisableClientState(GL_TEXTURE_COORD_ARRAY);
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
            glEnableClientState(GL_TEXTURE_COORD_ARRAY);

            // stride is 12 : (x, y, z, nx, ny, nz, r, g, b, a, u, v)
            // vertices, normals, color
            glVertexPointer(3, GL_FLOAT, 12 * sizeof (GLfloat), BUFFER_OFFSET(0));
            glNormalPointer(GL_FLOAT, 12 * sizeof (GLfloat), BUFFER_OFFSET(12)); // step over 3 bytes
            glColorPointer(4, GL_FLOAT, 12 * sizeof (GLfloat), BUFFER_OFFSET(24)); // step over 6 bytes
            glTexCoordPointer(2, GL_FLOAT, 12 * sizeof (GLfloat), BUFFER_OFFSET(40)); // step over 10 bytes

            if (render == POINT_CLOUD) {
                glDrawElements(GL_POINTS, inds.size()*3, GL_UNSIGNED_INT, BUFFER_OFFSET(0));
            } else {
                glDrawElements(GL_TRIANGLES, inds.size()*3, GL_UNSIGNED_INT, BUFFER_OFFSET(0));
            }

            glDisableClientState(GL_NORMAL_ARRAY);
            glDisableClientState(GL_COLOR_ARRAY);
            glDisableClientState(GL_VERTEX_ARRAY);
            glDisableClientState(GL_TEXTURE_COORD_ARRAY);

            // free pointers to data
            glBindBuffer(GL_ARRAY_BUFFER, 0);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

            break;

    }
    glPopMatrix();

    // reset fill and lighting
    glEnable(GL_LIGHTING);
    glPolygonMode(GL_FRONT, GL_FILL);

}

void ProtoGeomBase::move(const ProtoVector3& v) {
    pos += v;
}

void ProtoGeomBase::rotate(const ProtoVector3& r) {
    rot += r;
}

void ProtoGeomBase::scale(const ProtoDimension3f& s) {
    size += s;
}

// this needs to be TOTALLY reworked (binary implementation as well!!!)

void ProtoGeomBase::exportSTL() {
    if (mkdir("../exportData", 0777) == -1)//creating a directory
    {
        //std::cout << "STL file Successfully Written" << std::endl;
        //std::cerr<<"Error :  "<< strerror (errno)<< std::endl;
        //exit(1);
    }
    std::ofstream myfile;
    myfile.open("../exportData/geomData.STL");

    myfile << "solid PROTOBYTE\n";
    for (int i = 0; i < faces.size(); i++) {
        myfile << std::scientific << std::setprecision(7) << "\tfacet normal " <<
                faces[i].getNorm().x << " " << faces[i].getNorm().y << " " << faces[i].getNorm().z << "\n" <<
                "\t\touter loop\n" <<
                "\t\t\tvertex " << faces[i].v0_p->pos.x << " " << faces[i].v0_p->pos.y << " " << faces[i].v0_p->pos.z << "\n" <<
                "\t\t\tvertex " << faces[i].v1_p->pos.x << " " << faces[i].v1_p->pos.y << " " << faces[i].v1_p->pos.z << "\n" <<
                "\t\t\tvertex " << faces[i].v2_p->pos.x << " " << faces[i].v2_p->pos.y << " " << faces[i].v2_p->pos.z << "\n" <<
                "\t\tendloop\n" <<
                "\tendfacet\n";
    }
    myfile << "endsolid PROTOBYTE\n";

    myfile.close();
    std::cout << "STL file Successfully Written" << std::endl;
}



