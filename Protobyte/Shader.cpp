//
//  Shader.cpp
//  Protobyte Library V01
//
//  Created by Ira Greenberg on 8/2/11.
//  Copyright 2011 SMU. All rights reserved.
//

#include "Shader.h"
#include <string.h>
#include <iostream>

using namespace proto;

Shader::Shader() {
}

Shader::Shader(const char *vsFile, const char *fsFile) {
    init(vsFile, fsFile);
}

void Shader::init(const char *vsFile, const char *fsFile) {
    // bad code that should be changed (eventually!)
#ifdef  __linux__ 
    GLenum err = glewInit();
#elif defined _WIN32
    GLenum err = glewInit();
#endif
    
     // set uniform variables for shaders
    GLint loc1, loc2, loc3, loc4;
    float BrickColor[4] = {0.9, 0.3, 0.1, 1.0};
    float MortarColor[4] = {0.7, 0.7, 0.6, 1.0};
    float BrickSize[2] = {0.3, 0.15};
    float BrickPct[2] = {0.9, 0.85};

    
    
    


    shader_vp = glCreateShader(GL_VERTEX_SHADER);
    shader_fp = glCreateShader(GL_FRAGMENT_SHADER);

    std::string vText = Utility::getStringFromURL(vsFile);
    std::string fText = Utility::getStringFromURL(fsFile);

    const char* vsText = vText.c_str();
    const char* fsText = fText.c_str();


    if (vsText == NULL || fsText == NULL) {
        std::cerr << "Either vertex shader or fragment shader file not found." << std::endl;
        return;
    }

    glShaderSource(shader_vp, 1, &vsText, 0);
    glShaderSource(shader_fp, 1, &fsText, 0);

    glCompileShader(shader_vp);
    glCompileShader(shader_fp);

    shader_id = glCreateProgram();
    glAttachShader(shader_id, shader_vp);
    glAttachShader(shader_id, shader_fp);

    glLinkProgram(shader_id);
    
    
    
    // added for uniform shader
    loc1 = glGetUniformLocation(shader_id, "BrickColor");
    
    glUniform4fv(loc1, 1, BrickColor);

    loc2 = glGetUniformLocation(shader_id, "MortarColor");
    glUniform4fv(loc2, 1, MortarColor);

    loc3 = glGetUniformLocation(shader_id, "BrickSize");
    glUniform2fv(loc3, 1, BrickSize);

    loc4 = glGetUniformLocation(shader_id, "BrickPct");
    glUniform2fv(loc4, 1, BrickPct);
    
    std::cout << "loc1 = " << loc1 << std::endl;
    std::cout << "loc2 = " << loc2 << std::endl;
    std::cout << "loc3 = " << loc3 << std::endl;
    std::cout << "loc4 = " << loc4 << std::endl;
}

Shader::~Shader() {
    glDetachShader(shader_id, shader_fp);
    glDetachShader(shader_id, shader_vp);

    glDeleteShader(shader_fp);
    glDeleteShader(shader_vp);
    glDeleteProgram(shader_id);
}

unsigned int Shader::id() {
    return shader_id;
}

void Shader::bind() {
    glUseProgram(shader_id);
}

void Shader::unbind() {
    glUseProgram(0);
}