
#include "Vertex.h"

namespace proto {

    std::ostream& operator<<(std::ostream& output, const Vertex& vertex) {
        output << "vertex.pos: " << vertex.pos << ", vertex.col4: " <<
                vertex.col4 << ", vertex.norm: " << vertex.norm;
        return output;
    }

}

using namespace proto;

Vertex::Vertex() {
    pos = Vector3(0, 0, 0);
    col4 = Color4<float>(1, 1, 1, 1);
    uv = Tuple2<float>(0,0);
}

Vertex::Vertex(const Vector3& pos, const Color4<float>& col4) :
pos(pos), col4(col4) {
    uv = Tuple2<float>(0,0);
}

Vertex::Vertex(const Vector3& pos, const Color4<float>& col4, const Tuple2<float>& uv) :
pos(pos), col4(col4), uv(uv) {
}

Vertex::Vertex(const Vector3& pos) :
pos(pos) {
    col4 = Color4<float>(1, 1, 1, 1);
    uv = Tuple2<float>(0,0);
}

