/* 
 * File:   BlockGrid.cpp
 * Author: Ira Greenberg
 * 
 * Created on April 20, 2013, 2:35 PM
 */

#include "BlockGrid.h"

using namespace proto;

BlockGrid::BlockGrid() {

}

BlockGrid::BlockGrid(const Vector3& pos, const Vector3& rot, const Dimension3f& size,
        const Color4<float>& col4, const Texture2& tex2, int rows, int columns) :
rows(rows), columns(columns) {
    planes.resize(6);
    //GroundPlane p(pos + Vector3(0, 0, size.d / 2), rot + Vector3(90, 0, 0), Dimension3f(size.w, 1, size.d), col4, rows, columns);
    //front
    planes.at(0) = GroundPlane(pos + Vector3(0, 0, size.d / 2), rot + Vector3(90, 0, 0), Dimension3f(size.w, 1, size.d), col4, rows, columns);
    //right
    planes.at(1) = GroundPlane(pos + Vector3(size.w / 2, 0, 0), rot + Vector3(0, 0, -90), Dimension3f(size.w, 1, size.d), col4, rows, columns);
    //back
    planes.at(2) = GroundPlane(pos + Vector3(0, 0, -size.d / 2), rot + Vector3(-90, 0, 0), Dimension3f(size.w, 1, size.d), col4, rows, columns);
    //left
    planes.at(3) = GroundPlane(pos + Vector3(-size.w / 2, 0, 0), rot + Vector3(0, 0, 90), Dimension3f(size.w, 1, size.d), col4, rows, columns);
    // top
    planes.at(4) = GroundPlane(pos + Vector3(0, size.h / 2, 0), rot + Vector3(0, 0, 0), Dimension3f(size.w, 1, size.d), col4, rows, columns);
    // bottom
    planes.at(5) = GroundPlane(pos + Vector3(0, -size.h / 2, 0), rot + Vector3(0, 0, 180), Dimension3f(size.w, 1, size.d), col4, rows, columns);


}

BlockGrid::BlockGrid(const Vector3& pos, const Vector3& rot, const Dimension3f& size,
        const Color4<float>& col4, const Texture2& tex2, float textureScale, int rows, int columns) :
rows(rows), columns(columns) {
    //
    textures.push_back(tex2);
    textureScales.push_back(textureScale);
    planes.resize(6);

    //front
    planes.at(0) = GroundPlane(pos + Vector3(0, 0, size.d / 2), rot + Vector3(90, 0, 0), Dimension3f(size.w, 1, size.d), col4, rows, columns, textureScale);
    //right
    planes.at(1) = GroundPlane(pos + Vector3(size.w / 2, 0, 0), rot + Vector3(0, 0, -90), Dimension3f(size.w, 1, size.d), col4, rows, columns, textureScale);
    //back
    planes.at(2) = GroundPlane(pos + Vector3(0, 0, -size.d / 2), rot + Vector3(-90, 0, 0), Dimension3f(size.w, 1, size.d), col4, rows, columns, textureScale);
    //left
    planes.at(3) = GroundPlane(pos + Vector3(-size.w / 2, 0, 0), rot + Vector3(0, 0, 90), Dimension3f(size.w, 1, size.d), col4, rows, columns, textureScale);
    // top
    planes.at(4) = GroundPlane(pos + Vector3(0, size.h / 2, 0), rot + Vector3(0, 0, 0), Dimension3f(size.w, 1, size.d), col4, rows, columns, textureScale);
    // bottom
    planes.at(5) = GroundPlane(pos + Vector3(0, -size.h / 2, 0), rot + Vector3(0, 0, 180), Dimension3f(size.w, 1, size.d), col4, rows, columns, textureScale);


}

BlockGrid::BlockGrid(const Vector3& pos, const Vector3& rot, const Dimension3f& size,
        const Color4<float>& col4, const std::vector<Texture2>& textures, float textureScale, int rows, int columns) :
rows(rows), columns(columns), textures(textures) {

    textureScales.push_back(textureScale);
    planes.resize(6);
    //GroundPlane p(pos + Vector3(0, 0, size.d / 2), rot + Vector3(90, 0, 0), Dimension3f(size.w, 1, size.d), col4, rows, columns);
    //front
    planes.at(0) = GroundPlane(pos + Vector3(0, 0, size.d / 2), rot + Vector3(90, 0, 0), Dimension3f(size.w, 1, size.d), col4, rows, columns, textureScale);
    //right
    planes.at(1) = GroundPlane(pos + Vector3(size.w / 2, 0, 0), rot + Vector3(0, 0, -90), Dimension3f(size.w, 1, size.d), col4, rows, columns, textureScale);
    //back
    planes.at(2) = GroundPlane(pos + Vector3(0, 0, -size.d / 2), rot + Vector3(-90, 0, 0), Dimension3f(size.w, 1, size.d), col4, rows, columns, textureScale);
    //left
    planes.at(3) = GroundPlane(pos + Vector3(-size.w / 2, 0, 0), rot + Vector3(0, 0, 90), Dimension3f(size.w, 1, size.d), col4, rows, columns, textureScale);
    // top
    planes.at(4) = GroundPlane(pos + Vector3(0, size.h / 2, 0), rot + Vector3(0, 0, 0), Dimension3f(size.w, 1, size.d), col4, rows, columns, textureScale);
    // bottom
    planes.at(5) = GroundPlane(pos + Vector3(0, -size.h / 2, 0), rot + Vector3(0, 0, 180), Dimension3f(size.w, 1, size.d), col4, rows, columns, textureScale);


}

