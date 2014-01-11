/*!  \brief  ProtoGroundPlane.cpp: Simple plane
 ProtoGroundPlane.cpp
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

#include "ProtoGroundPlane.h"
#include "ProtoMath.h"

namespace ijg {

    std::ostream& operator<<(std::ostream& out, const ProtoGroundPlane& plane) {
        out << plane.columns << ", " << plane.rows;
    }
}


using namespace ijg;

ProtoGroundPlane::ProtoGroundPlane() {
}

ProtoGroundPlane::ProtoGroundPlane(const ProtoVector3& pos, const ProtoVector3& rot, const ProtoDimension3<float>& size,
        const ProtoColor4<float>& col4, int rows, int columns) :
ProtoGeomBase(pos, rot, size, col4), rows(rows), columns(columns) {
    init();
}

ProtoGroundPlane::ProtoGroundPlane(const ProtoVector3& pos, const ProtoVector3& rot, const ProtoDimension3<float>& size,
        const ProtoColor4<float>& col4, int rows, int columns, float textureScale) :
ProtoGeomBase(pos, rot, size, col4, textureScale), rows(rows), columns(columns) {
    init();
}

ProtoGroundPlane::ProtoGroundPlane(const ProtoVector3& pos, const ProtoVector3& rot, const ProtoDimension3<float>& size,
        const ProtoColor4<float>& col4, int rows, int columns, const ProtoTexture2& bumpMap) :
ProtoGeomBase(pos, rot, size, col4), rows(rows), columns(columns) {
    this->bumpMap = bumpMap;
    init();
}

ProtoGroundPlane::ProtoGroundPlane(const ProtoVector3& pos, const ProtoVector3& rot, const ProtoDimension3<float>& size,
        const ProtoColor4<float>& col4, int rows, int columns, const ProtoTexture2& bumpMap, float textureScale) :
ProtoGeomBase(pos, rot, size, col4, textureScale), rows(rows), columns(columns) {
    this->bumpMap = bumpMap;
    init();
}

void ProtoGroundPlane::calcVerts() {
    std::cout << "textureScale = " << textureScale << std::endl;
    float colSpan = 1.0 / (columns - 1);
    float rowSpan = 1.0 / (rows - 1);
    float x = 0, y = 0, z = 0;
    int counter = 0;
    verts.resize(columns * rows);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            x = -.5 + colSpan * j;
            z = -.5 + rowSpan * i;

            if (i > 0 && i < rows - 1 && j != 0 && j < columns - 1) {
                //y = proto::ProtoMath::random(.7);
                y = abs(sin((i*columns+j)*M_PI/180.0)*.8)+abs(cos((j*rows+i)*M_PI/180.0)*03)+ProtoMath::random(-.8, .8);
            } else {
                y = 0;
            }
            counter = i * columns + j;
            verts.at(counter) = ProtoVertex(ProtoVector3(x, y, z), ProtoColor4<float>(col4.getR(), col4.getG(), col4.getB(), col4.getA()),
                    ProtoTuple2<float>((x + .5) * textureScale, (z + .5) * textureScale));

        }
    }
    // std::cout << "ProtoGroundPlane.cpp:  verts.size() = " << verts.size() << std::endl;


    // extrude
    /* if (bumpMap.getW() > 0 && bumpMap.getH() > 0) {
         std::cout << "bumpMap = " << bumpMap << std::endl;

         int pixelLen = bumpMap.getW() * bumpMap.getH();
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
             verts.at(i).pos.y = avgData[i]*.2;
         }


         delete [] avgData;
         delete [] rgbData;
     }*/
}

void ProtoGroundPlane::calcInds() {
    inds.resize((columns - 1) * (rows - 1) * 2);
    int counter = 0;
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

            inds.at(counter++) = ProtoTuple3<int>(a0, a1, a2);
            inds.at(counter++) = ProtoTuple3<int>(b0, b1, b2);
        }
    }
}



