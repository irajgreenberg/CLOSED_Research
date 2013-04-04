/* 
 * File:   Texture2.h
 * Author: ira
 *
 * Created on April 2, 2013, 9:34 AM
 */

#ifndef TEXTURE2_H
#define	TEXTURE2_H



# ifdef  __APPLE__
      #include <OpenGL/gl.h>
      #include <OpenGL/glu.h>
#elif __linux__
        #include <GL/gl.h>
        #include <GL/glu.h>
#elif _WIN32
        #include <GL/gl.h>
        #include <GL/glu.h>
#else
        #error "unknown platform"
# endif

#include <iostream>
#include <string>
#include <stdio.h> // for File input

class Texture2 {
    
public:
    
    friend std::ostream& operator<<(std::ostream& output, const Texture2& texture2);
    
    Texture2();
    Texture2(const std::string& textureURL, GLuint w, GLuint h, bool isWrap);

    // getters/setters
    void SetH(GLuint h);
    GLuint GetH() const;
    void SetW(GLuint w);
    GLuint GetW() const;
    void SetTextureURL(std::string textureURL);
    std::string GetTextureURL() const;
    void SetTextureID(GLuint textureID);
    GLuint GetTextureID() const;


private:
    std::string textureURL;
    GLuint w;
    GLuint h;
    GLuint textureID;
    bool isWrap;
    
    void init();
};

inline void Texture2::SetH(GLuint h) {
    this->h = h;
}

inline GLuint Texture2::GetH() const {
    return h;
}

inline void Texture2::SetW(GLuint w) {
    this->w = w;
}

inline GLuint Texture2::GetW() const {
    return w;
}

inline void Texture2::SetTextureURL(std::string textureURL) {
    this->textureURL = textureURL;
}

inline std::string Texture2::GetTextureURL() const {
    return textureURL;
}

inline void Texture2::SetTextureID(GLuint textureID) {
    this->textureID = textureID;
}

inline GLuint Texture2::GetTextureID() const {
    return textureID;
}

#endif	/* TEXTURE2_H */

