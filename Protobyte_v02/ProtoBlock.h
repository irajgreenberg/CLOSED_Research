/*! \File:   ProtoBlock.h
 * Simple Hexahedron class   
 * ProtoBlock.h
 * Author: 33993405
 *
 * Created on April 6, 2013, 1:19 PM
 */

#ifndef ProtoBLOCK_H
#define	ProtoBLOCK_H

#include <iostream>
#include "ProtoGeom3.h"

namespace ijg {

    class ProtoBlock : public ProtoGeom3 {
    public:
        friend std::ostream& operator<<(std::ostream& out, const ProtoBlock& block);

        /*!
         * Default Constructor */
        ProtoBlock();
        /*!
         * Constructor */
        ProtoBlock(const Vec3f& pos, const Vec3f& rot, const ProtoDimension3<float>& size,
                const ProtoColor4<float>& col4);
        /*!
         * Constructor */
        ProtoBlock(const Vec3f& pos, const Vec3f& rot, const ProtoDimension3<float>& size,
                const ProtoColor4<float>& col4, float textureScale);

        /*!
         * Declared pure virtual in GeomBase base class
         * and must be implemented in all derived classes.
         * 
         * Generates all vertices.*/
        void calcVerts();
        
        
        /*!
         * Declared pure virtual in GeomBase base class
         * and must be implemented in all derived classes: 
         * 
         * Generates indices to group vertices to triangle faces.*/
        void calcInds();
      

    };
}

#endif	/* ProtoBLOCK_H */

