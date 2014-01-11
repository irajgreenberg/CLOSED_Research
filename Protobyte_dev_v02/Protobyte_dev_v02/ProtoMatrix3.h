/*!  \brief  ProtoMatrix3.h: 3D Matrix implementation
 ProtoMatrix3.h
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


#ifndef PROTO_MATRIX3_H
#define	PROTO_MATRIX3_H

#include "ProtoVector3.h"


namespace ijg {

    template <class T>
    class ProtoMatrix3 {
    public:
        ProtoMatrix3();
        ProtoMatrix3(float mat3[9]);
        void rotate(float theta, const Vec3f& axis, Vec3f& v);
        Vec3f getRotate(float theta, const Vec3f& axis, const Vec3f& vec);
        void transpose();
        void determinent();
        void mult(const ProtoMatrix3& m);
        Vec3f mult(const Vec3f& vec);
        void add();
        void identity();

    private:
        float mat3[9];

    };
}

#endif	// PROTO_MATRIX3_H 

