/*!  \brief  ProtoRenderer.cpp: Coordinates all rendering in ProtoUniverse
ProtoRenderer.cpp
Protobyte Library v02

Created by Ira on 7/25/13.
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
This class is part of the group common (update)
\sa NO LINK
*/


#include "ProtoRenderer.h"

using namespace ijg;


ProtoRenderer* ProtoRenderer::singletonRenderer = nullptr;
bool ProtoRenderer::singletonFlag = false;

// private default cstr to enforce singleton pattern
ProtoRenderer::ProtoRenderer(){
	init();
}

ProtoRenderer::~ProtoRenderer(){
	singletonFlag = false;
}

void ProtoRenderer::init(){
}


ProtoRenderer* ProtoRenderer::getInstance() {



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

	
	if (!ProtoRenderer::singletonFlag){
		ProtoRenderer::singletonRenderer =  new ProtoRenderer;
		ProtoRenderer::singletonFlag = true;
		return ProtoRenderer::singletonRenderer;
	} else {
		return ProtoRenderer::singletonRenderer;
	}
}

void ProtoRenderer::draw(const std::unique_ptr<ProtoGeom3>& geomObj, DisplayMode mode, RenderMode render, float pointSize) {

	glPushMatrix();
	glTranslatef(geomObj->getPosition().x, geomObj->getPosition().y, geomObj->getPosition().z);
	glRotatef(geomObj->getRotation().x, 1, 0, 0); // x-axis
	glRotatef(geomObj->getRotation().y, 0, 1, 0); // y-axis
	glRotatef(geomObj->getRotation().z, 0, 0, 1); // z-axis
	glScalef(geomObj->getSize().w, geomObj->getSize().h, geomObj->getSize().d);
	// std::cout << "geomObj->getSize() = " << geomObj->getSize() << std::endl;

	
	// make sure data is bound to buffer
	glBindBuffer(GL_ARRAY_BUFFER, geomObj->getVboID());
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, geomObj->getIndexVboID());

	// enable and specify pointers to vertex arrays
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	// stride is 12 : (x, y, z, nx, ny, nz, r, g, b, a, u, v)
	// vertices, normals, color
	glVertexPointer(3, GL_FLOAT, 12 * sizeof (GLfloat), BUFFER_OFFSET(0));
	glNormalPointer(GL_FLOAT, 12 * sizeof (GLfloat), BUFFER_OFFSET(12)); // step over 3 bytes
	glColorPointer(4, GL_FLOAT, 12 * sizeof (GLfloat), BUFFER_OFFSET(24)); // step over 6 bytes
	glTexCoordPointer(2, GL_FLOAT, 12 * sizeof (GLfloat), BUFFER_OFFSET(40)); // step over 10 bytes

	if (render == POINT_CLOUD) {
		glDrawElements(GL_POINTS, geomObj->getIndicesSize()*3, GL_UNSIGNED_INT, BUFFER_OFFSET(0));
	} else {
		glDrawElements(GL_TRIANGLES, geomObj->getIndicesSize()*3, GL_UNSIGNED_INT, BUFFER_OFFSET(0));
	}

	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);

	// free pointers to data
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glPopMatrix();


}