/*!  \brief  ProtoShader.h: class for managing shaders
 ProtoShader.h
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

#ifndef PROTO_SHADER_H
#define PROTO_SHADER_H

#if defined(_WIN32) || defined(__linux__)
#include <GL/glew.h>
#endif

#include <stdlib.h>
#include <string>
#include "ProtoUtility.h"


namespace ijg {

    class ProtoShader {
    public:
        ProtoShader();
        ProtoShader(const char *vsFile, const char *fsFile);
        ~ProtoShader();

        void init(const char *vsFile, const char *fsFile);

        void bind();
        void unbind();

        unsigned int id();
        unsigned int shader_id;
    private:
        //unsigned int shader_id;
        unsigned int shader_vp;
        unsigned int shader_fp;

    };

}


#endif //PROTO_SHADER_H
