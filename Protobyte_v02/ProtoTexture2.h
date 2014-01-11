/*!  \brief  ProtoTexture2.h: 2D texture class with w,h fields
 ProtoTexture2.h
 Protobyte Library v02
 
 Created by Ira on 7/23/13.
 Copyright (c) 2013 Ira Greenberg. All rights reserved.
 
 Library Usage:
 This work is licensed under the Creative Commons
 Attribution-NonCommercial-ShareAlike 3.0 Unported License.
 To view a copy of this license, visit
 http://creativecommons.org/licenses/by-nc-sa/3.0/
 or send a letter to Creative Commons,
 444 Castro Street, Suite 900,
 Mountain View, California, 94041, USA.
 
 This notice must be retained any source distribution.
 
 \ingroup common
 This class is templated to allow for varied single collection types
 This class is part of the group common (update)
 \sa NO LINK
 */

#ifndef TEXTURE2_H
#define	TEXTURE2_H



#ifdef _WIN32
#include <GL/glew.h>
#endif

#include<SFML/OpenGL.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h> // for File input

namespace ijg {

    class ProtoTexture2 {
    public:

        friend std::ostream& operator<<(std::ostream& output, const ProtoTexture2& texture2);

        ProtoTexture2();
        ProtoTexture2(const std::string& textureURL, GLuint w, GLuint h, bool isWrap);
        ProtoTexture2(unsigned char*& data, GLuint w, GLuint h, bool isWrap);
        ProtoTexture2(std::vector<unsigned char>& data, GLuint w, GLuint h, bool isWrap);
        ProtoTexture2(const int* packedData32, GLuint w, GLuint h, bool isWrap);

        // getters/setters
        void setH(GLuint h);
        GLuint getH() const;
        void setW(GLuint w);
        GLuint getW() const;
        void setTextureURL(std::string textureURL);
        std::string getTextureURL() const;
        void setTextureID(GLuint textureID);
        GLuint getTextureID() const;




    private:
        std::string textureURL;
        GLuint w;
        GLuint h;
        bool isWrap;
        GLuint textureID;

        void init();
    };

    inline void ProtoTexture2::setH(GLuint h) {
        this->h = h;
    }

    inline GLuint ProtoTexture2::getH() const {
        return h;
    }

    inline void ProtoTexture2::setW(GLuint w) {
        this->w = w;
    }

    inline GLuint ProtoTexture2::getW() const {
        return w;
    }

    inline void ProtoTexture2::setTextureURL(std::string textureURL) {
        this->textureURL = textureURL;
    }

    inline std::string ProtoTexture2::getTextureURL() const {
        return textureURL;
    }

    inline void ProtoTexture2::setTextureID(GLuint textureID) {
        this->textureID = textureID;
    }

    inline GLuint ProtoTexture2::getTextureID() const {
        return textureID;
    }

}

#endif	// TEXTURE2_H 

