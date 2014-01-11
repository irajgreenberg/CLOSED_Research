/*!  \brief  ProtoMatrix4.h: 4D Matrix implementation
 ProtoMatrix4.h
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

#ifndef PROTO_MATRIX4_H
#define PROTO_MATRIX4_H

#include "ProtoVector3.h"

namespace ijg {

    // non member function
    void transpose(float mat4[16]);

    class ProtoMatrix4 {
    public:
        ProtoMatrix4();
        ProtoMatrix4(float mat4[16]);
        void transpose();
        void determinent();
        void mult(const ProtoMatrix4& m);
        ProtoVector3 mult(const ProtoVector3& vec);
        void add();
        void identity();

    private:
        float mat4[16];
    };

}

#endif // PROTO_MATRIX4_H
