//
//  GeomBase.cpp
//  Protobyte Library Development
//
//  Created by Ira on 2/13/13.
//  Copyright (c) 2013 Ira Greenberg. All rights reserved.
//

#include "GeomBase.h"

//GeomBase::GeomBase() {

//}

GeomBase::GeomBase(const Vector3& pos, const Vector3& rot, const Dimension3<float> size, const Color4<float> col4) :
pos(pos), rot(rot), size(size), col4(col4) {
}

GeomBase::~GeomBase() {

}

void GeomBase::init() {
    calcVerts();
    calcInds();
    calcFaces();
    calcVertexNorms();
    calcPrimitives();

    
    /*
    // VBO stuff
    glGenBuffers(1, &vboID); // Create the buffer ID
    glBindBuffer(GL_ARRAY_BUFFER, vboID); // Bind the buffer (vertex array data)
    int vertsDataSize = sizeof (GLfloat)*10 * faces.size()*3;
    glBufferData(GL_ARRAY_BUFFER, vertsDataSize, NULL, GL_STATIC_DRAW); // allocate space
    glBufferSubData(GL_ARRAY_BUFFER, 0, vertsDataSize, &interleavedPrims[0]); // upload the data

    // set pointers to data
    glNormalPointer(GL_FLOAT, 10 * sizeof (GLfloat), &interleavedPrims[0] + 3);
    glColorPointer(4, GL_FLOAT, 10 * sizeof (GLfloat), &interleavedPrims[0] + 6);
    glVertexPointer(3, GL_FLOAT, 10 * sizeof (GLfloat), &interleavedPrims[0]);
    // vertex data now on GPU

    // now for indices
    // Our Index Buffer, same as above, the variable needs to be accessible wherever we draw
    glGenBuffers(1, &indexVBOID); // Generate buffer
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexVBOID); // Bind the element array buffer
    // Upload the index array, this can be done the same way as above (with NULL as the data, then a 
    // glBufferSubData call, but doing it all at once for convenience)
    int indsDataSize = inds.size()*3 * sizeof (GL_UNSIGNED_INT);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indsDataSize, NULL, GL_STATIC_DRAW); // allocate
    glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, indsDataSize, &indPrims[0]); // upload the data
    */


}

/*void GeomBase::calcFaces() {
    for (int i = 0; i < inds.size(); i++) {
        faces.push_back(Face3(verts.at(inds.at(i).elem0), verts.at(inds.at(i).elem1), verts.at(inds.at(i).elem2)));
    }
}*/

void GeomBase::calcFaces() {
    for (int i = 0; i < inds.size(); i++) {
        faces.push_back(Face3(verts_p.at(inds.at(i).elem0), verts_p.at(inds.at(i).elem1),
                verts_p.at(inds.at(i).elem2)));
    }
}

void GeomBase::calcVertexNorms() {

    for (int i = 0; i < verts.size(); i++) {
        Vector3 v;
        int counter = 0;
        for (int j = 0; j < faces.size(); j++) {
            if (verts_p.at(i) == faces.at(j)[0] || verts_p.at(i) == faces.at(j)[1] ||
                    verts_p.at(i) == faces.at(j)[2]) {
                v += faces.at(j).getNorm();
            }
        }
        v.normalize();
        verts_p.at(i)->setNormal(v);
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
        // fill indiviual primitive arrays
        vertPrims.push_back(verts_p.at(i)->pos.x);
        vertPrims.push_back(verts_p.at(i)->pos.y);
        vertPrims.push_back(verts_p.at(i)->pos.z);

        normPrims.push_back(verts_p.at(i)->getNormal().x);
        normPrims.push_back(verts_p.at(i)->getNormal().y);
        normPrims.push_back(verts_p.at(i)->getNormal().z);

        colorPrims.push_back(verts_p.at(i)->getColor().getR());
        colorPrims.push_back(verts_p.at(i)->getColor().getG());
        colorPrims.push_back(verts_p.at(i)->getColor().getB());
        colorPrims.push_back(verts_p.at(i)->getColor().getA());


        // fill interleaved primitive arrays
        interleavedPrims.push_back(verts_p.at(i)->pos.x);
        interleavedPrims.push_back(verts_p.at(i)->pos.y);
        interleavedPrims.push_back(verts_p.at(i)->pos.z);

        interleavedPrims.push_back(verts_p.at(i)->getNormal().x);
        interleavedPrims.push_back(verts_p.at(i)->getNormal().y);
        interleavedPrims.push_back(verts_p.at(i)->getNormal().z);

        interleavedPrims.push_back(verts_p.at(i)->getColor().getR());
        interleavedPrims.push_back(verts_p.at(i)->getColor().getG());
        interleavedPrims.push_back(verts_p.at(i)->getColor().getB());
        interleavedPrims.push_back(verts_p.at(i)->getColor().getA());
    }


    // explode inds arrays to primitives
    for (int i = 0; i < inds.size(); i++) {
        indPrims.push_back(inds.at(i).elem0);
        indPrims.push_back(inds.at(i).elem1);
        indPrims.push_back(inds.at(i).elem2);
    }

}

