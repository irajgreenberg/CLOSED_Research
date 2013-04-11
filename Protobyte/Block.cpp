/* 
 * File:   Block.cpp
 * Author: 33993405
 * 
 * Created on April 6, 2013, 1:19 PM
 */

#include "Block.h"


namespace proto {

    
     std::ostream& operator<<(std::ostream& out, const Block& block) {
        out << "pos: " << block.pos << "\n" <<
                "rot: " << block.rot << "\n" <<
                "size: " << block.size << "\n" <<
                "col4: " << block.col4 << "\n" <<
                "tex2: " << block.tex2;
        return out;
    }
}

using namespace proto;

Block::Block() {
}

Block::Block(const Vector3& pos, const Vector3& rot, const Dimension3<float>& size,
        const Color4<float>& col4) :
GeomBase(pos, rot, size, col4) {
    init();
}

Block::Block(const Vector3& pos, const Vector3& rot, const Dimension3<float>& size,
        const Color4<float>& col4, const Texture2& tex2) :
GeomBase(pos, rot, size, col4, tex2) {
    init();
}

void Block::calcVerts() {
    verts.resize(8);
    verts.at(0) = Vertex(Vector3(-.5, .5, .5), Color4<float>(1.0, 0.5, 0.0, 1.0), Tuple2<float>(0, 1.0));
    verts.at(1) = Vertex(Vector3(-.5, -.5, .5), Color4<float>(1.0, 0.5, 0.0, 1.0), Tuple2<float>(0, 0));
    verts.at(2) = Vertex(Vector3(.5, -.5, .5), Color4<float>(1.0, 0.5, 0.0, 1.0), Tuple2<float>(1.0, 0));
    verts.at(3) = Vertex(Vector3(.5, .5, .5), Color4<float>(1.0, 0.5, 0.0, 1.0), Tuple2<float>(1.0, 1.0));
    verts.at(4) = Vertex(Vector3(.5, .5, -.5), Color4<float>(1.0, 0.5, 0.0, 1.0), Tuple2<float>(1.0, 1.0));
    verts.at(5) = Vertex(Vector3(.5, -.5, -.5), Color4<float>(1.0, 0.5, 0.0, 1.0), Tuple2<float>(1.0, 0));
    verts.at(6) = Vertex(Vector3(-.5, -.5, -.5), Color4<float>(1.0, 0.5, 0.0, 1.0), Tuple2<float>(0, 0));
    verts.at(7) = Vertex(Vector3(-.5, .5, -.5), Color4<float>(1.0, 0.5, 0.0, 1.0), Tuple2<float>(0, 1.0));

}

void Block::calcInds() {
    inds.resize(12);
    inds.at(0) = Tuple3<int>(0, 1, 2);
    inds.at(1) = Tuple3<int>(0, 2, 3);
    inds.at(2) = Tuple3<int>(0, 7, 6);
    inds.at(3) = Tuple3<int>(0, 6, 1);
    inds.at(4) = Tuple3<int>(3, 2, 5);
    inds.at(5) = Tuple3<int>(3, 5, 4);
    inds.at(6) = Tuple3<int>(4, 6, 7);
    inds.at(7) = Tuple3<int>(4, 5, 6);
    inds.at(8) = Tuple3<int>(3, 7, 0);
    inds.at(9) = Tuple3<int>(3, 4, 7);
    inds.at(10) = Tuple3<int>(1, 6, 5);
    inds.at(11) = Tuple3<int>(1, 5, 2);
}