BlockGrid::BlockGrid(const Vector3& pos, const Vector3& rot, const Dimension3f& size,
        const Color4<float>& col4, const Texture2& tex2, std::vector<float>& textureScales, int rows, int columns) :

textureScales(textureScales), rows(rows), columns(columns) {
    textures.push_back(tex2);
    planes.resize(6);
    //front
    planes.at(0) = GroundPlane(pos + Vector3(0, 0, size.d / 2), rot + Vector3(90, 0, 0), Dimension3f(size.w, 1, size.d), col4, rows, columns, textureScales.at(0));
    //right
    planes.at(1) = GroundPlane(pos + Vector3(size.w / 2, 0, 0), rot + Vector3(0, 0, -90), Dimension3f(size.w, 1, size.d), col4, rows, columns, textureScales.at(1));
    //back
    planes.at(2) = GroundPlane(pos + Vector3(0, 0, -size.d / 2), rot + Vector3(-90, 0, 0), Dimension3f(size.w, 1, size.d), col4, rows, columns, textureScales.at(2));
    //left
    planes.at(3) = GroundPlane(pos + Vector3(-size.w / 2, 0, 0), rot + Vector3(0, 0, 90), Dimension3f(size.w, 1, size.d), col4, rows, columns, textureScales.at(3));
    // top
    planes.at(4) = GroundPlane(pos + Vector3(0, size.h / 2, 0), rot + Vector3(0, 0, 0), Dimension3f(size.w, 1, size.d), col4, rows, columns, textureScales.at(4));
    // bottom
    planes.at(5) = GroundPlane(pos + Vector3(0, -size.h / 2, 0), rot + Vector3(0, 0, 180), Dimension3f(size.w, 1, size.d), col4, rows, columns, textureScales.at(5));


}

BlockGrid::BlockGrid(const Vector3& pos, const Vector3& rot, const Dimension3f& size,
        const Color4<float>& col4, const std::vector<Texture2>& textures, std::vector<float> textureScales, int rows, int columns) :
textures(textures), textureScales(textureScales), rows(rows), columns(columns) {
    planes.resize(6);
    //front
    planes.at(0) = GroundPlane(pos + Vector3(0, 0, size.d / 2), rot + Vector3(90, 0, 0), Dimension3f(size.w, 1, size.d), col4, rows, columns, textureScales.at(0));
    //right
    planes.at(1) = GroundPlane(pos + Vector3(size.w / 2, 0, 0), rot + Vector3(0, 0, -90), Dimension3f(size.w, 1, size.d), col4, rows, columns, textureScales.at(1));
    //back
    planes.at(2) = GroundPlane(pos + Vector3(0, 0, -size.d / 2), rot + Vector3(-90, 0, 0), Dimension3f(size.w, 1, size.d), col4, rows, columns, textureScales.at(2));
    //left
    planes.at(3) = GroundPlane(pos + Vector3(-size.w / 2, 0, 0), rot + Vector3(0, 0, 90), Dimension3f(size.w, 1, size.d), col4, rows, columns, textureScales.at(3));
    // top
    planes.at(4) = GroundPlane(pos + Vector3(0, size.h / 2, 0), rot + Vector3(0, 0, 0), Dimension3f(size.w, 1, size.d), col4, rows, columns, textureScales.at(4));
    // bottom
    planes.at(5) = GroundPlane(pos + Vector3(0, -size.h / 2, 0), rot + Vector3(0, 0, 180), Dimension3f(size.w, 1, size.d), col4, rows, columns, textureScales.at(5));

}

void BlockGrid::display(GeomBase::displayMode mode, GeomBase::renderMode render) {
    //std::cout << "planes.size() = " << planes.size() << std::endl;
    for (int i = 0; i < planes.size(); ++i) {
        if (textures.size() > 1) {
            glBindTexture(GL_TEXTURE_2D, textures.at(i).getTextureID());
        } else {
            glBindTexture(GL_TEXTURE_2D, textures.at(0).getTextureID());
        }
        planes.at(i).display(mode, render);
    }
}
