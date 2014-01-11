/*!  \brief  ProtoGraphicsCore.h: Abstact Base Graphics class
 ProtoGraphicsCore.h
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

#ifndef PROTO_GRAPHICSCORE_H
#define	PROTO_GRAPHICSCORE_H

#ifdef  __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#elif __linux
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>
#define GL_GLEXT_PROTOTYPES
#include <GL/glext.h>
#elif _WIN32
#include <GL/gl.h>
#include <GL/glu.h>
#define GL_GLEXT_PROTOTYPES
#include <GL/glext.h>
#elif _WIN64
#include <GL/gl.h>
#include <GL/glu.h>
#define GL_GLEXT_PROTOTYPES
#include <GL/glext.h>
#endif

#include <iostream>
#include <algorithm>  
#include <vector>
#include "ProtoMath.h"
#include "ProtoVector3.h"
#include "ProtoDimension3.h"
#include "ProtoColor4.h"

namespace ijg {

    class ProtoGraphicsCore {
    public:
        /*!
         * Default Constructor */
        ProtoGraphicsCore();

        /*!
         * Constructor */
        ProtoGraphicsCore(const ProtoVector3& pos, const ProtoVector3& rot, const ProtoDimension3f& size,
                const ProtoColor4f& col4);
        
        /*!
         * Constructor */
        ProtoGraphicsCore(const ProtoVector3& pos, const ProtoVector3& rot, const ProtoDimension3f& size,
                const std::vector< ProtoColor4f >& col4s);

        virtual ~ProtoGraphicsCore();

        // setters
        virtual void setPosition(const ProtoVector3& pos);
        virtual void setRotation(const ProtoVector3& rot);
        virtual void setSize(const ProtoDimension3f& size);
        virtual void setColor(const ProtoColor4f& col4);
        virtual void setRotSpd(const ProtoVector3& rotSpd);
        virtual void setSpd(const ProtoVector3& spd);

        // getters
        virtual ProtoVector3 getPosition() const;
        virtual ProtoVector3 getRotation() const;
        virtual ProtoDimension3f getSize() const;
        virtual ProtoColor4f getColor() const;
        virtual ProtoVector3 getRotSpd() const;
        virtual ProtoVector3 getSpd() const;

    protected:
        ProtoVector3 pos, rot;
        ProtoDimension3f size;
        ProtoColor4f col4;
        std::vector< ProtoColor4f > col4s;
        ProtoVector3 spd, rotSpd;


    private:
        // nothing  here yet

    };

    // setters

    inline void ProtoGraphicsCore::setPosition(const ProtoVector3& pos) {
        this->pos = pos;
    }

    inline void ProtoGraphicsCore::setRotation(const ProtoVector3& rot) {
        this->rot = rot;
    }

    inline void ProtoGraphicsCore::setSize(const ProtoDimension3f& size) {
        this->size = size;
    }

    inline void ProtoGraphicsCore::setColor(const ProtoColor4f& col4) {
        this->col4 = col4;
    }

    inline void ProtoGraphicsCore::setRotSpd(const ProtoVector3& rotSpd) {
        this->rotSpd = rotSpd;
    }

    inline void ProtoGraphicsCore::setSpd(const ProtoVector3& spd) {
        this->spd = spd;
    }

    // getters

    inline ProtoVector3 ProtoGraphicsCore::getPosition() const {
        return pos;
    }

    inline ProtoVector3 ProtoGraphicsCore::getRotation() const {
        return rot;
    }

    inline ProtoDimension3f ProtoGraphicsCore::getSize() const {
        return size;
    }

    inline ProtoColor4f ProtoGraphicsCore::getColor() const {
        return col4;
    }

    inline ProtoVector3 ProtoGraphicsCore::getRotSpd() const {
        return rotSpd;
    }

    inline ProtoVector3 ProtoGraphicsCore::getSpd() const {
        return spd;
    }

}

#endif	/* PROTO_GRAPHICSCORE_H */

