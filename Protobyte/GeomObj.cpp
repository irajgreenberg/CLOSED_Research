//
//  GeomObj.cpp
//  SFML_simple_renderer_06
//
//  Created by Ira on 2/13/13.
//  Copyright (c) 2013 Ira Greenberg. All rights reserved.
//

#include "GeomObj.h"

//GeomObj::GeomObj() {

//}

GeomObj::GeomObj(const Vector3& pos, const Vector3& rot, const Dimension3<float> size, const Color4<int> col4) :
pos(pos), rot(rot), size(size), col4(col4) {
}

GeomObj::~GeomObj() {

}

/*void GeomObj::calcFaces() {
    for (int i = 0; i < inds.size(); i++) {
        faces.push_back(Face3(verts.at(inds.at(i).elem0), verts.at(inds.at(i).elem1), verts.at(inds.at(i).elem2)));
    }
}*/

void GeomObj::calcFaces() {
    for (int i = 0; i < inds.size(); i++) {
        faces.push_back(Face3(verts_p.at(inds.at(i).elem0), verts_p.at(inds.at(i).elem1), verts_p.at(inds.at(i).elem2)));
    }
}

void GeomObj::calcVertexNorms() {

    for (int i = 0; i < verts.size(); i++) {
        Vector3 v;
        int counter = 0;
        for (int j = 0; j < faces.size(); j++) {
            if (verts_p.at(i) == faces.at(j)[0] || verts_p.at(i) == faces.at(j)[1] || verts_p.at(i) == faces.at(j)[2]) {
                v += faces.at(j).getNorm();
                //counter++;
            }
        }
        v.normalize();
        verts_p.at(i)->setNormal(v);
    }
}

void GeomObj::sortFaces() {
    bool swapped = true;
    int j = 0;
    //Face3 tmp;
    while (swapped) {
        swapped = false;
        j++;
        for (int i = 0; i <faces.size() - j; i++) {
            if (faces.at(i).getCentroid().z > faces.at(i + 1).getCentroid().z) {
                Face3 tmp = faces.at(i);
                faces.at(i) = faces.at(i + 1);
                faces.at(i + 1) = tmp;
                swapped = true;
            }
        }
    }
}

void GeomObj::calcPrimitives() {
   /* for (int i = 0; i <verts_p.size(); i++) {
        vecPrims.push_back(verts_p.at(i)->pos.x);
        vecPrims.push_back(verts_p.at(i)->pos.y);
        vecPrims.push_back(verts_p.at(i)->pos.z);
    }*/
    
    for (int i = 0; i <faces.size(); i++) {
        vecPrims.push_back(faces.at(i)[0]->pos.x);
        vecPrims.push_back(faces.at(i)[0]->pos.y);
        vecPrims.push_back(faces.at(i)[0]->pos.z);
        vecPrims.push_back(faces.at(i)[1]->pos.x);
        vecPrims.push_back(faces.at(i)[1]->pos.y);
        vecPrims.push_back(faces.at(i)[1]->pos.z);
        vecPrims.push_back(faces.at(i)[2]->pos.x);
        vecPrims.push_back(faces.at(i)[2]->pos.y);
        vecPrims.push_back(faces.at(i)[2]->pos.z);
        
        normPrims.push_back(faces.at(i)[0]->getNormal().x);
        normPrims.push_back(faces.at(i)[0]->getNormal().y);
        normPrims.push_back(faces.at(i)[0]->getNormal().z);
        normPrims.push_back(faces.at(i)[1]->getNormal().x);
        normPrims.push_back(faces.at(i)[1]->getNormal().y);
        normPrims.push_back(faces.at(i)[1]->getNormal().z);
        normPrims.push_back(faces.at(i)[2]->getNormal().x);
        normPrims.push_back(faces.at(i)[2]->getNormal().y);
        normPrims.push_back(faces.at(i)[2]->getNormal().z);
        
    }

}

/*void GeomObj::display() {
    // hackity-hack - fix eventually
    static float rx = .2;
    static float ry = .3;
    static float rz = .4;
    sortFaces();
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
   

    glEnableClientState(GL_NORMAL_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glEnableClientState(GL_VERTEX_ARRAY);
    glNormalPointer(GL_FLOAT, 0, normals2);
    glColorPointer(3, GL_FLOAT, 0, colors2);
    glVertexPointer(3, GL_FLOAT, 0, vertices2);


    // draw a cube
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, indices);
    glPopMatrix();
    // deactivate vertex arrays after drawing
    glDisableClientState(GL_VERTEX_ARRAY); // disable vertex arrays
    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_NORMAL_ARRAY);
}*/

void GeomObj::display() {
    // hackity-hack - fix eventually
    static float rx = .2;
    static float ry = .3;
    static float rz = .4;
    sortFaces();
    glPopMatrix();
    glLoadIdentity();
    glTranslatef(pos.x, pos.y, pos.z);
    glScalef(size.w, size.h, size.d);
    glRotatef(rot.x, 1, 0, 0); // x-axis
    glRotatef(rot.y, 0, 1, 0); // y-axis
    glRotatef(rot.z, 0, 0, 1); // z-axis
    rot.x += rx;
    rot.y += ry;
    rot.z += rz;
    for (int i = 0; i < faces.size(); ++i) {
        faces.at(i).display();
    }
    glPushMatrix();
}

void GeomObj::move(const Vector3& v) {
    pos += v;
}

void GeomObj::rotate(const Vector3& r) {
    rot += r;
}

void GeomObj::scale(const Dimension3<float>& s) {
    size += s;
}

// setters/getters

void GeomObj::setPosition(const Vector3& pos) {
    this->pos = pos;
}

void GeomObj::setRotation(const Vector3& rot) {
    this->rot = rot;
}

void GeomObj::setSize(const Dimension3<float> size) {
    this->size = size;
}

void GeomObj::setColor(const Color4<int> col4) {
    this->col4 = col4;
}

Vector3& GeomObj::getPosition() {
    return pos;
}

Vector3& GeomObj::getRotation() {
    return rot;
}

Dimension3<float>& GeomObj::getSize() {
    return size;
}

Color4<int>& GeomObj::getColor() {
    return col4;
}

std::vector<Face3>& GeomObj::getFaces() {
    return faces;
}

std::vector<Vertex>& GeomObj::getVertices() {
    return verts;
}

