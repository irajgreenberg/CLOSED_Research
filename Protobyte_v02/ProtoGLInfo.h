/*!  \brief  ProtoGLInfo.h: Utility structs and functions to output GL related info
 ProtoGLInfo.h
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
 This class is part of the group common (update)
 \sa NO LINK
 */

#ifndef GLINFO_H
#define GLINFO_H

#ifdef  __APPLE__
  #include <OpenGL/gl.h>
#elif __linux__
  #include <GL/gl.h>
#elif _WIN32
  #include <GL/gl.h>
#else
#error "unknown platform"
#endif

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <cstring>

using std::string;
using std::stringstream;
using std::vector;
using std::cout;
using std::endl;


// struct variable to store OpenGL info
struct ProtoGLInfo
{
    std::string vendor;
    std::string renderer;
    std::string version;
    std::vector <std::string> extensions;
    int redBits;
    int greenBits;
    int blueBits;
    int alphaBits;
    int depthBits;
    int stencilBits;
    int maxTextureSize;
    int maxLights;
    int maxAttribStacks;
    int maxModelViewStacks;
    int maxProjectionStacks;
    int maxClipPlanes;
    int maxTextureStacks;

    // ctor, init all members
ProtoGLInfo() : redBits(0), greenBits(0), blueBits(0), alphaBits(0), depthBits(0),
        stencilBits(0), maxTextureSize(0), maxLights(0), maxAttribStacks(0),
        maxModelViewStacks(0), maxClipPlanes(0), maxTextureStacks(0) {}

///////////////////////////////////////////////////////////////////////////////
// extract openGL info
// This function must be called after GL rendering context opened.
///////////////////////////////////////////////////////////////////////////////
    bool getInfo()
        {
            char* str = 0;
            char* tok = 0;

            // get vendor string
            str = (char*)glGetString(GL_VENDOR);
            if(str) this->vendor = str;                  // check NULL return value
            else return false;

            // get renderer string
            str = (char*)glGetString(GL_RENDERER);
            if(str) this->renderer = str;                // check NULL return value
            else return false;

            // get version string
            str = (char*)glGetString(GL_VERSION);
            if(str) this->version = str;                 // check NULL return value
            else return false;

            // get all extensions as a string
            str = (char*)glGetString(GL_EXTENSIONS);

            // split extensions
            if(str)
            {
                tok = strtok((char*)str, " ");
                while(tok)
                {
                    this->extensions.push_back(tok);    // put a extension into struct
                    tok = strtok(0, " ");               // next token
                }
            }
            else
            {
                return false;
            }

            // sort extension by alphabetical order
            std::sort(this->extensions.begin(), this->extensions.end());

            // get number of color bits
            glGetIntegerv(GL_RED_BITS, &this->redBits);
            glGetIntegerv(GL_GREEN_BITS, &this->greenBits);
            glGetIntegerv(GL_BLUE_BITS, &this->blueBits);
            glGetIntegerv(GL_ALPHA_BITS, &this->alphaBits);

            // get depth bits
            glGetIntegerv(GL_DEPTH_BITS, &this->depthBits);

            // get stecil bits
            glGetIntegerv(GL_STENCIL_BITS, &this->stencilBits);

            // get max number of lights allowed
            glGetIntegerv(GL_MAX_LIGHTS, &this->maxLights);

            // get max texture resolution
            glGetIntegerv(GL_MAX_TEXTURE_SIZE, &this->maxTextureSize);

            // get max number of clipping planes
            glGetIntegerv(GL_MAX_CLIP_PLANES, &this->maxClipPlanes);

            // get max modelview and projection matrix stacks
            glGetIntegerv(GL_MAX_MODELVIEW_STACK_DEPTH, &this->maxModelViewStacks);
            glGetIntegerv(GL_MAX_PROJECTION_STACK_DEPTH, &this->maxProjectionStacks);
            glGetIntegerv(GL_MAX_ATTRIB_STACK_DEPTH, &this->maxAttribStacks);

            // get max texture stacks
            glGetIntegerv(GL_MAX_TEXTURE_STACK_DEPTH, &this->maxTextureStacks);

            return true;
        }



///////////////////////////////////////////////////////////////////////////////
// check if the video card support a certain extension
///////////////////////////////////////////////////////////////////////////////
    bool isExtensionSupported(const char* ext)
        {
            // search corresponding extension
            std::vector< string >::const_iterator iter = this->extensions.begin();
            std::vector< string >::const_iterator endIter = this->extensions.end();

            while(iter != endIter)
            {
                if(ext == *iter)
                    return true;
                else
                    ++iter;
            }
            return false;
        }



///////////////////////////////////////////////////////////////////////////////
// print OpenGL info to screen and save to a file
///////////////////////////////////////////////////////////////////////////////
    void printSelf()
        {
            stringstream ss;

            ss << endl; // blank line
            ss << "OpenGL Driver Info" << endl;
            ss << "==================" << endl;
            ss << "Vendor: " << this->vendor << endl;
            ss << "Version: " << this->version << endl;
            ss << "Renderer: " << this->renderer << endl;

            ss << endl;
            ss << "Color Bits(R,G,B,A): (" << this->redBits << ", " << this->greenBits
               << ", " << this->blueBits << ", " << this->alphaBits << ")\n";
            ss << "Depth Bits: " << this->depthBits << endl;
            ss << "Stencil Bits: " << this->stencilBits << endl;

            ss << endl;
            ss << "Max Texture Size: " << this->maxTextureSize << "x" << this->maxTextureSize << endl;
            ss << "Max Lights: " << this->maxLights << endl;
            ss << "Max Clip Planes: " << this->maxClipPlanes << endl;
            ss << "Max Modelview Matrix Stacks: " << this->maxModelViewStacks << endl;
            ss << "Max Projection Matrix Stacks: " << this->maxProjectionStacks << endl;
            ss << "Max Attribute Stacks: " << this->maxAttribStacks << endl;
            ss << "Max Texture Stacks: " << this->maxTextureStacks << endl;

            ss << endl;
            ss << "Total Number of Extensions: " << this->extensions.size() << endl;
            ss << "==============================" << endl;
            for(unsigned int i = 0; i < this->extensions.size(); ++i)
                ss << this->extensions.at(i) << endl;

            ss << "======================================================================" << endl;

            cout << ss.str() << endl;
        }
};

#endif // ProtoGLInfo.h