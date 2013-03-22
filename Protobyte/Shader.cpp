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

    std::cout << "vsTextStr = " << vsTextStr << std::endl;
    std::cout << "fsTextStr = " << fsTextStr << std::endl;

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


    /*GLint status;
    glGetProgramiv(shader_vp, GL_ACTIVE_UNIFORMS, &status);
    if (status) {
        std::cout << "yes it compiled!" << std::endl;
    }

    //std::cout << status << std::endl;

    glGetProgramiv(shader_fp, GL_ACTIVE_UNIFORMS, &status);
    if (status) {
        std::cout << "yes it compiled!" << std::endl;
    }*/




    shader_id = glCreateProgram();

    glAttachShader(shader_id, shader_vp);
    glAttachShader(shader_id, shader_fp);

    glLinkProgram(shader_id);

    //glUseProgram(shader_id);
    
    // check linking 
    /*GLint linked;
    glGetProgramiv(shader_id, GL_LINK_STATUS, &linked);
    std::cout << "linked = " << linked << std::endl;
    if (linked) {
        std::cout << "Linking ok" << std::endl;
    }*/
    

    /*int loglen;
    char logbuffer[1000];
    glGetShaderInfoLog(shader_id, sizeof(logbuffer), &loglen, logbuffer);
    if (loglen > 0) {
        std::cout<< "logBuffer = " << logbuffer << std::endl;
    }*/
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