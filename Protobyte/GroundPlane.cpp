/* 
 * File:   GroundPlane.cpp
 * Author: 33993405
 * 
 * Created on April 9, 2013, 6:31 PM
 */

#include "GroundPlane.h"

namespace proto {

    std::ostream& operator<<(std::ostream& out, const GroundPlane& plane) {
        out << plane.columns << ", " << plane.rows;
    }
}


using namespace proto;

GroundPlane::GroundPlane() {
}

GroundPlane::GroundPlane(const Vector3& pos, const Vector3& rot, const Dimension3<float>& size,
        const Color4<float>& col4, int rows, int columns) :
GeomBase(pos, rot, size, col4), rows(rows), columns(columns) {
    init();
}

GroundPlane::GroundPlane(const Vector3& pos, const Vector3& rot, const Dimension3<float>& size,
        const Color4<float>& col4, int rows, int columns, const Texture2& tex2) :
GeomBase(pos, rot, size, col4, tex2), rows(rows), columns(columns) {
    init();
}

void GroundPlane::calcVerts() {
    float colSpan = 1.0 / columns;
    float rowSpan = 1.0 / rows;
    float x, z;
    int counter;
    verts.resize(columns * rows);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            x = -.5 + colSpan * j;
            z = -.5 + rowSpan * i;
            counter = i * columns + j;
            verts.at(counter) = Vertex(Vector3(x, 0, z), Color4<float>(col4.getR(), col4.getG(), col4.getB(), col4.getA()), Tuple2<float>(x + .5, z + .5));

        }
    }

    // extrude
    int pixelLen = tex2.getW() * tex2.getH();
    int rgbLen = pixelLen * 3;

    unsigned char* rgbData = new unsigned char[rgbLen];
    unsigned char* avgData = new unsigned char[pixelLen];
    glGetTexImage(GL_TEXTURE_2D, 0, GL_RGB, GL_UNSIGNED_BYTE, rgbData);
    // std::cout<<  "rgbLen = " << rgbLen << std::endl;

    // NOTE: + op automatically promotes char to int
    for (int i = 0, j = 0; i < pixelLen; ++i, j += 1) {
        avgData[i] = ((rgbData[j] + rgbData[j + 1] + rgbData[j + 2]) / 3);
    }

    for (int i = 0; i < verts.size(); ++i) {
        //verts.at(i).pos.y = avgData[i]*.2;
    }


    delete [] avgData;
    delete [] rgbData;
}

void GroundPlane::calcInds() {
    inds.resize((columns - 1) * (rows - 1) * 2);
    int counter;
    // temp face vars
    float a0, a1, a2, b0, b1, b2;
    for (int i = 0; i < rows - 1; ++i) {
        for (int j = 0; j < columns - 1; ++j) {

            a0 = i * columns + j;
            a1 = (i + 1) * columns + j;
            a2 = (i + 1) * columns + j + 1;

            b0 = i * columns + j;
            b1 = (i + 1) * columns + j + 1;
            b2 = i * columns + j + 1;

            inds.at(counter++) = Tuple3<int>(a0, a1, a2);
            inds.at(counter++) = Tuple3<int>(b0, b1, b2);
        }
    }
}



