/* 
 * File:   Texture2.h
 * Author: ira
 *
 * Created on April 2, 2013, 9:34 AM
 */

#ifndef TEXTURE2_H
#define	TEXTURE2_H



#ifdef  __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#elif __linux
#include <GL/gl.h>
#include <GL/glu.h>
#elif defined(_WIN32) || defined(_WIN64)
#include <GL/gl.h>
#include <GL/glu.h>
#endif

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h> // for File input

namespace proto {

    class Texture2 {
    public:

        friend std::ostream& operator<<(std::ostream& output, const Texture2& texture2);

        Texture2();
        Texture2(const std::string& textureURL, GLuint w, GLuint h, bool isWrap);
        Texture2(unsigned char*& data, GLuint w, GLuint h, bool isWrap);
        Texture2(std::vector<unsigned char>& data, GLuint w, GLuint h, bool isWrap);
        Texture2(const int* packedData32, GLuint w, GLuint h, bool isWrap);

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

    inline void Texture2::setH(GLuint h) {
        this->h = h;
    }

    inline GLuint Texture2::getH() const {
        return h;
    }

    inline void Texture2::setW(GLuint w) {
        this->w = w;
    }

    inline GLuint Texture2::getW() const {
        return w;
    }

    inline void Texture2::setTextureURL(std::string textureURL) {
        this->textureURL = textureURL;
    }

    inline std::string Texture2::getTextureURL() const {
        return textureURL;
    }

    inline void Texture2::setTextureID(GLuint textureID) {
        this->textureID = textureID;
    }

    inline GLuint Texture2::getTextureID() const {
        return textureID;
    }

}

#endif	/* TEXTURE2_H */

