/* 
 * File:   Texture2.cpp
 * Author: ira
 * 
 * Created on April 2, 2013, 9:34 AM
 */

#include "Texture2.h"



namespace proto {

    std::ostream& operator<<(std::ostream& output, const Texture2& texture2) {
        output << "texture2.textureURL: " << texture2.textureURL <<
                ", texture2.w: " << texture2.w <<
                ", texture2.h: " << texture2.h <<
                ", texture2.textureID: " << texture2.textureID;
        return output;
    }

}

using namespace proto;

Texture2::Texture2() {
    textureURL = "";
    w = 0;
    h = 0;
}

Texture2::Texture2(const std::string& textureURL, GLuint w, GLuint h, bool isWrap) :
textureURL(textureURL), w(w), h(h), isWrap(isWrap) {

    init();
}

void Texture2::init() {
    // texture creation/loading code from: 
    // http://www.nullterminator.net/gltexture.html

    unsigned char* data;
    FILE * file;

    // allocate buffer
    data = new unsigned char[w * h * 3];

    // open texture data
    file = fopen(textureURL.c_str(), "rb");
    if (file == NULL) std::cout << "no file data";

    // read texture data
    fread(data, w * h * 3, 1, file);
    fclose(file);
    //Now that we have loaded our texture data from the RAW file, we can call the GLU(OpenGL Utility) function gluBuild2DMipmaps.

    // allocate a texture name
    glGenTextures(1, &textureID);

    // select our current texture
    glBindTexture(GL_TEXTURE_2D, textureID);

    // select modulate to mix texture with color for shading
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

    // when texture area is small, bilinear filter the closest MIP map
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
            GL_LINEAR_MIPMAP_NEAREST);
    // when texture area is large, bilinear filter the first MIP map
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // if wrap is true, the texture wraps over at the edges (repeat)
    //       ... false, the texture ends at the edges (clamp)
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,
            isWrap ? GL_REPEAT : GL_CLAMP);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,
            isWrap ? GL_REPEAT : GL_CLAMP);

    // give opengl the texture
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_BGR, GL_UNSIGNED_BYTE, data);

    // build our texture mipmaps
    /* gluBuild2DMipmaps(GL_TEXTURE_2D, 3, w, h,
             GL_RGB, GL_UNSIGNED_BYTE, data);*/

    // free memory
    delete [] data;
}



