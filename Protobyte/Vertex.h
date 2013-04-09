/* 
 * File:   Vertex.h
 * Author: 33993405
 *
 * Created on February 27, 2013, 5:54 PM
 */

#ifndef VERTEX_H
#define	VERTEX_H

#include "Vector3.h"
#include "Color4.h"
#include "Tuple2.h"

namespace proto {

    class Vertex {
    public:
        friend std::ostream& operator<<(std::ostream& output, const Vertex& vertex);

        Vertex();
        Vertex(const Vector3& pos);
        Vertex(const Vector3& pos, const Color4<float>& col4);
        Vertex(const Vector3& pos, const Color4<float>& col4, const Tuple2<float>& uv);

        Vector3 pos;

        const Vector3& getNormal() const;
        Color4<float> getColor() const;
        Tuple2<float> getUV() const;

        void setNormal(const Vector3& norm);
        void setColor(const Color4<float>& col4);
        void setUV(const Tuple2<float>& uv);

    private:
        Color4<float> col4;
        Vector3 norm;
        Tuple2<float> uv;

        void init();
    };
    
    // inline getters/setters

    inline const Vector3& Vertex::getNormal() const {
        return norm;
    }

    inline void Vertex::setNormal(const Vector3& norm) {
        this->norm = norm;
    }

    inline Color4<float> Vertex::getColor() const {
        return col4;
    }

    inline void Vertex::setColor(const Color4<float>& col4) {
        this->col4 = col4;
    }
    
    inline Tuple2<float> Vertex::getUV() const {
        return uv;
    }
    
    inline void Vertex::setUV(const Tuple2<float>& uv){
        this->uv = uv;
    }


}
#endif	/* VERTEX_H */