// Includes multiple display implementations

/* NOTE:: Drawing will eventually get delegated to a 
 world type class, to enable aggregate face sorting and 
 and primitive processing*/
void GeomBase::display(displayMode mode) {
    // hackity-hack - fix eventually
    static float rx = .2;
    static float ry = .3;
    static float rz = .4;
    glPushMatrix();
    glLoadIdentity();
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
    I think the solution will be doing manual rotations on geometry 
    as compared to modelview matrix transformation and then sorting faces. 
     * See note above above delegating this to a world type class.*/

    switch (mode) {
        case IMMEDIATE:
            for (int i = 0; i < faces.size(); ++i) {
                faces.at(i).display();
            }
            break;

        case VERTEX_ARRAY:

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

            // enable and specify pointers to vertex arrays
            glEnableClientState(GL_VERTEX_ARRAY);
            glEnableClientState(GL_NORMAL_ARRAY);
            glEnableClientState(GL_COLOR_ARRAY);

            // stride is 10 : (x, y, z, nx, ny, nz, r, g, b, a)
            glVertexPointer(3, GL_FLOAT, 10 * sizeof (GLfloat), &interleavedPrims[0]);
            glNormalPointer(GL_FLOAT, 10 * sizeof (GLfloat), &interleavedPrims[0] + 3);
            glColorPointer(4, GL_FLOAT, 10 * sizeof (GLfloat), &interleavedPrims[0] + 6);

            glDrawElements(GL_TRIANGLES, inds.size()*3, GL_UNSIGNED_INT, &indPrims[0]);

            // disable stuff
            glDisableClientState(GL_NORMAL_ARRAY);
            glDisableClientState(GL_COLOR_ARRAY);
            glDisableClientState(GL_VERTEX_ARRAY);
            break;

        case FBO:
            glBindBuffer(GL_ARRAY_BUFFER, vboID);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexVBOID);

            glEnableClientState(GL_COLOR_ARRAY);
            glEnableClientState(GL_NORMAL_ARRAY);
            glEnableClientState(GL_VERTEX_ARRAY);

            // stride is 10 : (x, y, z, nx, ny, nz, r, g, b, a)
            glVertexPointer(3, GL_FLOAT, 10 * sizeof (GLfloat), &interleavedPrims[0]);
            glNormalPointer(GL_FLOAT, 10 * sizeof (GLfloat), &interleavedPrims[0] + 3);
            glColorPointer(4, GL_FLOAT, 10 * sizeof (GLfloat), &interleavedPrims[0] + 6);

            glDrawElements(GL_TRIANGLES, inds.size()*3, GL_UNSIGNED_INT, &indPrims[0]);

            glDisableClientState(GL_COLOR_ARRAY);
            glDisableClientState(GL_NORMAL_ARRAY);
            glDisableClientState(GL_VERTEX_ARRAY);

            break;

    }
    glPopMatrix();
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

