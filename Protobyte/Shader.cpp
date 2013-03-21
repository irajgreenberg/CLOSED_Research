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


    glShaderSource(shader_vp, 1, (const GLchar**) &vsTextStr, 0);
    glShaderSource(shader_fp, 1, (const GLchar**) &fsTextStr, 0);

    glCompileShader(shader_vp);
    glCompileShader(shader_fp);


    // evnetually check if compilation worked
    /*GLint compiled;
    glGetObjectParameteriv(shader_vp, GL_COMPILE_STATUS, &compiled);
    if (compiled) {
       std::cout << "yes it compiled!" << std::endl;
    }*/



    shader_id = glCreateProgram();

    glAttachShader(shader_id, shader_vp);
    glAttachShader(shader_id, shader_fp);

    glLinkProgram(shader_id);

    // check linking 
    GLint linked;
    glGetProgramiv(shader_id, GL_LINK_STATUS, &linked);
    if (linked) {
        std::cout << "Llinking ok" << std::endl;
    }
}

Shader::~Shader() {
    glDetachShader(shader_id, shader_fp);
    glDetachShader(shader_id, shader_vp);

    glDeleteShader(shader_fp);
    glDeleteShader(shader_vp);
    glDeleteProgram(shader_id);

}

unsigned int Shader::getID() {
    return shader_id;
}

void Shader::bind() {
    glUseProgram(shader_id);
}

void Shader::unbind() {
    glUseProgram(0);
}