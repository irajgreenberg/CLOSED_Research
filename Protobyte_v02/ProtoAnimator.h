/*!  \brief  ProtoAnimator.h: Singletoon class coordinates all motion within ProtoUniverse
 ProtoAnimator.h
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

#ifndef Protobyte_v02_ProtoAnimator_cpp
#define Protobyte_v02_ProtoAnimator_cpp

#include <iostream>

namespace ijg {
    
    class ProtoAnimator {
    
        
    private:
        // field for singleton instance
        static ProtoAnimator* singletonAnimator;
        
        // private default cstr to enforce singleton pattern
        ProtoAnimator(){
        }
        
        // disallow overriding copy cstr
        ProtoAnimator(const ProtoAnimator& animator);

    
    public:
        
        // dstr
        ~ProtoAnimator();
        
        // only returns a single instance
        static ProtoAnimator* getInstance();
        
        // overloaded assignment op
        ProtoAnimator& operator=(const ProtoAnimator& animator);
        
        
        void start();
        
        void stop();

           
    };
}

#endif // Protobyte_v02_ProtoAnimator_cpp
