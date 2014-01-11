/* 
 * File:   ProtoBlock.cpp
 * Author: 33993405
 * 
 * Created on April 6, 2013, 1:19 PM
 */

#include "ProtoBlock.h"


namespace ijg {

    std::ostream& operator<<(std::ostream& out, const ProtoBlock& ProtoBlock) {
        out << "pos: " << ProtoBlock.pos << "\n" <<
                "rot: " << ProtoBlock.rot << "\n" <<
                "size: " << ProtoBlock.size << "\n" <<
                "col4: " << ProtoBlock.col4;
        return out;
    }
}

using namespace ijg;

ProtoBlock::ProtoProtoBlock() {
}

ProtoBlock::ProtoBlock(const Vector3& pos, const Vector3& rot, const Dimension3<float>& size,
        const Color4<float>& col4) :
GeomBase(pos, rot, size, col4) {
    textureScale = 1.0;
    init();
}

ProtoBlock::ProtoBlock(const Vector3& pos, const Vector3& rot, const Dimension3<float>& size,
        const Color4<float>& col4, float textureScale) :
GeomBase(pos, rot, size, col4, textureScale) {
    init();
}

//Uses uuplicate vertices to allow proper texture mapping

void ProtoBlock::calcVerts() {

    Vector3 vs[8];
    vs[0] = Vector3(-.5, .5, .5);
    vs[1] = Vector3(-.5, -.5, .5);
    vs[2] = Vector3(.5, -.5, .5);
    vs[3] = Vector3(.5, .5, .5);
    vs[4] = Vector3(.5, .5, -.5);
    vs[5] = Vector3(.5, -.5, -.5);
    vs[6] = Vector3(-.5, -.5, -.5);
    vs[7] = Vector3(-.5, .5, -.5);


    verts.resize(36);
    // FRONT
    verts.at(0) = Vertex(vs[0], Color4<float>(1.0, 0.5, 0.0, 1.0), Tuple2<float>(0.0, 0.0));
    verts.at(1) = Vertex(vs[1], Color4<float>(1.0, 0.5, 0.0, 1.0), Tuple2<float>(0.0, 1.0 * textureScale));
    verts.at(2) = Vertex(vs[2], Color4<float>(1.0, 0.5, 0.0, 1.0), Tuple2<float>(1.0 * textureScale, 1.0 * textureScale));

    verts.at(3) = Vertex(vs[0], Color4<float>(1.0, 0.5, 0.0, 1.0), Tuple2<float>(0.0, 0.0));
    verts.at(4) = Vertex(vs[2], Color4<float>(1.0, 0.5, 0.0, 1.0), Tuple2<float>(1.0 * textureScale, 1.0 * textureScale));
    verts.at(5) = Vertex(vs[3], Color4<float>(1.0, 0.5, 0.0, 1.0), Tuple2<float>(1.0 * textureScale, 0.0));

    // RIGHT
    verts.at(6) = Vertex(vs[3], Color4<float>(1.0, 0.5, 0.0, 1.0), Tuple2<float>(0.0, 0.0));
    verts.at(7) = Vertex(vs[2], Color4<float>(1.0, 0.5, 0.0, 1.0), Tuple2<float>(0.0, 1.0 * textureScale));
    verts.at(8) = Vertex(vs[5], Color4<float>(1.0, 0.5, 0.0, 1.0), Tuple2<float>(1.0 * textureScale, 1.0 * textureScale));

    verts.at(9) = Vertex(vs[3], Color4<float>(1.0, 0.5, 0.0, 1.0), Tuple2<float>(0.0, 0.0));
    verts.at(10) = Vertex(vs[5], Color4<float>(1.0, 0.5, 0.0, 1.0), Tuple2<float>(1.0 * textureScale, 1.0 * textureScale));
    verts.at(11) = Vertex(vs[4], Color4<float>(1.0, 0.5, 0.0, 1.0), Tuple2<float>(1.0 * textureScale, 0.0));

    // BACK
    verts.at(12) = Vertex(vs[4], Color4<float>(1.0, 0.5, 0.0, 1.0), Tuple2<float>(0.0, 0.0));
    verts.at(13) = Vertex(vs[5], Color4<float>(1.0, 0.5, 0.0, 1.0), Tuple2<float>(0.0, 1.0 * textureScale));
    verts.at(14) = Vertex(vs[6], Color4<float>(1.0, 0.5, 0.0, 1.0), Tuple2<float>(1.0 * textureScale, 1.0 * textureScale));

    verts.at(15) = Vertex(vs[4], Color4<float>(1.0, 0.5, 0.0, 1.0), Tuple2<float>(0.0, 0.0));
    verts.at(16) = Vertex(vs[6], Color4<float>(1.0, 0.5, 0.0, 1.0), Tuple2<float>(1.0 * textureScale, 1.0 * textureScale));
    verts.at(17) = Vertex(vs[7], Color4<float>(1.0, 0.5, 0.0, 1.0), Tuple2<float>(1.0 * textureScale, 0.0));

    //LEFT
    verts.at(18) = Vertex(vs[7], Color4<float>(1.0, 0.5, 0.0, 1.0), Tuple2<float>(0.0, 0.0));
    verts.at(19) = Vertex(vs[6], Color4<float>(1.0, 0.5, 0.0, 1.0), Tuple2<float>(0.0, 1.0 * textureScale));
    verts.at(20) = Vertex(vs[1], Color4<float>(1.0, 0.5, 0.0, 1.0), Tuple2<float>(1.0 * textureScale, 1.0 * textureScale));

    verts.at(21) = Vertex(vs[7], Color4<float>(1.0, 0.5, 0.0, 1.0), Tuple2<float>(0.0, 0.0));
    verts.at(22) = Vertex(vs[1], Color4<float>(1.0, 0.5, 0.0, 1.0), Tuple2<float>(1.0 * textureScale, 1.0 * textureScale));
    verts.at(23) = Vertex(vs[0], Color4<float>(1.0, 0.5, 0.0, 1.0), Tuple2<float>(1.0 * textureScale, 0.0));

    // TOP 
    verts.at(24) = Vertex(vs[7], Color4<float>(1.0, 0.5, 0.0, 1.0), Tuple2<float>(0.0, 0.0));
    verts.at(25) = Vertex(vs[0], Color4<float>(1.0, 0.5, 0.0, 1.0), Tuple2<float>(0.0, 1.0 * textureScale));
    verts.at(26) = Vertex(vs[3], Color4<float>(1.0, 0.5, 0.0, 1.0), Tuple2<float>(1.0 * textureScale, 1.0 * textureScale));

    verts.at(27) = Vertex(vs[7], Color4<float>(1.0, 0.5, 0.0, 1.0), Tuple2<float>(0.0, 0.0));
    verts.at(28) = Vertex(vs[3], Color4<float>(1.0, 0.5, 0.0, 1.0), Tuple2<float>(1.0 * textureScale, 1.0 * textureScale));
    verts.at(29) = Vertex(vs[4], Color4<float>(1.0, 0.5, 0.0, 1.0), Tuple2<float>(1.0 * textureScale, 0.0));

    //BOTTOM
    verts.at(30) = Vertex(vs[1], Color4<float>(1.0, 0.5, 0.0, 1.0), Tuple2<float>(0.0, 0.0));
    verts.at(31) = Vertex(vs[6], Color4<float>(1.0, 0.5, 0.0, 1.0), Tuple2<float>(0.0, 1.0 * textureScale));
    verts.at(32) = Vertex(vs[5], Color4<float>(1.0, 0.5, 0.0, 1.0), Tuple2<float>(1.0 * textureScale, 1.0 * textureScale));

    verts.at(33) = Vertex(vs[1], Color4<float>(1.0, 0.5, 0.0, 1.0), Tuple2<float>(0.0, 0.0));
    verts.at(34) = Vertex(vs[5], Color4<float>(1.0, 0.5, 0.0, 1.0), Tuple2<float>(1.0 * textureScale, 1.0 * textureScale));
    verts.at(35) = Vertex(vs[2], Color4<float>(1.0, 0.5, 0.0, 1.0), Tuple2<float>(1.0 * textureScale, 0.0));
}

void ProtoBlock::calcInds() {
    inds.resize(12);
    for (int i = 0, j = 0; i < inds.size(); i++, j += 3) {
        inds.at(i) = Tuple3<int>(j, j + 1, j + 2);
    }
}


