//
//  Shader.cpp
//  Protobyte Library V01
//
//  Created by Ira Greenberg on 8/2/11.
//  Copyright 2011 SMU. All rights reserved.
//

#include "shader.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

std::string Shader::fileRead(const char* fileName) {


    std::ifstream in(fileName);
    std::string contents((std::istreambuf_iterator<char>(in)),
            std::istreambuf_iterator<char>());

    return contents;

}

Shader::Shader() {

}

Shader::Shader(const char *vsFile, const char *fsFile) {
    init(vsFile, fsFile);
}

void Shader::init(const char *vsFile, const char *fsFile) {
    shader_vp = glCreateShader(GL_VERTEX_SHADER);
    shader_fp = glCreateShader(GL_FRAGMENT_SHADER);

    //const char *c_str = data.c_str();

    std::string vsTextStr = fileRead(vsFile);
    std::string fsTextStr = fileRead(fsFile);

    //std::cout << "fileRead(vsFile) is" << fileRead(vsFile) << std::endl;
    //std::cout << "fsTextStr is" << fsTextStr.c_str() << std::endl;

    // convert sring to char*
   /* const GLchar* vsText = new char[vsTextStr.size() + 1];
    vsText[vsTextStr.size()] = 0;
    memcpy(vsText, vsTextStr.c_str(), vsTextStr.size());

    const GLchar* fsText = new char[fsTextStr.size() + 1];
    fsText[fsTextStr.size()] = 0;
    memcpy(fsText, fsTextStr.c_str(), fsTextStr.size());*/


    //const char* vsText = vsTextStr.c_str();
    //const char* fsText = fsTextStr.c_str();

    //std::cout << "fsText address is" << &fsText << std::endl;
    //std::cout << "fsText is" << fsText << std::endl;

    //std::cout << "vsText address is" << &vsText << std::endl;
    //std::cout << "vsText is" << vsText << std::endl;


    /*if (vsText == NULL || fsText == NULL) {
        std::cerr << "Either vertex shader or fragment shader file not found." << std::endl;
        return;
    }*/

    glShaderSource(shader_vp, 1, (const GLchar**)&vsTextStr, 0);
    glShaderSource(shader_fp, 1, (const GLchar**)&fsTextStr, 0);

    glCompileShader(shader_vp);
    glCompileShader(shader_fp);

    shader_id = glCreateProgram();
    glAttachShader(shader_id, shader_fp);
    glAttachShader(shader_id, shader_vp);
    glLinkProgram(shader_id);
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