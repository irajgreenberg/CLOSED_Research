/*!  \brief  ProtoShader.cpp: class for managing shaders
ProtoShader.cpp
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


#include "ProtoShader.h"
#include <string.h>
#include <iostream>

using namespace ijg;

ProtoShader::ProtoShader() {
}

ProtoShader::ProtoShader(const char *vsFile, const char *fsFile) {
	init(vsFile, fsFile);
}

void ProtoShader::init(const char *vsFile, const char *fsFile) {

	// set uniform variables for shaders
	GLint loc1, loc2, loc3, loc4;
	float BrickColor[4] = {0.9, 0.3, 0.1, 1.0};
	float MortarColor[4] = {0.7, 0.7, 0.6, 1.0};
	float BrickSize[2] = {0.3, 0.15};
	float BrickPct[2] = {0.9, 0.85};


	// initialize glew for Windows
#if defined(_WIN32) || defined(__linux__)
	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		/* Problem: glewInit failed, something is seriously wrong. */
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
	}
	fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));
#endif

	shader_vp = glCreateShader(GL_VERTEX_SHADER);
	shader_fp = glCreateShader(GL_FRAGMENT_SHADER);

	std::string vText = ProtoUtility::load(vsFile);
	std::string fText = ProtoUtility::load(fsFile);

	const char* vsText = vText.c_str();
	const char* fsText = fText.c_str();
	std::cout << "vsText = " << vsText << std::endl;
	std::cout << "fsText = " << fsText << std::endl;

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

	//    std::cout << "loc1 = " << loc1 << std::endl;
	//    std::cout << "loc2 = " << loc2 << std::endl;
	//    std::cout << "loc3 = " << loc3 << std::endl;
	//    std::cout << "loc4 = " << loc4 << std::endl;
}

ProtoShader::~ProtoShader() {
	glDetachShader(shader_id, shader_fp);
	glDetachShader(shader_id, shader_vp);

	glDeleteShader(shader_fp);
	glDeleteShader(shader_vp);
	glDeleteProgram(shader_id);
}

unsigned int ProtoShader::id() {
	return shader_id;
}

void ProtoShader::bind() {
	glUseProgram(shader_id);
}

void ProtoShader::unbind() {
	glUseProgram(0);
}