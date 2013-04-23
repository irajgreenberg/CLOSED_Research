/* 
 * File:   GroundPlane.h
 * Author: 33993405
 *
 * Created on April 9, 2013, 6:31 PM
 */

#ifndef GROUNDPLANE_H
#define	GROUNDPLANE_H

#include "GeomBase.h"

namespace proto {

    class GroundPlane : public GeomBase {
    public:
        friend std::ostream& operator<<(std::ostream& out, const GroundPlane& plane);

        GroundPlane();
        
        GroundPlane(const Vector3& pos, const Vector3& rot, const Dimension3f& size,
                const Color4f& col4, int rows, int columns);
        
        GroundPlane(const Vector3& pos, const Vector3& rot, const Dimension3f& size,
                const Color4f& col4, int rows, int columns, float textureScale);
         
        GroundPlane(const Vector3& pos, const Vector3& rot, const Dimension3f& size,
                const Color4f& col4, int rows, int columns, const Texture2& bumpMap);
        
        GroundPlane(const Vector3& pos, const Vector3& rot, const Dimension3f& size,
                const Color4f& col4, int rows, int columns, const Texture2& bumpMap, float textureScale);

        void calcVerts();
        void calcInds();

        void setRows(int rows);
        int getRows() const;
        void setColumns(int columns);
        int getColumns() const;

    private:
        int columns, rows;

    };

    inline void GroundPlane::setRows(int rows) {
        this->rows = rows;
    }

    inline int GroundPlane::getRows() const {
        return rows;
    }

    inline void GroundPlane::setColumns(int columns) {
        this->columns = columns;
    }

    inline int GroundPlane::getColumns() const {
        return columns;
    }
}

#endif	/* GROUNDPLANE_H */

