/*!  \brief  ProtoQuaternion.h: quaternion implementation
 ProtoQuaternion.h
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

#ifndef PROTO_QUATERNION_h
#define PROTO_QUATERNION_h

#include "ProtoVector3.h"

namespace ijg {
    class ProtoQuaternion {
       

    public:
        // fields
        float x, y, z, w;
        
        // constructor
        ProtoQuaternion(const ProtoVector3& axis = ProtoVector3(0, 0, 1), float theta = 0);
        ProtoQuaternion(float x, float y, float z, float w);
        //void rotate(ProtoVector3 v);
        ProtoVector3 getRotate(const ProtoVector3& v); // return
        void rotate(ProtoVector3& v); // update in place
        float mag() const;
        void normalize();
        
        friend ProtoQuaternion& operator*(const ProtoQuaternion& q); // need to implement
        void operator*=(const ProtoQuaternion& q); // need to implement
        
        void setAxis(const ProtoVector3& axis);
        const ProtoVector3& getAxis() const;
        
    private:
        ProtoVector3 axis;
        float theta;

    };
    
}

#endif // PROTO_QUATERNION_h
