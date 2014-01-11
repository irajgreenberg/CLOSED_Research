/*! \File:   BlockGrid.h
 * Hexahedron composed of Planes class   
 * BlockGrid.h
 * Author: Ira Greenberg
 *
 * Created on April 6, 2013, 1:19 PM
 */

#ifndef BLOCK_GRID_H
#define	BLOCK_GRID_H

#ifdef  __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#elif __linux
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>
#define GL_GLEXT_PROTOTYPES
#include <GL/glext.h>
#elif _WIN32
#include <GL/gl.h>
#include <GL/glu.h>
#define GL_GLEXT_PROTOTYPES
#include <GL/glext.h>
#elif _WIN64
#include <GL/gl.h>
#include <GL/glu.h>
#define GL_GLEXT_PROTOTYPES
#include <GL/glext.h>
#endif

#include <iostream>
#include "GeomBase.h"
#include "GroundPlane.h"

namespace proto {

    class BlockGrid {
    private:
        int rows, columns;
        std::vector<Texture2> textures;
        std::vector<float> textureScales;
        std::vector<GroundPlane> planes;

    public:
        friend std::ostream& operator<<(std::ostream& out, const BlockGrid& blockGrid);

        /*!
         * Default Constructor */
        BlockGrid();

        /*!
         * Constructor */
        BlockGrid(const Vector3& pos, const Vector3& rot, const Dimension3f& size,
                const Color4<float>& col4, const Texture2& tex2, int rows, int columns);

        /*!
         * Constructor */
        BlockGrid(const Vector3& pos, const Vector3& rot, const Dimension3f& size,
                const Color4<float>& col4, const Texture2& tex2, float textureScale, int rows, int columns);

        /*!
         * Constructor */
        BlockGrid(const Vector3& pos, const Vector3& rot, const Dimension3f& size,
                const Color4<float>& col4, const std::vector<Texture2>& textures, float textureScale, int rows, int columns);

        /*!
         * Constructor */
        BlockGrid(const Vector3& pos, const Vector3& rot, const Dimension3f& size,
                const Color4<float>& col4, const Texture2& tex2, std::vector<float>& textureScales, int rows, int columns);

        /*!
         * Constructor */
        BlockGrid(const Vector3& pos, const Vector3& rot, const Dimension3f& size,
                const Color4<float>& col4, const std::vector<Texture2>& textures, std::vector<float> textureScales, int rows, int columns);


        /*!
         * Delegates calls to display() on composed GroundPlanes */
        void display(GeomBase::displayMode mode, GeomBase::renderMode render);

        /*!
         * Accessor and mutator prototypes*/
        void setColumns(int columns);
        int getColumns() const;
        void setRows(int rows);
        int getRows() const;
        void setTextureScales(std::vector<float> textureScales);
        std::vector<float> getTextureScales() const;
        void setTextures(const std::vector<Texture2>& textures);
        const std::vector<Texture2>& getTextures() const;
        void setPlanes(std::vector<GroundPlane> planes);
        std::vector<GroundPlane> getPlanes() const;
    };

    /*!
     * inline accessors and mutators */
    inline void BlockGrid::setColumns(int columns) {
        this->columns = columns;
    }

    inline int BlockGrid::getColumns() const {
        return columns;
    }

    inline void BlockGrid::setRows(int rows) {
        this->rows = rows;
    }

    inline int BlockGrid::getRows() const {
        return rows;
    }

    inline void BlockGrid::setTextureScales(std::vector<float> textureScales) {
        this->textureScales = textureScales;
    }

    inline std::vector<float> BlockGrid::getTextureScales() const {
        return textureScales;
    }

    inline void BlockGrid::setTextures(const std::vector<Texture2>& textures) {
        this->textures = textures;
    }

    inline const std::vector<Texture2>& BlockGrid::getTextures() const {
        return textures;
    }

    inline void BlockGrid::setPlanes(std::vector<GroundPlane> planes) {
        this->planes = planes;
    }

    inline std::vector<GroundPlane> BlockGrid::getPlanes() const {
        return planes;
    }

}

#endif	/* BLOCK_GRID_H */

