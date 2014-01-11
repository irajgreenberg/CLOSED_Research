/*!  \brief  ProtoFrenetFrame.h: Frenet frame class for parallel transport correction
 ProtoFrenetFrame.h
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

#ifndef PROTO_FRENET_FRAME_H
#define PROTO_FRENET_FRAME_H

//#ifdef  __APPLE__
//  #include <OpenGL/gl.h>
//#elif __linux
//  #include <GL/gl.h>
//#elif defined(_WIN32) || defined(_WIN64)
//  #include <GL/gl.h>
//#endif

#include "ProtoVector3.h"
#include <iostream>


namespace ijg {

    class ProtoFrenetFrame {
    private:
        Vec3f p, T, N, B;
        
    public:
        friend std::ostream& operator<<(std::ostream& out, const ProtoFrenetFrame& frame);
        ProtoFrenetFrame();
        ProtoFrenetFrame(const Vec3f& p, const Vec3f& T, const Vec3f& B, const Vec3f& N);
        ProtoFrenetFrame(const Vec3f TBN[3]);
        
        void init();
        Vec3f getT() const;
        Vec3f getN() const;
        Vec3f getB() const;
        
        void display(float len = 10);
        
    };
}

#endif // PROTO_FRENET_FRAME_H
