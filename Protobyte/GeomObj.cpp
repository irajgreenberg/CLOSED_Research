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

