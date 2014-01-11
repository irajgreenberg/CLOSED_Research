/*!  \brief  ProtoBounds.h: (add brief description)
 ProtoBounds.h
 Protobyte Library v02
 
 Created by Ira on 8/16/13.
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

#ifndef PROTO_BOUNDS_H
#define PROTO_BOUNDS_H

#include <iostream>

namespace ijg {
    
    template<class T>
    class ProtoBounds {
        
    public:
        template <typename U>
        friend std::ostream& operator<<(std::ostream& out, const ProtoBounds<U>& bounds);
        
        ProtoBounds();
        ProtoBounds(T x, T y, T w, T h);
        ProtoBounds(T xywh[4]);
        virtual ~ProtoBounds() {}
        
        T x;
        T y;
        T w;
        T h;
        
    private:
        
    };
    
    template<typename T>
    std::ostream& operator<<(std::ostream& out, const ProtoBounds<T>& bounds){
        out << bounds.x << ", " << bounds.y << ", " << bounds.w << ", " << bounds.h;
        return out;
    }
    
    template<typename T>
        inline ProtoBounds<T>::ProtoBounds():
    x(static_cast<T>(0.0)), y(static_cast<T>(0.0)), w(static_cast<T>(1.0)), h(static_cast<T>(1.0)){
        
    }
                                            
    template<typename T>
        inline ProtoBounds<T>::ProtoBounds(T x, T y, T w, T h):
    x(x), y(y), w(w), h(h){
        
    }
    
    template<typename T>
        inline ProtoBounds<T>::ProtoBounds(T xywh[4]):
        x(xywh[0]), y(xywh[1]), w(xywh[2]), h(xywh[3]) {
    }
        
    // Type name convenience macros
    #define ProtoBoundsi ProtoBounds<integer>
    #define ProtoBoundsf ProtoBounds<float>
    #define ProtoBoundsd ProtoBounds<double>
}

#endif // PROTO_BOUNDS_H
