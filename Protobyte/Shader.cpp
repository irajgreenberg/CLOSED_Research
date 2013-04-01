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

static char* textFileRead(const char *fileName) {


    char* text;

    if (fileName != NULL) {

        FILE *file = fopen(fileName, "rt");
        std::cout << "file = " << file << std::endl;

        if (file != NULL) {
            fseek(file, 0, SEEK_END);
            int count = (int) ftell(file);
            rewind(file);

            if (count > 0) {
                text = (char*) malloc(sizeof (char) * (count + 1));
                count = (int) fread(text, sizeof (char), count, file);
                text[count] = '\0';
            }
            fclose(file);
        }
    }
    return text;
}

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


    shader_vp = glCreateShader(GL_VERTEX_SHADER);
    shader_fp = glCreateShader(GL_FRAGMENT_SHADER);

    const char* vsText = textFileRead(vsFile);
    const char* fsText = textFileRead(fsFile);


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