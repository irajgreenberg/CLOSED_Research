/* 
 * File:   Block.h
 * Author: 33993405
 *
 * Created on April 6, 2013, 1:19 PM
 */

#ifndef BLOCK_H
#define	BLOCK_H

#include <iostream>
#include "GeomBase.h"

namespace proto {

    class Block : public GeomBase {
    public:
        friend std::ostream& operator<<(std::ostream& out, const Block& block);

        Block();
        Block(const Vector3& pos, const Vector3& rot, const Dimension3<float>& size,
                const Color4<float>& col4);
        Block(const Vector3& pos, const Vector3& rot, const Dimension3<float>& size,
                const Color4<float>& col4, const Texture2& tex2);

        void calcVerts();
        void calcInds();

    };
}

#endif	/* BLOCK_H */

