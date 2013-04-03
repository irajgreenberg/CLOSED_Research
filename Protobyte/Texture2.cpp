/* 
 * File:   Texture2.cpp
 * Author: ira
 * 
 * Created on April 2, 2013, 9:34 AM
 */

#include "Texture2.h"

std::ostream& operator<<(std::ostream& output, const Texture2& texture2)
{
    output << "texture2.texturePath: "<< texture2.texturePath <<
            ", texture2.w: " << texture2.w <<
            ", texture2.h: " << texture2.h << 
            ", texture2.textureID: " << texture2.textureID;
    return output;
}

Texture2::Texture2() {
    texturePath="";
    w=0;
    h=0;
}

Texture2::Texture2(std::string texturePath, GLuint w, GLuint h):
texturePath(texturePath), w(w), h(h) {
}

