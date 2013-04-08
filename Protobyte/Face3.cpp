//
//  Face3.cpp
//  SFML_simple_renderer_05
//
//  Created by Ira on 2/9/13.
//  Copyright (c) 2013 Ira Greenberg. All rights reserved.
//

#include "Face3.h"


namespace proto {
    // overloaded << operator for outputting field values in objects

    std::ostream& operator<<(std::ostream& output, const Face3& face3) {
        output << "[ V0: " << *(face3.v0_p) << ", " << *(face3.v1_p) << ", " << *(face3.v2_p) << " ]";
        return output;
    }
}

using namespace proto;

Face3::Face3(Vertex* v0_p, Vertex* v1_p, Vertex* v2_p) {
    // get vertex addresses
    this->v0_p = v0_p;
    this->v1_p = v1_p;
    this->v2_p = v2_p;

    init();
}

void Face3::init() {
    // initialize centroid and normal
    calcCentroid();
    calcNorm();
}

void Face3::display() {
    // flat shading
    /*glBegin(GL_TRIANGLES);
    glColor3f(.2, .3, 1.0); // for face normals
    glNormal3f(norm.x, norm.y, norm.z);
    glVertex3f(v0_p->pos.x, v0_p->pos.y, v0_p->pos.z);
    glColor3f(.2, .3, 1.0);
    //glNormal3f(v1_p->getNormal().x, v1_p->getNormal().y, v1_p->getNormal().z);
    glVertex3f(v1_p->pos.x, v1_p->pos.y, v1_p->pos.z);
    glColor3f(.2, .3, 1.0);
    //glNormal3f(v2_p->getNormal().x, v2_p->getNormal().y, v2_p->getNormal().z);
    glVertex3f(v2_p->pos.x, v2_p->pos.y, v2_p->pos.z);
    glEnd();*/


    // smooth shading
    glBegin(GL_TRIANGLES);
    glColor3f(.2, .3, 1.0); // for face normals
    glNormal3f(v0_p->getNormal().x, v0_p->getNormal().y, v0_p->getNormal().z);
    glVertex3f(v0_p->pos.x, v0_p->pos.y, v0_p->pos.z);
    glColor3f(.2, .3, 1.0);
    glNormal3f(v1_p->getNormal().x, v1_p->getNormal().y, v1_p->getNormal().z);
    glVertex3f(v1_p->pos.x, v1_p->pos.y, v1_p->pos.z);
    glColor3f(.2, .3, 1.0);
    glNormal3f(v2_p->getNormal().x, v2_p->getNormal().y, v2_p->getNormal().z);
    glVertex3f(v2_p->pos.x, v2_p->pos.y, v2_p->pos.z);
    glEnd();
}

void Face3::calcCentroid() {
    //std::cout << "centroid before = " << centroid << std::endl;
    centroid += v0_p->pos;
    centroid += v1_p->pos;
    centroid += v2_p->pos;
    centroid /= 3;
    //std::cout << "centroid after = " << centroid << std::endl;
}

void Face3::calcNorm() {
    Vector3 v0 = v1_p->pos - v0_p->pos;
    Vector3 v1 = v2_p->pos - v0_p->pos;
    norm = v0.cross(v1); // maybe reverse
    norm.normalize();
}

const Vector3& Face3::getNorm() const {
    return norm;
}

const Vector3& Face3::getCentroid() const {
    return centroid;
}

const Vertex* Face3::operator[](int index) {
    switch (index) {
        case 0:
            return v0_p;
            break;
        case 1:
            return v1_p;
            break;
        case 2:
            return v2_p;
            break;
    }
}


